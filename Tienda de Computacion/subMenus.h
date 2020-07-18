#ifndef SUBMENUS_H_INCLUDED
#define SUBMENUS_H_INCLUDED
#include "colormenues.h"
void subMenuProducto()
{
    int opcion;
    while (true)
    {
        system("cls");
        MENUCOLORVENTA();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}
void subMenuProveedor()
{
    Proveedor reg;
    int opcion;
    while (true)
    {
        system("cls");
        MENUCOLORPROVEEDOR();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            reg.altaProveedor();
            break;
        case 2:
            reg.bajaProveedor();
            break;
        case 3:
            reg.modificarProveedorNuevo();
            break;
        case 4:
            reg.listarProveedor();
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}
void subMenuCliente()
{
    Cliente aux;
    int opcion;
    while (true)
    {
        system("cls");
        MENUCOLORCLIENTE();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            aux.altaCliente();
            break;
        case 2:
            aux.bajaCliente();
            break;
        case 3:
            aux.modificarClienteNuevo();
            break;
        case 4:
            aux.listarCliente();
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}
void subMenuVenta()
{
    int opcion;
    while (true)
    {
        system("cls");
        MENUCOLORVENTA();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}
void subMenuEmpleado()
{
    int opcion;
    while (true)
    {
        system("cls");
        MENUCOLOREMPLEADO();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}
void subMenuCompra()
{
    int opcion;
    while (true)
    {
        system("cls");
        MENUCOLORCOMPRA();
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            cout<<"VOLVIENDO AL MENU PRINCIPAL"<<endl;
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA POR FAVOR VUELVA INTRODUCCIR LA OPCION CORRECTA EN PANTALLA"<<endl;
            break;
        }
        system("pause");
    }
}
#endif // SUBMENUS_H_INCLUDED
