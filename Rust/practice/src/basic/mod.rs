/*Escriba un programa que dado como datos dos números reales, calcule la
suma, resta y multiplicación de dichos números.*/

use std::error::Error;
use std::io;

pub fn basic_op() {
    println!("Ingrese su primer número");
    let mut scanner = String::new();

    let mut sum: f64 = 0.0;
    let mut sub: f64 = 0.0;
    let mut mult: f64 = 0.0;
    let mut div: f64 = 0.0;

    io::stdin()
        .read_line(&mut scanner)
        .expect("Ocurrió un error al leer la entrada");

    let num_1 = scanner.trim();

    match num_1.parse::<f64>() {
        Ok(num_1) => {
            sum = num_1;
            sub = num_1;
            mult = num_1;
            div = num_1;
        }
        Err(e) => {
            eprintln!("Esto no es un número: {}", num_1);
            eprintln!("Error: {}", e.description());
        }
    }

    println!("Ingrese su segundo número");
    let mut scanner = String::new();
    io::stdin()
        .read_line(&mut scanner)
        .expect("Ocurrió un error al leer la entrada");

    let num_2 = scanner.trim();

    match num_2.parse::<f64>() {
        Ok(num_2) => {
            sum += num_2;
            sub -= num_2;
            mult *= num_2;
            div /= num_2;
        }
        Err(e) => {
            eprintln!("This is not a number {}", num_2);
            eprintln!("Error: {}", e.description());
            panic!("Cannot recover from error, exiting");
        }
    }

    println!("The sum of {} + {} is: {}", num_1, num_2, sum);
    println!("The diff of {} - {} is: {}", num_1, num_2, sub);
    println!("The product of {} * {} is: {}", num_1, num_2, mult);
    println!("The division of {} / {} is: {}", num_1, num_2, div);
}
