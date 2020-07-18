#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED
#include "colormenues.h"

bool Compra::CargarCompra()
{
    textcolor(cNEGRO,cVERDE);
    cout<<"CODIGO DE PRODUCTO: ";
    cin>>codProducto;
    cout<<"NUMERO DE PROVEEDOR: ";
    cin>>numProveedor;
    cout<<"CANTIDAD INGRESADA: ";
    cin>>cantIngresada;
    cout<<"FECHA DE COMPRA"<<endl;
    cout<<"DIA/";
    cout<<"MES/";
    cout<<"AÑO:";
    cout<<fechaDeCompra.getdia()<<"/"<<fechaDeCompra.getmes()<<"/"<<fechaDeCompra.getanio();
    cout<<"FECHA DE VENCIMIENTO DEL PAGO"<<endl;
    cout<<"DIA/";
    cout<<"MES/";
    cout<<"AÑO:";
    cout<<fechaDeCompra.getdia()<<"/"<<fechaDeCompra.getmes()<<"/"<<fechaDeCompra.getanio();
    cout<<"IMPORTE: ";
    cin>>importe;
    cout<<"FORMA DE PAGO: ";
    cin>>formaPago;
    activo=true;
}
void Compra::MostrarCompra()
{
    textcolor(cNEGRO,cVERDE);
    cout<<"CODIGO DE PRODUCTO: ";
    cout<<codProducto<<endl;
    cout<<"NUMERO DE PROVEEDOR: ";
    cout<<numProveedor<<endl;
    cout<<"CANTIDAD INGRESADA: ";
    cout<<cantIngresada<<endl;
    cout<<"FECHA DE COMPRA"<<endl;
    cout<<"DIA:/";
    cout<<"MES:/";
    cout<<"AÑO:";
    cout<<fechaDeCompra.getdia()<<"/"<<fechaDeCompra.getmes()<<"/"<<fechaDeCompra.getanio();
    cout<<"FECHA DE VENCIMIENTO DEL PAGO"<<endl;
    cout<<"DIA:/";
    cout<<"MES:/";
    cout<<"AÑO:";
    cout<<fechaVencimientoPago.getdia()<<"/"<<fechaVencimientoPago.getmes()<<"/"<<fechaVencimientoPago.getanio();
    cout<<"IMPORTE: ";
    cout<<importe<<endl;
    cout<<"FORMA DE PAGO: ";
    cout<<formaPago<<endl;
}


bool Compra::leerDiscoCompra(int posicion)
{
    FILE *CO =fopen(COMPRA_CHAR,"rb");
    if(CO==NULL)
    {
        return false;
    }
    fseek(CO,sizeof *this *posicion,0);
    bool leyo=fread(this,sizeof *this,1,CO);
    fclose(CO);
    return leyo;
}

bool Compra::grabarCompra()
{
    FILE *CO;
    CO=fopen(COMPRA_CHAR, "ab");
    if(CO==NULL)
        return false;
    fwrite(this, sizeof (Venta), 1, CO);
    fclose(CO);
    return true;
}


bool Compra::altaCompra()
{
    textcolor(cNEGRO,cVERDE);
    Compra c;
    if(c.CargarCompra()==false) return false;

    if(c.grabarCompra()==true)
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


void Compra::listarCompra()
{
    textcolor(cNEGRO,cVERDE);
    FILE *CO;
    Compra c;
    int pos=0;
    CO=fopen(COMPRA_CHAR,"rb");
    if(CO==NULL)
        exit(1);
    while(c.leerDiscoCompra(pos++))
    {
        if(c.activo==1){
        c.MostrarCompra();
        cout<<endl;
        cout<<"-------------------"<<endl;
        }
    }
    fclose(CO);
}

bool Compra::modificarCompra(int posicion)
{
    FILE *CO=fopen(COMPRA_CHAR,"rb+");
    if(CO==NULL)
    {
        return false;
    }
    fseek(CO,sizeof(Compra)*posicion,0);
    bool escribio=fwrite(this, sizeof (Compra), 1, CO);
    fclose(CO);
    return escribio;
}

void Compra::bajaCompra()
{
    textcolor(cNEGRO,cVERDE);
    FILE *CO=fopen(COMPRA_CHAR,"rb+");
    char opcion;
    int pos=0;
    char aux[10];
    Compra c;
    if(CO==NULL)
    {
        exit(1);
    }
    cout<<" INGRESE EL CODIGO DE COMPRA A ELIMINAR: ";
    cin>>aux;
    cout<<endl;
    while(c.leerDiscoCompra(pos++))
    {
        if (aux==c.codProducto)
        {
            cout<< "¿DESEA ELIMINAR A ESTE CODIGO DE VENTA?: "<<endl;
            c.MostrarCompra();
            cout<<endl;
            cout<<"..........................."<<endl;
            cout<<" INGRESE S ( SI ) O N (NO):  " ;
            cin>> opcion;
            if (opcion=='s'||opcion=='S')
            {
                c.activo=false;
                cout<<" ELIMINADO CORRECTAMENTE "<<endl;
                fseek(CO,ftell(CO)-sizeof c,0);
                fwrite(this, sizeof (Compra), 1, CO);
                fclose(CO);
            }
            fclose(CO);
            return;
        }
    }
    cout<< "NO SE ENCONTRO EL CODIGO DE COMPRA";
    fclose(CO);
}

void Compra::listarPorNumeroCompra()
{
    textcolor(cNEGRO,cVERDE);
    Compra c;
    char aux[10];
    int pos=0;
    cout<<" INGRESE CODIGO DE COMPRA QUE QUIERE BUSCAR: ";
    cin>>aux;
    cout<<endl;
    while(c.leerDiscoCompra(pos++))
    {
        if (aux==c.codProducto)
        {
         c.MostrarCompra();
        }
        else
        {
            cout<<"NO HAY NINGUNA COMPRA CON ESTE CODIGO "<<endl;
        }
    }
}

int Compra::buscarCompra(char *idCompraNuevoAux)
{
    int pos=0;
    Compra c;
    while(c.leerDiscoCompra(pos)==1)
    {
        if (strcmp(idCompraNuevoAux,c.codProducto)==0)
        {
            return pos;
            pos++;
        }
    }
    return -1;
}

void Compra::modificarCompraNuevo()
{
    textcolor(cNEGRO,cVERDE);
    char *idcompraAux;
    int pos;
    Compra c;
    cout<<"INGRESE EL CODIGO DE COMPRA QUE DESEA MODIFICAR: ";
    cin>>idcompraAux;
    pos=buscarCompra(idcompraAux);
    if(pos!=-1)
    {
        c.leerDiscoCompra(pos);
        CargarCompra();
        c.modificarCompra(pos);
    }
    else
    {
        cout<<"NO EXISTE EL CODIGO DE COMPRA"<<endl;
    }
}

#endif // COMPRA_H_INCLUDED
