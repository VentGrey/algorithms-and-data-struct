// Solo vamos a permitir los enteros de 32 bits

pub enum List { //Con "pub" podemos usar los enums fuera del archivo
    Empty,
    Elem(i32, Box<List>),
}

