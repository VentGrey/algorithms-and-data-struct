use std::cell::RefCell;
// Ubicación de memoria mutable con ownership comprobada dinámicamente

use std::rc::Rc;
//Un puntero de conteo de referencia de un solo hilo.

#[derive(Clone)] // Utilizado para duplicar un objeto de manera explicíta
struct Nodo {
    valor: String,
    sig: Link, // Tipo "enlace" porque #nohaypunteros
}

type Link = Option<Rc<RefCell<Nodo>>>; // Err...mas o menos emula un apuntador

impl Nodo { // Aquí colocaremos los métodos del "objeto" nodo.
    fn new(valor: String) -> Rc<RefCell<Node>> {
        Rc::new(RefCell::new(Node {
            valor: valor,
            sig: None,
        }))
    }
}
