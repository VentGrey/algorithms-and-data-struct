package ejemplosencillo.EDA;

import ejemplosencillo.EDA.Item;
import ejemplosencillo.base.IFuncionObjetivo;
import java.util.Collections;
import java.util.LinkedList;

public abstract class EDA {
    protected IFuncionObjetivo funcion = null;
    protected Integer Dimension;
    protected Integer Iteraciones;
    protected Integer Poblacion;
    protected Integer Seleccion;
    
    protected LinkedList<Item> poblacion = null;

    public LinkedList<Item> getPoblacion() {
        return poblacion;
    }

    
    public EDA(Integer Dimension, Integer Iteraciones, Integer Poblacion, Integer Seleccion,
            IFuncionObjetivo funcion) {
        this.Dimension = Dimension;
        this.Iteraciones = Iteraciones;
        this.Poblacion = Poblacion;
        this.Seleccion = Seleccion;
        this.funcion = funcion;
    }
    
    public void Ejecutar(){
        try {
            this.poblacion = new LinkedList<>();
            LinkedList<Item> items = Inicializar();
            this.poblacion.add(items.getFirst().clone());
            for (int i=0; i<this.Iteraciones; i++){
                LinkedList<Float> probabilidades = pdf(Seleccion(items, this.Seleccion));
                items = Muestrear(probabilidades, this.Poblacion);
                this.poblacion.add(items.getFirst().clone());
            }
        } catch (Exception ex){
            System.err.println(ex);
        }
    }
    
    private LinkedList<Item> Inicializar(){
        LinkedList<Float> probabilidades = new LinkedList<>();
        for (int i=0; i<this.Dimension; i++){
            probabilidades.add(0.5f);
        }
        
        LinkedList<Item> items = new LinkedList<>();
        for (int i=0; i<this.Poblacion; i++){
            items.add(new Item());
            items.getLast().Generar(probabilidades);
            items.getLast().Evaluar(this.funcion);
        }
        Collections.sort(items);
        return items;
    }
    private LinkedList<Item> Seleccion(LinkedList<Item> items, Integer numer){
        LinkedList<Item> de = new LinkedList<>();
        for (int i=0; i<numer; i++){
            de.add(items.get(i).clone());
        }
        return de;
    }
    public abstract LinkedList<Float> pdf(LinkedList<Item> de);
    public abstract LinkedList<Item> Muestrear(LinkedList<Float> pdf, Integer Num);
    
}
