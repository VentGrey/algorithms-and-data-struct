package ejemplosencillo.EDA;

import ejemplosencillo.base.IFuncionObjetivo;
import java.util.Collections;
import java.util.LinkedList;

/**
 *
 * @author Marco Sotelo
 */
public class UMDA extends EDA{
    public UMDA(Integer Dimension, Integer Iteraciones, Integer Poblacion, Integer Seleccion, IFuncionObjetivo funcion) {
        super(Dimension, Iteraciones, Poblacion, Seleccion, funcion);
    }

    @Override
    public LinkedList<Float> pdf(LinkedList<Item> de) {
        LinkedList<Float> probabilidades = new LinkedList<>();
        for(int i=0; i<this.Dimension; i++){
            probabilidades.add(0.0f);
        }
        for (Item item: de){
            for (int i=0; i<item.getValues().size(); i++){
                probabilidades.set(i, probabilidades.get(i)+item.getValues().get(i));
            }
        }
        for(int i=0; i<this.Dimension; i++){
            probabilidades.set(i, probabilidades.get(i)/de.size());
        }
        return probabilidades;
    }

    @Override
    public LinkedList<Item> Muestrear(LinkedList<Float> pdf, Integer Num) {
        LinkedList<Item> items = new LinkedList<>();
        for (int i=0; i<Num; i++){
            items.add(new Item());
            items.getLast().Generar(pdf);
            items.getLast().Evaluar(this.funcion);
        }
        Collections.sort(items);
        return items;
    }

}
