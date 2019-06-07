package ejemplosencillo.EDA

import ejemplosencillo.EDA.Item
import ejemplosencillo.base.IFuncionObjetivo
import java.util.Collections
import java.util.LinkedList

abstract class EDA(protected var Dimension: Integer, protected var Iteraciones: Integer, protected var Poblacion: Integer, protected var Seleccion: Integer,
                   funcion: IFuncionObjetivo) {
    protected var funcion: IFuncionObjetivo? = null

    var poblacion: LinkedList<Item>? = null
        protected set


    init {
        this.funcion = funcion
    }

    fun Ejecutar() {
        try {
            this.poblacion = LinkedList()
            var items = Inicializar()
            this.poblacion!!.add(items.getFirst().clone())
            for (i in 0 until this.Iteraciones) {
                val probabilidades = pdf(Seleccion(items, this.Seleccion))
                items = Muestrear(probabilidades, this.Poblacion)
                this.poblacion!!.add(items.getFirst().clone())
            }
        } catch (ex: Exception) {
            System.err.println(ex)
        }

    }

    private fun Inicializar(): LinkedList<Item> {
        val probabilidades = LinkedList()
        for (i in 0 until this.Dimension) {
            probabilidades.add(0.5f)
        }

        val items = LinkedList()
        for (i in 0 until this.Poblacion) {
            items.add(Item())
            items.getLast().Generar(probabilidades)
            items.getLast().Evaluar(this.funcion)
        }
        Collections.sort(items)
        return items
    }

    private fun Seleccion(items: LinkedList<Item>, numer: Integer): LinkedList<Item> {
        val de = LinkedList()
        for (i in 0 until numer) {
            de.add(items.get(i).clone())
        }
        return de
    }

    abstract fun pdf(de: LinkedList<Item>): LinkedList<Float>
    abstract fun Muestrear(pdf: LinkedList<Float>, Num: Integer): LinkedList<Item>

}
