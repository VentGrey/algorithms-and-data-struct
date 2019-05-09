// Solo vamos a permitir los enteros de 32 bits


struct Node {
    elem: i32,
    next: List,
}

pub enum List { //Con "pub" podemos usar los enums fuera del archivo
    Empty,
    More(Box<Node>),
}
