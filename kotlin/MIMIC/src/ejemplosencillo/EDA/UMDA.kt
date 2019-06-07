package ejemplosencillo.EDA

import ejemplosencillo.base.IFuncionObjetivo
import java.util.Collections
import java.util.LinkedList

/**
 *
 * @author Marco Sotelo
 */
class UMDA(Dimension: Integer, Iteraciones: Integer, Poblacion: Integer, Seleccion: Integer, funcion: IFuncionObjetivo) : EDA(Dimension, Iteraciones, Poblacion, Seleccion, funcion) {

    @Override
    fun pdf(de: LinkedList<Item>): LinkedList<Float> {
        val probabilidades = LinkedList()
        for (i in 0 until this.Dimension) {
            probabilidades.add(0.0f)
        }
        for (item in de) {
            for (i in 0 until item.getValues().size()) {
                probabilidades.set(i, probabilidades.get(i) + item.getValues().get(i))
            }
        }
        for (i in 0 until this.Dimension) {
            probabilidades.set(i, probabilidades.get(i) / de.size())
        }
        return probabilidades
    }

    @Override
    fun Muestrear(pdf: LinkedList<Float>, Num: Integer): LinkedList<Item> {
        val items = LinkedList()
        for (i in 0 until Num) {
            items.add(Item())
            items.getLast().Generar(pdf)
            items.getLast().Evaluar(this.funcion)
        }
        Collections.sort(items)
        return items
    }

}
