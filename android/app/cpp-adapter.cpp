#include <jni.h>
#include <jsi/jsi.h>
#include <sys/system_properties.h>
#include "react-native-jsi-module.h"

using namespace facebook::jsi;

// Optional:
void bridgePlatformFunctions(Runtime &jsi);

extern "C" JNIEXPORT void JNICALL
Java_com_testapp_JsiModuleModule_jniBridgeJSIFunctions(JNIEnv *env, jobject thiz, jobject context,
                                                       jlong jsi_pointer)
{
    Runtime *jsi = reinterpret_cast<Runtime *>(jsi_pointer);
    if (jsi)
    {
        jsimodule::bridgeJSIFunctions(*jsi);

        // Optional: bridge platform-specific logic too.
        bridgePlatformFunctions(*jsi);
    }
}

// Optional:
void bridgePlatformFunctions(Runtime &jsi)
{
    auto getDeviceName = Function::createFromHostFunction(jsi,
                                                          PropNameID::forAscii(jsi, "getDeviceName"),
                                                          0,
                                                          [](Runtime &runtime,
                                                             const Value &thisValue,
                                                             const Value *arguments,
                                                             size_t count) -> Value
                                                          {
                                                              // JNI logic for another time!
                                                              char model_string[PROP_VALUE_MAX + 1];
                                                              __system_property_get("ro.product.model", model_string);
                                                              return Value(runtime, String::createFromAscii(runtime, model_string));
                                                          });

    jsi.global().setProperty(jsi, "getDeviceName", std::move(getDeviceName));
}
