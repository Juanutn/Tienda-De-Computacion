#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED
class Fecha
{
private:
    int dia;
    int mes;
    int anio;
public:
   fecha(){int dia=mes=anio=0;}
    void cargarfecha();
    int getdia()
    {
        return dia;
    }
    int getmes()
    {
        return mes;
    }
    int getanio()
    {
        return anio;
    }
    void setdia(int d)
    {
        dia=d;
    }
    void setmes(int m)
    {
        mes=m;
    }
    void setanio(int a)
    {
        anio=a;
    }
};
class Persona
{
protected:
    char nombre[40];
    char apellido[40];
    int dni;
    int nroTelefono;
    char  domicilio[50];
    Fecha nacimiento;
    char email[50];
    char genero[10];
    int activo=1;
public:
    persona(){activo=0;}
    const char *getNombre();
    const char *getApellido();
    int getDni();
    int getNroTelefono();
    const char *getDomicilio();
    const char *getEmail();
    const char *getGenero();
    void setNombre(const char *);
    void setApellido(const char *);
    void setDni(int);
    void setNroTelefono(int);
    void setDomicilio(const char *);
    void setEmail(const char *);
    void setGenero(const char *);
    bool nuevapersona();
    bool grabarpersona();
    bool altapersona();
    bool leerdedisco(int);
    void mostrarpersona();
    void eliminarpersona();
    void modificarpersona();
    void listarpersona();
    void buscarporDNI();
};
class Producto
{
private:
    char codigoProducto [10];
    char nombre[40];
    float precio;
    int stock;
    int codigoMarca;
    int codigoCategoriaProducto;
    int activo=1;
public:
    producto(){activo=0;}
    void CargarProducto();
    void MostrarProducto();
    const char *getCodigo();
    const char *getNombre();
    float getPrecio();
    int getStock();
    void setCodigo(const char *);
    void setNombre(const char *);
    void setPrecio(float);
    void setStock(int);
    bool nuevoproducto();
    bool grabarproducto();
    bool altaproducto();
    bool leerdedisco(int);
    void mostrarproducto();
    void eliminarproducto();
    void modificarproducto();
    void listarproducto();
    void buscarporCodigoProducto();

};
class Marca
{
private:
    int codigoMarca;
    char nombreMarca[40];
public:
    const char *getNombre();
    void setNombre(const char *);
    int getCodigoMarca();
    void setCodigoMarca(int);
};
class Categoria
{
private:
    int codigoCategoriaProducto;
    char nombreCategoriaProducto[40];
public:
    int getCodigoCate();
    const char *getNombreCat();
    void setCodigoCate(int);
    void setNombreCate(const char *);
};
class Proveedor
{
private:
    int numeroProveedor;
    char nombre[40];
    char apellido[40];
    int dni;
    int nroTelefono;
    char  domicilio[50];
    Fecha nacimiento;
    char email[50];
    char genero[10];

    bool activo;
public:
    bool getActivo();
    void setActivo(bool a){activo=a;}
    bool CargarProveedor();
    void MostrarProveedor();
    int getNumeroProveedor();

    void setNumeroProveedor(int );
    bool grabarProveedor();
    bool leerProveedor(int );
    bool altaProveedor();
    bool leerDiscoProveedor(int );
    void listarPorNumeroProveedor();
    void bajaProveedor();
    bool modificarProveedor(int);
    void modificarProveedorNuevo();
    void listarProveedor();
    int buscarProveedor(int);
};
class Cliente
{

private:
    int idCliente;
    char nombre[40];
    char apellido[40];
    int dni;
    int nroTelefono;
    char  domicilio[50];
    Fecha nacimiento;
    char email[50];
    char genero[10];

    bool activo;

public:
    bool getActivo();
    void setActivo(bool a){activo=a;}
    bool CargarCliente();
    void MostrarCliente();
    int getIDCliente();
    int getDNI(){return dni;}
    void setIDCliente(int);
    bool grabarCliente();
    bool leerCliente(int );
    bool altaCliente();
    bool leerDiscoCliente(int );
    void listarPorIDCliente();
    void bajaCliente();
    bool modificarCliente(int);
    void modificarClienteNuevo();
    void listarCliente();
    int buscarCliente(int);


};
class Venta
{
private:
    int idVenta;
    int  idVendedor;
    char codigoProducto[10];
    int formaPago;
    float importe;
    int cantvendida;
    Fecha fechaVenta;
    int activo=0;
public:

    ///gets
    int getIDvendedor();
    bool getEstado();
    int getCantvendida();
    int getIDVenta();
    float getImporte();
    int getFormaPago();
    ///sets
    void setIDVenta(int);
    void setImporte(float);
    void setFormaPago(int);
    ///funciones
    bool altaventa();
    bool CargarVenta();
    void MostarVenta();
    bool grabarventa();
    void listarventa();
    void bajaVenta();
    void modificarVentaNuevo();
    bool leerDiscoVenta(int);
    void listarPorNumeroVenta();
    bool modificarVenta(int);
    int buscarVenta(int);
};
class Empleado
{
private:
    int idEmpleado;
    float sueldo;
    char nombre[40];
    char apellido[40];
    int dni;
    int nroTelefono;
    char  domicilio[50];
    Fecha nacimiento;
    char email[50];
    char genero[10];
    int activo=1;
public:
    void CargarEmpleado();
    void MostrarEmpleado();
    int getIDEmpleado();
    float getSueldo();
    void setIDEmpleado(int);
    void setSueldo(float);
    void *setNombre(const char);
    bool nuevoEmpleado();
    bool grabarEmpleado();
    bool altaEmpleado();
    bool leerdedisco(int);
    void eliminarEmpleado();
    void modificarEmpleado();
    void listarEmpleado();
    void buscarporCodigoEmpleado();
};
class Compra
{
private:
    char codProducto[10];
    int numProveedor;
    int cantIngresada;
    Fecha fechaDeCompra;
    Fecha fechaVencimientoPago;
    float importe;
    int formaPago;
    bool activo;
public:
    bool CargarCompra();
    void MostrarCompra();
    const char *getCodProducto();
    int getNumProveedor();
    int getCantIngresada();
    float getImporte();
    int getFormaPago();
    void setCodProducto(const char);
    void setNumProveedor(int);
    void setCantIngresada(int );
    void setImporte(float);
    void setFormaPago(int);
    void modificarCompraNuevo();
    int buscarCompra(char *);
    void bajaCompra();
    bool modificarCompra(int);
    void listarCompra();
    bool altaCompra();
    bool grabarCompra();
    bool leerDiscoCompra(int);
    void listarPorNumeroCompra();
};
#endif // TIPOS_H_INCLUDED
