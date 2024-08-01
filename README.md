# Test App

This is a testing app to validate Rust can be called in React native through JSI

## Test History

1. rust_multiply can be called in iOS and Android
2. Add getDeviceName function
3. ios xcframework includes release and sim release
4. plus 1 benchmark testing with 200M iteractions and executed 5 times on Android physical device in release mode
   add_js is javascript, add_benchmark is rust
   ```
    08-01 11:26:56.342 24540 24574 I ReactNativeJS: Running "TestApp
    08-01 11:32:11.228 24792 24824 I ReactNativeJS: loop 0: js_add execution time: 1181 ms
    08-01 11:32:12.433 24792 24824 I ReactNativeJS: loop 1: js_add execution time: 1205 ms
    08-01 11:32:13.638 24792 24824 I ReactNativeJS: loop 2: js_add execution time: 1205 ms
    08-01 11:32:14.809 24792 24824 I ReactNativeJS: loop 3: js_add execution time: 1171 ms
    08-01 11:32:16.015 24792 24824 I ReactNativeJS: loop 4: js_add execution time: 1206 ms
    08-01 11:32:16.090 24792 24824 I ReactNativeJS: loop0: add_benchmark execution time: 75 ms
    08-01 11:32:16.162 24792 24824 I ReactNativeJS: loop1: add_benchmark execution time: 72 ms
    08-01 11:32:16.234 24792 24824 I ReactNativeJS: loop2: add_benchmark execution time: 72 ms
    08-01 11:32:16.305 24792 24824 I ReactNativeJS: loop3: add_benchmark execution time: 71 ms
    08-01 11:32:16.377 24792 24824 I ReactNativeJS: loop4: add_benchmark execution time: 72 ms
   ```
