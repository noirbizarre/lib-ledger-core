// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from database.djinni

#ifndef DJINNI_GENERATED_DATABASECOLUMN_HPP
#define DJINNI_GENERATED_DATABASECOLUMN_HPP

#include <string>

namespace ledger { namespace core { namespace api {

enum class DatabaseValueType;

class DatabaseColumn {
public:
    virtual ~DatabaseColumn() {}

    virtual DatabaseValueType getType() = 0;

    virtual std::string getName() = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_DATABASECOLUMN_HPP
