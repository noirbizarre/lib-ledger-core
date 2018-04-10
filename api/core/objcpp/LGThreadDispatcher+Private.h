// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from thread_dispatcher.djinni

#include "ThreadDispatcher.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@protocol LGThreadDispatcher;

namespace djinni_generated {

class ThreadDispatcher
{
public:
    using CppType = std::shared_ptr<::ledger::core::api::ThreadDispatcher>;
    using CppOptType = std::shared_ptr<::ledger::core::api::ThreadDispatcher>;
    using ObjcType = id<LGThreadDispatcher>;

    using Boxed = ThreadDispatcher;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

