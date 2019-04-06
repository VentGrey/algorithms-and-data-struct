package ejemplosencillo.EDA;

import ejemplosencillo.base.IFuncionObjetivo;
import java.util.LinkedList;

public class Item implements Comparable<Item>, Cloneable{
    private LinkedList<Byte> values = null;
    private Integer fitness;

    public LinkedList<Byte> getValues() {
        return values;
    }
    public Integer getFitness() {
        return fitness;
    }
    
    public Item(){}
    private Item(Integer fitness, LinkedList<Byte> values){
        this.fitness=fitness;
        this.values = (LinkedList<Byte>) values.clone();
    }
    
    public void Generar(LinkedList<Float> probabilidades){
        this.values = new LinkedList<>();
        for (Float prob: probabilidades){
            if ((float)Math.random()<prob){
                this.values.add((byte) 1);
            } else {
                this.values.add((byte) 0);
            }
        }
    }
    
    public void Evaluar(IFuncionObjetivo funcion){
        this.fitness = funcion.evaluar(values);
    }

    @Override
    public int compareTo(Item o) {
        return this.fitness.compareTo(o.fitness);
    }
    
    @Override
    public Item clone(){
        return new Item(this.fitness, this.values);
    }

    @Override
    public String toString() {
        return fitness + "=[" + values + "]";
    }
    
    
}
