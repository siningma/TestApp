use std::hint::black_box;

#[no_mangle]
pub extern "C" fn rust_multiply(a: f64, b: f64) -> f64 {
    a * b + 5.0
}

#[no_mangle]
pub extern "C" fn add_benchmark(count: i32) -> i32 {
    let mut x = 0;
    for _ in 0..count {
        x += black_box(1);
    }
    x
}
