/* Escriba un programa tal que dado el radio de un cı́rculo, calcule e imprima
el área y la circunferencia del mismo.*/

use std::f64::consts::PI;
use std::io;

pub fn circle() {
    println!("Ingrese el radio de su círculo");
    let mut scanner = String::new();

    io::stdin()
        .read_line(&mut scanner)
        .expect("Ocurrió un error al leer desde el teclado");

    let num1 = scanner.trim();

    match num1.parse::<f64>() {
        Ok(num1) => {
            println!("El radio se registró correctamente! {}", num1);
            let area: f64 = num1 * num1 * PI;
            let perim: f64 = (num1 * 2.0) * PI;
            println!("El área del círculo es: {}", area);
            println!("La circúnferencia es: {}", perim);
        }
        Err(e) => {
            eprintln!("Esto no es un número {}", num1);
            eprintln!("Error: {}", e.to_string());
        }
    }
}
