// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet.djinni

#ifndef DJINNI_GENERATED_COSMOSGASLIMITREQUEST_HPP_JNI_
#define DJINNI_GENERATED_COSMOSGASLIMITREQUEST_HPP_JNI_

#include "../../api/CosmosGasLimitRequest.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class CosmosGasLimitRequest final {
public:
    using CppType = ::ledger::core::api::CosmosGasLimitRequest;
    using JniType = jobject;

    using Boxed = CosmosGasLimitRequest;

    ~CosmosGasLimitRequest();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    CosmosGasLimitRequest();
    friend ::djinni::JniClass<CosmosGasLimitRequest>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/CosmosGasLimitRequest") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;Ljava/util/ArrayList;Ljava/lang/String;)V") };
    const jfieldID field_memo { ::djinni::jniGetFieldID(clazz.get(), "memo", "Ljava/lang/String;") };
    const jfieldID field_messages { ::djinni::jniGetFieldID(clazz.get(), "messages", "Ljava/util/ArrayList;") };
    const jfieldID field_amplifier { ::djinni::jniGetFieldID(clazz.get(), "amplifier", "Ljava/lang/String;") };
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_COSMOSGASLIMITREQUEST_HPP_JNI_
