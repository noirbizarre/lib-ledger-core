#include "BTGXPubFixtures.hpp"

namespace ledger {
	namespace testing {
		namespace btg_xpub {

			core::api::ExtendedKeyAccountCreationInfo XPUB_INFO(
			        0, {"btg"}, {"49'/1'/0'"}, {"xpub6C25jbLoXJoeKy4LFGvwaZRXcKg8FXc17zgaDN2cShJGeBcf8RySNQntLuHbFMnyoxdsVBiEcoij7sp3MLUkD3tRSKQ48BLNEsmrZng8EMf"}
			);

			std::shared_ptr<core::BitcoinLikeAccount> inflate(const std::shared_ptr<core::Services>& services, const std::shared_ptr<core::AbstractWallet>& wallet) {
				auto account = std::dynamic_pointer_cast<core::BitcoinLikeAccount>(wait(wallet->newAccountWithExtendedKeyInfo(XPUB_INFO)));
				soci::session sql(services->getDatabaseSessionPool()->getPool());
				
				sql.begin();				
				account->putTransaction(sql, *core::JSONUtils::parse<core::BitcoinLikeTransactionParser>(TX_1));
				account->putTransaction(sql, *core::JSONUtils::parse<core::BitcoinLikeTransactionParser>(TX_2));
				sql.commit();
				
				return account;
			}
			
			const std::string TX_1 = "{\"inputs\": [{\"value\": 10000000, \"output_index\": 0, \"output_hash\": \"424ffc81334d91f58c3d6f485936f51c9de2fb56ede4d17143129bb5e656c055\", \"input_index\": 0, \"address\": \"ATqSa4V9ZjxPxDBe877bbXeKMfZA644mBk\", \"txinwitness\": [\"3045022100d12c69f31d876c40bb74ab7d0944e3804033e070cfdde61e04315c114c3e4164022028fea19f1a43c15a77f812588d3c7aab84e002173ed8d00387f6f7b0228916b541\", \"0313ca3dc8d6fb865c582e09d4699426356edc824e7bd8276ae611cd4ffe21332c\"], \"script_signature\": \"160014319fed015be1d7a411157b3686e725bc955cdfe2\"}], \"lock_time\": 0, \"hash\": \"54d071e5d9f12d70bcbd299dbeb0a4f4345e9cfb07e27f01e73cbbd5ba981138\", \"outputs\": [{\"script_hex\": \"a914aa220ee3fb8dc1347835a9dc9228ea3e3bc8203287\", \"output_index\": 0, \"value\": 5000000, \"address\": \"AXHTKWftA1NpfKDynbzqQPRq51pQD1VLhP\"}, {\"script_hex\": \"a9141eea95b625b8e9b0ad4820b863709d4c73a3500087\", \"output_index\": 1, \"value\": 4999180, \"address\": \"AJbLwVU5eYpTXPPGWmKfyyvY739Gnd6wXk\"}], \"amount\": 9999180, \"confirmations\": 28193, \"fees\": 820, \"received_at\": \"2017-11-21T12:51:30Z\", \"block\": {\"time\": \"2017-11-21T13:48:44Z\", \"hash\": \"000000000b119dd8068ef7a85cea25a4c3a8a8ddc94d2cf42b785daf392d2a21\", \"height\": 501072}}";
			const std::string TX_2 = "{\"inputs\": [{\"value\": 89997770, \"output_index\": 1, \"output_hash\": \"d5106478eb98766238a8bc244cf6eec5379f060be9c9ad5c64354af8f8742d16\", \"input_index\": 0, \"address\": \"GbsmhmCWAKN9B9QWAwhheyN1wRsp83QGvg\", \"script_signature\": \"473044022022eeba7c0c3c56df4c8fca2bb787978ba481505ebf691ef2e54aede642ed24f80220640eb26f8e4601b9f2fc062585e07aaa5c84fe232bdcbdf734e674217c54c53341210211d1249da5859a83f130a719756b22b41aabc110d4defdeb1662f0d70a2b8d97\"}], \"lock_time\": 0, \"hash\": \"424ffc81334d91f58c3d6f485936f51c9de2fb56ede4d17143129bb5e656c055\", \"outputs\": [{\"script_hex\": \"a914844e3d8d5f5634d8150c207719f62813e141b10287\", \"output_index\": 0, \"value\": 10000000, \"address\": \"ATqSa4V9ZjxPxDBe877bbXeKMfZA644mBk\"}, {\"script_hex\": \"76a914e4621594d4c7af9fd3e1dca2d36e22ceb9ae7aae88ac\", \"output_index\": 1, \"value\": 79995540, \"address\": \"GefVyt4qpRsdKApr1PFr2THm1xAkiY3Crh\"}], \"amount\": 89995540, \"confirmations\": 28733, \"fees\": 2230, \"received_at\": \"2017-11-18T00:06:01Z\", \"block\": {\"time\": \"2017-11-18T00:07:57Z\", \"hash\": \"00000000073d638e9a9c2730b09b9989497736943f11549ccc33f1a0cc1866af\", \"height\": 500532}}";
		}
	}
}
