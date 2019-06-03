package ejemplosencillo.EDA;

import ejemplosencillo.base.IFuncionObjetivo;
import java.util.LinkedList;

public class OneMax implements IFuncionObjetivo{

    @Override
    public Integer evaluar(LinkedList<Byte> values) {
        byte suma = 0;
        for (Byte item: values){
            suma += item;
        }
        return values.size()-suma;
    }

}
