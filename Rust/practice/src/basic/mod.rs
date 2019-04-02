/*Escriba un programa que dado como datos dos números reales, calcule la
suma, resta y multiplicación de dichos números.*/

use std::io;

pub fn basic_op() {
    println!("Please input your first number");
    let mut scanner = String::new();

    let mut sum: f64 = 0.0;

    io::stdin()
        .read_line(&mut scanner)
        .expect("Something went wrong when reading user input");

    let num_1 = scanner.trim();

    match num_1.parse::<f64>() {
        Ok(num_1) => {
            println!("Number 1 registered correctly! {}", num_1);
            sum += num_1;
        }
        Err(e) => {
            eprintln!("This is not a number {}", num_1);
            eprintln!("Error: {}", e.to_string());
        }
    }

    println!("Input yout second number");
    let mut scanner = String::new();
    io::stdin()
        .read_line(&mut scanner)
        .expect("Something went wrong when reading user input");

    let num_2 = scanner.trim();

    match num_2.parse::<f64>() {
        Ok(num_2) => {
            println!("Number 2 registered correctly! {}", num_2);
            sum += num_2;
        }
        Err(e) => {
            eprintln!("This is not a number {}", num_2);
            eprintln!("Error: {}", e);
            panic!("Cannot recover from error, exiting");
        }
    }

    println!("The sum of {} and {} is: {}", num_1, num_2, sum);
}
