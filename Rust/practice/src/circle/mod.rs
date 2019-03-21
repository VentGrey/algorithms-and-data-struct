/* Escriba un programa tal que dado el radio de un cı́rculo, calcule e imprima
el área y la circunferencia del mismo.*/

use std::io;

fn circle() {
    println!("¡Área del círculo!");

    loop {
        println!("Ingrese el radio del círculo");
        let mut entrada = String::new();

        io::stdin().read_line(&mut entrada)
            .expect("Fallo al leer desde teclado");

        let entrada: f64 = match entrada.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
    }
}
