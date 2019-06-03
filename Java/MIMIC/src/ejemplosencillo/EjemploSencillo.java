package ejemplosencillo;

import ejemplosencillo.EDA.EDA;
import ejemplosencillo.EDA.UMDA;
import ejemplosencillo.EDA.OneMax;
import ejemplosencillo.EDA.Item;
import ejemplosencillo.base.IFuncionObjetivo;

public class EjemploSencillo {

    public static void main(String[] args) {
        try {
            IFuncionObjetivo funcion = new OneMax();
            EDA eda = new UMDA(100, 100, 70, 20, funcion);
            eda.Ejecutar();
            for (Item item: eda.getPoblacion()){
                System.out.println(item);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }

}
