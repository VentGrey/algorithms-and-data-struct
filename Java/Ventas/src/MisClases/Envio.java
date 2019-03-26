package MisClases;

public class Envio {
    private String ID, Nombre, Ciudad;
    private Boolean Pago, Empresa;

    public Envio(String ID, String Nombre, String Ciudad, Boolean Pago, 
            Boolean Empresa) {
        this.ID = ID;
        this.Nombre = Nombre;
        this.Ciudad = Ciudad;
        this.Pago = Pago;
        this.Empresa = Empresa;
    }

    public String getID() {
        return ID;
    }

    public String getNombre() {
        return Nombre;
    }

    public String getCiudad() {
        return Ciudad;
    }

    public Boolean getPago() {
        return Pago;
    }

    public Boolean getEmpresa() {
        return Empresa;
    }
}
