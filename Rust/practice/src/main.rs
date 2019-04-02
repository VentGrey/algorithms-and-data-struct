mod basic;
mod circle;

use std::io;

fn main() {
    println!("----------Menú principal----------");
    println!("Seleccione el código a ejecutar:");
    println!("1- Operaciones básicas");

    let mut entrada = String::new();
    io::stdin().read_line(&mut entrada).unwrap();
    let num: u32 = entrada.trim().parse().unwrap();

    match num {
        1 => basic::basic_op(),
        _ => panic!("Error de entrada D:"),
    }
}
