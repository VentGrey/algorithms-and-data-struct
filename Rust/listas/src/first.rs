use std::mem;

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
    next: Link,
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
        let new_node = Box::new(Node {
            elem: elem,
            next: mem::replace(&mut self.head, Link::Empty),
        });

        self.head = Link::More(new_node);
    }

    pub fn pop(&mut self) -> Option<i32> {
        match mem::replace(&mut self.head, Link::Empty) {
            Link::Empty => None,
            Link::More(node) => {
                self.head = node.next;
                Some(node.elem)
            }
        }
    }
}

impl Drop for List {
    fn drop(&mut self) {
        let mut cur_link = mem::replace(&mut self.head, Link::Empty);
        // while let == "Hacer esto hasta que el patrón buscado ya no coincida"
        while let Link::More(mut boxed_node) = cur_link {
            cur_link = mem::replace(&mut boxed_node.next, Link::Empty);
        }
    }
}

// Código para pruebas, favor de no mover :3

mod test {
    use super::List;
    #[test]
    fn basics() {
        let mut list = List::new();

        // Prueba de que la lista vacía funcione bien
        assert_eq!(list.pop(), None);

        // Aquí poblaremos la lista
        list.push(1);
        list.push(2);
        list.push(3);
        list.push(4);
        list.push(5);
        list.push(6);
        list.push(7);
        list.push(8);
        list.push(9);
        list.push(10);

        // Probar que eliminar elementos funciona
        assert_eq!(list.pop(), Some(3));
        assert_eq!(list.pop(), Some(2));

        // Meter mas elementos para ver si se rompe algo
        list.push(11);
        list.push(12);

        // Eliminar los mismos elementos
        assert_eq!(list.pop(), Some(11));
        assert_eq!(list.pop(), Some(12));

        // Revisar el final de la lista
        assert_eq!(list.pop(), Some(1));
        assert_eq!(list.pop(), None);
    }
}
