/*
* En una Casa de Cambio necesitan construir un programa tal que dado como
* dato una cantidad expresada en dólares, convierta esa cantidad a pesos. 
* Elabore un programa que permita resolver el problema.
*/

use std::io;

fn main() {
    println!("Ingrese la cantidad de dólares que posee: ");
    let mut Scanner = String::new();
    let mut dlls: f64 = 0.0;

    io::stdin().read_line(&mut Scanner)
    .expect("Error al leer desde teclado")

    const pesos:f64 = 18.75;

}