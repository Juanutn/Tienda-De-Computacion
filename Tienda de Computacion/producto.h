#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include "colormenues.h"


bool Producto::nuevoproducto()
{
    textcolor(cNEGRO,cVERDE);
    cout<<"CÓDIGO DE PRODUCTO: ";
    cin.ignore();
    cin.getline(codigoProducto,10);
    if(strlen(codigoProducto)==0)
    {
        return false;
    }
    cout<<"NOMBRE: ";
    cin.getline(nombre,40);
    if(strlen(nombre)==0)
    {
        return false;
    }
    cout<<"PRECIO: ";
    cin>>precio;
    cout<<"STOCK: ";
    cin>>stock;
    cout<<"MARCA: ";
    cin>>codigoMarca;
    cout<<"CATEGORIA: ";
    cin>>codigoCategoriaProducto;
    activo=1;
    return true;

}
///GRABAR
bool Producto::grabarproducto()
{
    FILE *p;
    p=fopen("productos.dat", "ab");
    if(p==NULL)
        return false;
    bool escribio=fwrite(this, sizeof (Producto), 1, p);
    fclose(p);
    return escribio;
}
bool Producto::altaproducto()
{
    textcolor(cNEGRO,cVERDE);
    Producto a;
    if(a.nuevoproducto()==false) return false;



    if(a.grabarproducto()==true)
    {
        cout<<"PRODUCTO AGREGADO."<<endl;

    }
    else
    {
        cout<<"NO SE PUDO AGREGAR PRODUCTO."<<endl;

    }
    system("pause");
    system("cls");


}

///LISTAR

bool Producto::leerdedisco(int pos)
{
    textcolor(cNEGRO,cVERDE);
    FILE *p;
    p=fopen("productos.dat","rb");
    if(p==NULL)
        return false;
    fseek(p,sizeof *this *pos,0);
    bool leyo=fread(this,sizeof *this,1,p);
    fclose(p);
    return leyo;


}
void Producto::listarproducto()
{
    textcolor(cNEGRO,cVERDE);
    FILE *p;
    Producto a;
    int pos=0;
    p=fopen("productos.dat","rb");
    if(p==NULL)
        exit(1);
    while(a.leerdedisco(pos++))
    {
        a.mostrarproducto();
        cout<<endl;
        cout<<"-------------------"<<endl;
    }
    fclose(p);
}
void Producto::mostrarproducto()
{
    textcolor(cNEGRO,cVERDE);
    if(activo==1)
    {

    cout<<"CÓDIGO DE PRODUCTO:       ";
    cout<<codigoProducto<<endl;
    cout<<"NOMBRE:                   ";
    cout<<nombre<<endl;
    cout<<"PRECIO:                   ";
    cout<<precio<<endl;
    cout<<"STOCK:                    ";
    cout<<stock<<endl;
    cout<<"MARCA:                    ";
    cout<<codigoMarca<<endl;
    cout<<"CATEGORIA:                ";
    cout<<codigoCategoriaProducto<<endl;

    }
    else
    {
        cout<< "ESTE PRODUCTO SE ENCUENTRA SIN STOCK : "<<endl;
    }

}
///ELIMINAR

void Producto::eliminarproducto()
{
    textcolor(cNEGRO,cVERDE);
    FILE *p;
    char opcion;
    int pos=0;
    char d[10];
    Producto a;
    p=fopen("productos.dat","rb+");
    if(p==NULL)
        exit(1);
    cout<<" INGRESE CODIGO DE PRODUCTO A ELIMINAR: ";
    cin>>d;
    cout<<endl;
     while(a.leerdedisco(pos++))
    {
        if (strcmp(d,a.codigoProducto) == 0)
        {
            cout<< "¿DESEA ELIMINAR A ESTE PRODUCTO?: "<<endl;
            a.mostrarproducto();
            cout<<endl;
            cout<<"..........................."<<endl;
            cout<<" INGRESE S ( SI ) O N (NO):  " ;
            cin>> opcion;
            if (opcion=='s'||opcion=='S')
            {
                a.activo=0;

                cout<<" ELIMINADO CORRECTAMENTE "<<endl;
                fseek(p,ftell(p)-sizeof a,0);
                fwrite(this, sizeof (Producto), 1, p);
                fclose(p);
            }
            fclose(p);
            return;
        }

    }
    cout<< "NO SE ENCONTRO AL PRODUCTO ";
    fclose(p);


}
///BUSQUEDAS
void Producto::buscarporCodigoProducto()
{
    textcolor(cNEGRO,cVERDE);
    Producto a;
    char d[10];
    int pos=0;
    cout<<" INGRESE CODIGO DE PRODUCTO QUE QUIERE BUSCAR: ";
    cin>>d;
    cout<<endl;

    while(a.leerdedisco(pos++))
    {
        if (strcmp(d,a.codigoProducto) == 0)
        {
            a.mostrarproducto();
        }
        else
        {
            cout<<"este CODIGO no es de ningun producto actualmente "<<endl;

        }
    }

}




#endif // PRODUCTO_H_INCLUDED
