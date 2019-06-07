package ejemplosencillo

import ejemplosencillo.EDA.EDA
import ejemplosencillo.EDA.UMDA
import ejemplosencillo.EDA.OneMax
import ejemplosencillo.EDA.Item
import ejemplosencillo.base.IFuncionObjetivo

object EjemploSencillo {

    fun main(args: Array<String>) {
        try {
            val funcion = OneMax()
            val eda = UMDA(100, 100, 70, 20, funcion)
            eda.Ejecutar()
            for (item in eda.getPoblacion()) {
                System.out.println(item)
            }
        } catch (e: Exception) {
            System.out.println(e)
        }

    }

}
