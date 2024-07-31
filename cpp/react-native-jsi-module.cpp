#include "react-native-jsi-module.h"

namespace jsimodule
{

    extern "C"
    {
        // For instance, C++'s `double` type is the equivalent of Rust's `f64`
        // double rust_multiply(double a, double b);
        int add_benchmark(int cnt);
    }

    void bridgeJSIFunctions(Runtime &jsi)
    {
        // Define `addBenchmarkJSI` using JSI idioms.
        auto addBenchmarkJSI = Function::createFromHostFunction(
            jsi,
            PropNameID::forAscii(jsi, "addBenchmarkJSI"),
            2, // number of arguments
            [](Runtime &runtime, const Value &thisValue, const Value *arguments, size_t count) -> Value
            {
                if (count < 1)
                {
                    throw JSError(runtime, "add_benchmark() expects 1 arguments");
                }

                // double a = arguments[0].asNumber();
                //  double b = arguments[1].asNumber();
                int cnt = arguments[0].asNumber();

                // double ret = rust_multiply(a, b);
                int ret = add_benchmark(cnt);

                return Value(ret);
            });

        // Export `add_benchmark` to React Native's global object
        jsi.global().setProperty(jsi, "add_benchmark", std::move(addBenchmarkJSI));
    }

} //
