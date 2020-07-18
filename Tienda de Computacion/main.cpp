#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <clocale>
using namespace std;
const char *PROVEEDOR_CHAR="proveedor.dat";
const char *CLIENTE_CHAR="cliente.dat";
const char *VENTAS_CHAR="ventas.dat";
const char *COMPRA_CHAR="compras.dat";
const char *EMPLEADO_CHAR="empleado.dat";
#include "tipos.h"
#include "prototipos.h"
#include "producto.h"
#include "proveedor.h"
#include "cliente.h"
#include "venta.h"
#include "empleado.h"
#include "compra.h"
#include "informe.h"
#include "configuracion.h"
#include "subMenus.h"
#include "colormenues.h"
#include "persona.h"
int main()
{
    system("color 24");
    setlocale(LC_CTYPE,"Spanish");
    int opcion;
    while (true)
    {
        system("cls");
        MENUCOLORMAIN();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            subMenuProducto();
            break;
        case 2:
            subMenuProveedor();
            break;
        case 3:
            subMenuCliente();
            break;
        case 4:
            subMenuVenta();
            break;
        case 5:
            subMenuEmpleado();
            break;
        case 6:
            subMenuCompra();
            break;
        case 7:
            break;
        case 8:
            break;
        case 0:
            cout<<"GRACIAS POR USAR EL PROGRAMA QUE TENGA UN BUEN DIA"<<endl;
            return 0;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}
