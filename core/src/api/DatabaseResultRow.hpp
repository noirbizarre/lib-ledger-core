// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from database.djinni

#ifndef DJINNI_GENERATED_DATABASERESULTROW_HPP
#define DJINNI_GENERATED_DATABASERESULTROW_HPP

#include <cstdint>
#include <memory>
#include <string>

namespace ledger { namespace core { namespace api {

class DatabaseBlob;

class DatabaseResultRow {
public:
    virtual ~DatabaseResultRow() {}

    virtual bool isNullAtPos(int32_t pos) = 0;

    virtual std::string getColumnName(int32_t pos) = 0;

    virtual int16_t getShortByPos(int32_t pos) = 0;

    virtual int32_t getIntByPos(int32_t pos) = 0;

    virtual float getFloatByPos(int32_t pos) = 0;

    virtual double getDoubleByPos(int32_t pos) = 0;

    virtual int64_t getLongByPos(int32_t pos) = 0;

    virtual std::string getStringByPos(int32_t pos) = 0;

    virtual std::shared_ptr<DatabaseBlob> getBlobByPos(int32_t pos) = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_DATABASERESULTROW_HPP
