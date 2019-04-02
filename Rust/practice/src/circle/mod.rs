/* Escriba un programa tal que dado el radio de un cı́rculo, calcule e imprima
el área y la circunferencia del mismo.*/

use std::io;

pub fn circle() {
    println!("Ingrese el radio de su círculo");
    let mut scanner = String::new();

    let rad: f64 = 0.0;
    io::stdin()
        .read_line(&mut scanner)
        .expect("Ocurrió un error al leer desde el teclado");
}
