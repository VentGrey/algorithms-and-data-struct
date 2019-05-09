// Solo vamos a permitir los enteros de 32 bits

pub struct List {
    head: Link,
}

enum Link {
    Empty,
    More(Box<Node>),
}

struct Node {
    elem: i32,
    nect: Link,
}

impl List {
    pub fn new() -> Self {
        List { head: Link::Empty }
    }
}
