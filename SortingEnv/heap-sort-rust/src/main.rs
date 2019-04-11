use std::io;

fn main() {

}

fn create(heap: &[i32]) {
    let mut n: i32;
   
    n = heap[0];

    for e in (0..=n/2).rev() {
        adjust(heap, e);
    }
}

fn adjust(heap: &[i32], i:i32) {
    let mut j:i32 = 1;
    let mut temp: i32 = 1;
    let mut n: i32 = 1;
    let mut flag = 1;

    n = heap[0];

    while 2 * i <=n && flag == 1 {

        j = 2*i;

        if j + 1 <= n && heap[j + 1] > heap[j] {
            j = j + 1;
        }

        if heap[i] > heap[j] {
            flag = 0;
        } else {
            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
        }
    }
}
