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

#[derive(Clone)]
pub struct Registro {
    cabeza: Link,
    cola: Link,
    pub tam: u64,
}

impl Registro { // Métodos del objeto "Registro"
    pub fn new_empty() -> Registro {
        Registro { cabeza: None, cola: None, tam: 0 }
    }

    pub fn append(&mut self, valor: String) {
        let new = Nodo::new(valor);

        match self.cola.take() {
            Some(old) => old.borrow_mut().next = Some(new.clone()),
            None => self.cabeza = Some(new.clone())
        };
        self.tam += 1;
        self.cola = Some(new);
    }

    pub fn pop(&mut self) -> Option<String> {
        self.cabeza.take().map(|head| {
            if let Some(sig) = cabeza.borrow_mut().next.take() {
                self.cabeza = Some(sig);
            } else {
                self.cola.take();
            }
            self.tam -= 1;
            Rc::try_unwrap(cabeza)
                .ok()
                .expect("Ocurrió un turbo error")
                .into_inner()
                .value
        })
    }
}
