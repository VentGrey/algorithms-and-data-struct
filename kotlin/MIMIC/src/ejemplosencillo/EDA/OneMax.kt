package ejemplosencillo.EDA

import ejemplosencillo.base.IFuncionObjetivo
import java.util.LinkedList

class OneMax : IFuncionObjetivo {

    @Override
    fun evaluar(values: LinkedList<Byte>): Integer {
        var suma: Byte = 0
        for (item in values) {
            suma += item.toByte()
        }
        return values.size() - suma
    }

}
