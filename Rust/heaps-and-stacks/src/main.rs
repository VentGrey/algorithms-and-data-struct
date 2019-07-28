use std::mem;

struct Struct {
    a: u8,
    b: u8,
    c: u8
}

fn main() {
    assert_eq!(mem::size_of::<Struct>(), 3 * mem::size_of::<u8>());
    assert_eq!(mem::size_of::<[Struct; 2]>(), 3 * mem::size_of::<u8>() * 2);
}
