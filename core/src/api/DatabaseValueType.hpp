// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from database.djinni

#ifndef DJINNI_GENERATED_DATABASEVALUETYPE_HPP
#define DJINNI_GENERATED_DATABASEVALUETYPE_HPP

#include <functional>
#include <iostream>
#include <string>

namespace ledger { namespace core { namespace api {

enum class DatabaseValueType : int {
    STRING,
    DATE,
    DOUBLE,
    INTEGER,
    LONG_LONG,
    UNSIGNED_LONG_LONG,
};
std::string to_string(const DatabaseValueType& databaseValueType);
std::ostream &operator<<(std::ostream &os, const DatabaseValueType &o);

} } }  // namespace ledger::core::api

namespace std {

template <>
struct hash<::ledger::core::api::DatabaseValueType> {
    size_t operator()(::ledger::core::api::DatabaseValueType type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
#endif //DJINNI_GENERATED_DATABASEVALUETYPE_HPP
