#include "react-native-jsi-module.h"

namespace jsimodule
{

    // Temporary C++ that we want to be imported from Rust.
    double cpp_multiply(double a, double b)
    {
        return a * b;
    }

    void bridgeJSIFunctions(Runtime &jsi)
    {
        // Define `multiplyJSI` using JSI idioms.
        auto multiplyJSI = Function::createFromHostFunction(
            jsi,
            PropNameID::forAscii(jsi, "multiplyJSI"),
            2, // number of arguments
            [](Runtime &runtime, const Value &thisValue, const Value *arguments, size_t count) -> Value
            {
                if (count < 2)
                {
                    throw JSError(runtime, "multiply() expects 2 arguments");
                }

                double a = arguments[0].asNumber();
                double b = arguments[1].asNumber();

                double ret = cpp_multiply(a, b);

                return Value(ret);
            });

        // Export `multiply` to React Native's global object
        jsi.global().setProperty(jsi, "multiply", std::move(multiplyJSI));
    }

} //
