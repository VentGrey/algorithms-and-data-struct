use std::io;

fn basic_op() {
    println!("¡Operaciones básicas!");

    loop {
        println!("Ingrese el primer número");
        let mut entrada = String::new();

        io::stdin().read_line(&mut entrada)
            .expect("Fallo al leer desde teclado");

        let entrada: f64 = match entrada.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
    }

    loop {
        println!("Ingrese el segundo número");
        let mut entrada = String::new();
        io::stdin().read_line(&mut entrada)
            .expect("Fallo al leer desde teclado");

        let entrada: f64 = match entrada.trim().parse() {
            Ok(num) = num,
            Err(_) => continue,
        };
    }
}
