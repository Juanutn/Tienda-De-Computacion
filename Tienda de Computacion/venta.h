#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "colormenues.h"


bool Venta::CargarVenta()
{
textcolor(cNEGRO,cVERDE);
    cout<<"ID VENTA: ";
    cin>>idVenta;
        cout<<"ID VENDEDOR: ";
        cin>>idVendedor;
        cout<<"CODIGO DE PRODUCTO: ";
        cin>>codigoProducto;
        cout<<"FORMA DE PAGO: ";
        cin>>formaPago;
        cout<<"IMPORTE: ";
        cin>>importe;
        cout<<"CANTIDAD VENDIDA: ";
        cin>>cantvendida;
        cout<<"FECHA DE VENTA "<<endl;
        cout<<"DIA/ ";
        cout<<"MES/ ";
        cout<<"AÑO: "<<endl;
        fechaVenta.cargarfecha();
        activo=1;

        return true;
}

bool Venta::leerDiscoVenta(int posicion)
{
    FILE *VE =fopen("ventas.dat","rb");
    if(VE==NULL)
    {
        return false;
    }
    fseek(VE,sizeof *this *posicion,0);
    bool leyo=fread(this,sizeof *this,1,VE);
    fclose(VE);
    return leyo;
}

bool Venta::grabarventa()
{
    FILE *v;
    v=fopen("ventas.dat", "ab");
    if(v==NULL)
        return false;
    fwrite(this, sizeof (Venta), 1, v);
    fclose(v);
    return true;
}


bool Venta::altaventa()
{
    textcolor(cNEGRO,cVERDE);
    Venta v;
    if(v.CargarVenta()==false) return false;

    if(v.grabarventa()==true)
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

void Venta::MostarVenta()
{
    textcolor(cNEGRO,cVERDE);
    cout<<"ID VENTA: ";
    cout<<idVenta<<endl;
        cout<<"ID VENDEDOR: ";
        cout<<idVendedor<<endl;
        cout<<"CODIGO DE PRODUCTO: ";
        cout<<codigoProducto<<endl;
        cout<<"FORMA DE PAGO: ";
        cout<<formaPago<<endl;
        cout<<"IMPORTE: ";
        cout<<importe<<endl;
        cout<<"CANTIDAD VENDIDA: ";
        cout<<cantvendida<<endl;
        cout<<"FECHA DE VENTA: ";
        cout<<fechaVenta.getdia()<<"/"<<fechaVenta.getmes()<<"/"<<fechaVenta.getanio();
        system("pause");
}

void Venta::listarventa()
{
    FILE *V;
    Venta ve;
    int pos=0;
    V=fopen("ventas.dat","rb");
    if(V==NULL)
        exit(1);
    while(ve.leerDiscoVenta(pos++))
    {
        if(ve.activo==1){
        ve.MostarVenta();
        cout<<endl;
        cout<<"-------------------"<<endl;
        }
    }
    fclose(V);
}

bool Venta::modificarVenta(int posicion)
{
    FILE *VE=fopen(VENTAS_CHAR,"rb+");
    if(VE==NULL)
    {
        return false;
    }
    fseek(VE,sizeof(Venta)*posicion,0);
    bool escribio=fwrite(this, sizeof (Venta), 1, VE);
    fclose(VE);
    return escribio;
}

void Venta::bajaVenta()
{
    textcolor(cNEGRO,cVERDE);
    FILE *VE =fopen(VENTAS_CHAR,"rb+");
    char opcion;
    int pos=0;
    int aux;
    Venta v;
    if(VE==NULL)
    {
        exit(1);
    }
    cout<<" INGRESE EL ID VENTA A ELIMINAR: ";
    cin>>aux;
    cout<<endl;
    while(v.leerDiscoVenta(pos++))
    {
        if (aux==v.idVenta)
        {
            cout<< "¿DESEA ELIMINAR A ESTE ID DE VENTA?: "<<endl;
            v.MostarVenta();
            cout<<endl;
            cout<<"..........................."<<endl;
            cout<<" INGRESE S ( SI ) O N (NO):  " ;
            cin>> opcion;
            if (opcion=='s'||opcion=='S')
            {
                v.activo=false;
                cout<<" ELIMINADO CORRECTAMENTE "<<endl;
                fseek(VE,ftell(VE)-sizeof v,0);
                fwrite(this, sizeof (Venta), 1, VE);
                fclose(VE);
            }
            fclose(VE);
            return;
        }
    }
    cout<< "NO SE ENCONTRO AL ID DE LA VENTA";
    fclose(VE);
}

void Venta::listarPorNumeroVenta()
{
    textcolor(cNEGRO,cVERDE);
    Venta v;
    int aux;
    int pos=0;
    cout<<" INGRESE ID CLIENTE QUE QUIERE BUSCAR: ";
    cin>>aux;
    cout<<endl;
    while(v.leerDiscoVenta(pos++))
    {
        if (aux==v.idVenta)
        {
            v.MostarVenta();
        }
        else
        {
            cout<<"NO HAY NINGUN ID CLIENTE"<<endl;
        }
    }
}

int Venta::buscarVenta(int idVentaNuevoAux)
{
    int pos=0;
    Venta v;
    while(v.leerDiscoVenta(pos)==1)
    {
        if (idVentaNuevoAux== v.idVenta)
        {
            return pos;
            pos++;
        }
    }
    return -1;
}

void Venta::modificarVentaNuevo()
{
    textcolor(cNEGRO,cVERDE);
    int idventaAux;
    int pos;
    Venta v;
    cout<<"INGRESE EL ID CLIENTE QUE DESEA MODIFICAR: ";
    cin>>idVenta;
    pos=buscarVenta(idventaAux);
    if(pos!=-1)
    {
        v.leerDiscoVenta(pos);
        CargarVenta();
        v.modificarVenta(pos);
    }
    else
    {
        cout<<"NO EXISTE EL ID CLIENTE"<<endl;
    }
}

#endif // VENTA_H_INCLUDED
