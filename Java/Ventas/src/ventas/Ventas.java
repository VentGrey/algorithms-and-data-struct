package ventas;

import MisClases.Envio;
import java.util.ArrayList;
import java.util.Scanner;

public class Ventas {
    public static void main(String[] args) {
        ArrayList<Envio> datos = new ArrayList<>();
        
        for(int i = 0; i < 7; i++) {
            Scanner teclado = new Scanner(System.in);
            String IDex;
            System.out.println("Dame el ID del envío");
            IDex = teclado.nextLine();
            
            String NombreEx;
            System.out.println("Dame el nombre del cliente");
            NombreEx = teclado.nextLine();
            
            String CiudadEx;
            System.out.println("Dame la ciudad de envío");
            CiudadEx = teclado.nextLine();
            
            Boolean PagoEx;
            System.out.println("Ingrese true para Cred o false para Cont");
            PagoEx = teclado.nextBoolean();
            
            Boolean EmpresaEx;
            System.out.println("Ingrese true para Fedex o false para Mexpost");
            EmpresaEx = teclado.nextBoolean();
            
            Envio temp = new Envio(IDex, NombreEx, CiudadEx, PagoEx, EmpresaEx);
            datos.add(temp);
        }
    }
    
}
