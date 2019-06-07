package ejemplosencillo.EDA

import ejemplosencillo.base.IFuncionObjetivo
import java.util.LinkedList

class Item : Comparable<Item>, Cloneable {
    var values: LinkedList<Byte>? = null
        private set
    var fitness: Integer? = null
        private set

    constructor() {}
    private constructor(fitness: Integer, values: LinkedList<Byte>) {
        this.fitness = fitness
        this.values = values.clone() as LinkedList<Byte>
    }

    fun Generar(probabilidades: LinkedList<Float>) {
        this.values = LinkedList()
        for (prob in probabilidades) {
            if (Math.random() as Float<prob) {
                this.values!!.add(1.toByte())
            } else {
                this.values!!.add(0.toByte())
            }
        }
    }

    fun Evaluar(funcion: IFuncionObjetivo) {
        this.fitness = funcion.evaluar(values)
    }

    @Override
    fun compareTo(o: Item): Int {
        return this.fitness!!.compareTo(o.fitness)
    }

    @Override
    fun clone(): Item {
        return Item(this.fitness, this.values!!)
    }

    @Override
    fun toString(): String {
        return fitness + "=[" + values + "]"
    }


}
