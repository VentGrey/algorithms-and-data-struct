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

/*
 fn foo(self, arg2: Type2) -> ReturnType {
    // body
}

donde:

self - valor
&mut self - referencia mutable
&self - referencia compartida

 */

impl List {
    pub fn new() -> Self { // Con Self nos ahorramos el volver a escribir tipos
        List { head: Link::Empty }
    }

    pub fn push(&mut self, elem: i32) {
        let new_node = Node {
            elem: elem,
            next: self.head,
        }
    }
}
