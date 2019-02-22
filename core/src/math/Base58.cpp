/*
 *
 * Base58
 * ledger-core
 *
 * Created by Pierre Pollastri on 12/12/2016.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
#include "Base58.hpp"
#include "BigInt.h"
#include <sstream>
#include "../collections/vector.hpp"
#include <crypto/HashAlgorithm.h>
#include <utils/hex.h>
#include <functional>
#include <crypto/Keccak.h>

static const std::string DIGITS = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
static const std::string RIPPLE_DIGITS = "rpshnaf39wBUDNEGHJKLM4PQRST7VWXYZ2bcdeCg65jkm8oFqi1tuvAxyz";
static const ledger::core::BigInt V_58(58);

static std::string getBase58Dictionary(const std::string &networkIdentifier) {
    if (networkIdentifier == "xrp") {
        return RIPPLE_DIGITS;
    }
    return DIGITS;
}
static void _encode(const ledger::core::BigInt &v,
                    std::stringstream &ss,
                    const std::string &networkIdentifier) {
    if (v == ledger::core::BigInt::ZERO) {
        return ;
    }
    auto r = (v % V_58).toUnsignedInt();
    _encode(v / V_58, ss, networkIdentifier);
    ss << getBase58Dictionary(networkIdentifier)[r];
}

std::string ledger::core::Base58::encode(const std::vector<uint8_t> &bytes,
                                         const std::string &networkIdentifier) {
    BigInt intData(bytes.data(), bytes.size(), false);
    std::stringstream ss;

    for (auto i = 0; i < bytes.size() && bytes[i] == 0; i++) {
        ss << getBase58Dictionary(networkIdentifier)[0];
    }
    _encode(intData, ss, networkIdentifier);
    return ss.str();
}

std::string ledger::core::Base58::encodeWithChecksum(const std::vector<uint8_t> &bytes,
                                                     const std::string &networkIdentifier) {
    return encode(vector::concat<uint8_t>(bytes, computeChecksum(bytes, networkIdentifier)), networkIdentifier);
}

std::string ledger::core::Base58::encodeWithEIP55(const std::vector<uint8_t> &bytes) {
    auto byteToDigitEIP55 = [](uint8_t byte, uint8_t against) -> char {
        bool uppercase = against >= 0x8;
        byte = (uint8_t) (0xF < byte ? 0xF : byte);
        if (byte < 0xA) {
            return '0' + byte;
        } else if (uppercase) {
            return (char)('A' + (byte - 0xA));
        } else {
            return (char)('a' + (byte - 0xA));
        }
    };

    auto keccakHash = Keccak::keccak256(hex::toString(bytes));

    std::string addressEIP55(bytes.size() * 2, '0');
    for (int i = 0; i < bytes.size(); i++) {
        addressEIP55[i * 2] = byteToDigitEIP55(bytes[i] >> 4, keccakHash[i] >> 4);
        addressEIP55[i * 2 + 1] = byteToDigitEIP55((uint8_t) (bytes[i] & 0xF), (uint8_t) (keccakHash[i] & 0xF));
    }
    return "0x" + addressEIP55;
}

std::string ledger::core::Base58::encodeWithEIP55(const std::string &address) {
    if (address.size() == 42) {
        //Address with 0x prefix
        return Base58::encodeWithEIP55(hex::toByteArray(address.substr(2, address.size() - 2)));
    } else if (address.size() == 40) {
        return Base58::encodeWithEIP55(hex::toByteArray(address));
    }
    throw Exception(api::ErrorCode::INVALID_BASE58_FORMAT, "Invalid base 58 format");
}

std::vector<uint8_t> ledger::core::Base58::decode(const std::string &str,
                                                  const std::string &networkIdentifier) throw(ledger::core::Exception) {
    BigInt intData(0);
    std::vector<uint8_t> prefix;

    for (auto& c : str) {
        if (c == '1' && intData == BigInt::ZERO) {
            prefix.push_back(0);
        } else {
            auto digitIndex = getBase58Dictionary(networkIdentifier).find(c);
            if (digitIndex != std::string::npos) {
                intData = (intData * V_58) + BigInt((unsigned int)digitIndex);
            } else {
                throw Exception(api::ErrorCode::INVALID_BASE58_FORMAT, "Invalid base 58 format");
            }
        }
    }

    //For XRP, hash160 is preceeded by a null byte prefix
    if (prefix.empty() && networkIdentifier == "xrp") {
        prefix.push_back(0);
    }

    return vector::concat(prefix, intData.toByteArray());
}

std::vector<uint8_t> ledger::core::Base58::computeChecksum(const std::vector<uint8_t> &bytes,
                                                           const std::string &networkIdentifier) {
    ledger::core::HashAlgorithm hashAlgorithm(networkIdentifier);
    auto hash = hashAlgorithm.bytesToBytesHash(bytes);
    auto doubleHash = hashAlgorithm.bytesToBytesHash(hash);
    return std::vector<uint8_t>(doubleHash.begin(), doubleHash.begin() + 4);
}

ledger::core::Try<std::vector<uint8_t>> ledger::core::Base58::checkAndDecode(const std::string &str,
                                                                             const std::string &networkIdentifier,
                                                                             bool useNetworkDictionary) {
    return Try<std::vector<uint8_t>>::from([&] () {
        auto decoded = useNetworkDictionary ? decode(str, networkIdentifier) : decode(str);
        //Check decoded address size
        if (decoded.size() <= 4) {
            throw Exception(api::ErrorCode::INVALID_BASE58_FORMAT, "Invalid address : Invalid base 58 format");
        }
        std::vector<uint8_t> data(decoded.begin(), decoded.end() - 4);
        std::vector<uint8_t> checksum(decoded.end() - 4, decoded.end());
        auto chks = computeChecksum(data, networkIdentifier);
        if (checksum != chks) {
            throw Exception(api::ErrorCode::INVALID_CHECKSUM, "Base 58 invalid checksum");
        }
        return data;
    });
}