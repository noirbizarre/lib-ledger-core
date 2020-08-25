// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from idl.djinni

#include "AlgorandAssetParams.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

AlgorandAssetParams::AlgorandAssetParams() = default;

AlgorandAssetParams::~AlgorandAssetParams() = default;

auto AlgorandAssetParams::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<AlgorandAssetParams>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.assetId)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.assetName)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.unitName)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.url)),
                                                           ::djinni::get(::djinni::Bool::fromCpp(jniEnv, c.defaultFrozen)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.total)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.decimals)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.creatorAddress)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.managerAddress)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.freezeAddress)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.clawbackAddress)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.reserveAddress)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.metadataHash)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto AlgorandAssetParams::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 14);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<AlgorandAssetParams>::get();
    return {::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_assetId)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_assetName)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_unitName)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_url)),
            ::djinni::Bool::toCpp(jniEnv, jniEnv->GetBooleanField(j, data.field_defaultFrozen)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_total)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_decimals)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_creatorAddress)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_managerAddress)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_freezeAddress)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_clawbackAddress)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_reserveAddress)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_metadataHash))};
}

}  // namespace djinni_generated
