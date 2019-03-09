/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Tree;

/**
 *
 * @author omar
 * @param <T>
 */
public class Arbol<T extends Comparable> {

    private Nodo<T> raiz = null;

    public void Insertar(T valor) {
        if (this.raiz == null) {
            this.raiz = new Nodo<>(valor);
        } else {
            Nodo nodo = raiz;
            while (nodo != null) {
                int cmp = valor.compareTo(nodo.getValor());
                if (cmp == 0) {
                    return;
                } else if (cmp < 0) {
                    if (nodo.getIzquierdo() == null) {
                        nodo.setIzquierdo(new Nodo<>(valor));
                    } else {
                        nodo = nodo.getIzquierdo();
                    }
                } else {
                    if (nodo.getDerecho() == null) {
                        nodo.setDerecho(new Nodo<>(valor));
                        nodo.getDerecho();
                    }
                }
            }
        }
    }

    public void InFijo() {
        InFijoPrint(raiz);
    }

    private void InFijoPrint(Nodo<T> nodo) {
        if (nodo.getIzquierdo() != null) {
            InFijoPrint(nodo.getIzquierdo());
        }
        System.out.println(nodo.getValor());
        if (nodo.getDerecho() != null) {
            InFijoPrint(nodo.getDerecho());
        }
    }

    public void PreFijo() {
        PreFijoPrint(raiz);
    }

    private void PreFijoPrint(Nodo<T> nodo) {
        System.out.println(nodo.getValor());

        if (nodo.getIzquierdo() != null) {
            InFijoPrint(nodo.getIzquierdo());
        }

        if (nodo.getDerecho() != null) {
            InFijoPrint(nodo.getDerecho());
        }
    }

    public void PosFijo() {
        PosFijoPrint(raiz);
    }

    private void PosFijoPrint(Nodo<T> nodo) {
        System.out.println(nodo.getValor());

        if (nodo.getIzquierdo() != null) {
            PosFijoPrint(nodo.getIzquierdo());
        }

        if (nodo.getDerecho() != null) {
            PosFijoPrint(nodo.getDerecho());
        }
    }
}
