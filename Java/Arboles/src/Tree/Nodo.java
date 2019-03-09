package Tree;


public class Nodo<T extends Comparable> implements Comparable<Nodo<T>> {
    private Nodo<T> Izquierdo = null;
    private final T Valor;
    private Nodo<T> Derecho = null;

    public Nodo<T> getIzquierdo() {
        return Izquierdo;
    }

    public T getValor() {
        return Valor;
    }

    public Nodo<T> getDerecho() {
        return Derecho;
    }

    public void setIzquierdo(Nodo<T> Izquierdo) {
        this.Izquierdo = Izquierdo;
    }

    public void setDerecho(Nodo<T> Derecho) {
        this.Derecho = Derecho;
    }
    
    
    public Nodo(T Valor) {
        this.Valor = Valor;
    }

    @Override
    public int compareTo(Nodo<T> o) {
        return this.Valor.compareTo(o);
    }

    @Override
    public String toString() {
        return String.valueOf(this.Valor);
    }
}
