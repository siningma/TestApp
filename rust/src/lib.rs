#[no_mangle]
pub extern "C" fn rust_multiply(a: f64, b: f64) -> f64 {
    a * b + 5.0
}