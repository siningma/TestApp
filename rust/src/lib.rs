#[no_mangle]
pub extern "C" fn rust_multiply(a: f64, b: f64) -> f64 {
    a * b + 5.0
}

#[no_mangle]
pub extern "C" fn rust_add(a: i32, b: i32) -> i32 {
    a + b
}

#[no_mangle]
pub extern "C" fn rust_add_loop() -> i32 {
    let mut x = 0;
    for i in 0..100000 {
        let b = i;
        x += b;
    }
    x
}
