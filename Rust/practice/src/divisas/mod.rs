/*
* En una Casa de Cambio necesitan construir un programa tal que dado como
* dato una cantidad expresada en dólares, convierta esa cantidad a pesos.
* Elabore un programa que permita resolver el problema.
*/

use std::io;

pub fn divisas() {
    println!("Ingrese la cantidad de dólares que posee: ");
    let mut scanner = String::new();

    io::stdin()
        .read_line(&mut scanner)
        .expect("Error al leer desde teclado");

    const VALORPESO: f64 = 18.75;

    let dlls = scanner.trim();
    let cambio: f64;

    match dlls.parse::<f64>() {
        Ok(dlls) => {
            cambio = dlls * VALORPESO;
        }
        Err(_e) => {
            eprintln!("Esto no es un número válido {}", _e);
            panic!();
        }
    }
    println!("Usted posee {} pesos mexicanos", cambio);
}
