#ifndef JSIMODULE_H
#define JSIMODULE_H

// iOS has the JSI module included out-of-the-box through Pods,
// while Android will include it using `CMakeLists.txt`.
#include <jsi/jsi.h>

using namespace facebook::jsi;

namespace jsimodule
{
    void bridgeJSIFunctions(Runtime &jsi);
}

#endif /* JSIMODULE_H */
