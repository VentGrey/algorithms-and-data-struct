package ejemplosencillo.base

import java.util.LinkedList

interface IFuncionObjetivo {
    fun evaluar(values: LinkedList<Byte>): Integer
}
