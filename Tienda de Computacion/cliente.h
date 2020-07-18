#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "colormenues.h"

bool Cliente::CargarCliente()
{
    textcolor(cNEGRO,cVERDE);
    cout<<"ID CLIENTE: ";
    cin>>idCliente;
    cout<<"NOMBRE: ";
    cin.ignore();
    cin.getline(nombre,40);
    if (strlen(nombre)==0)
    {
        return false;
    }
    cout<<"APELLIDO: ";
    cin.getline(apellido,40);
    if (strlen(apellido)==0)
    {
        return false;
    }
    cout<<"DNI: ";
    cin>>dni;
    cout<<"NÚMERO DE TELEFONO: ";
    cin>>nroTelefono;
    cout<<"EMAIL: ";
    cin.ignore();
    cin.getline(email,50);
    if (strlen(email)==0)
    {
        return false;
    }
    cout<<"DOMICILIO: ";
    cin.getline(domicilio,50);
    if (strlen(domicilio)==0)
    {
        return false;
    }
    activo=true;
    return true;
}

bool Cliente::grabarCliente()
{
    FILE *archivo_cliente=fopen(CLIENTE_CHAR, "ab");
    if(archivo_cliente==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this, sizeof (Cliente), 1, archivo_cliente);
    fclose(archivo_cliente);
    return escribio;
}

bool Cliente::altaCliente()
{
    textcolor(cNEGRO,cVERDE);
    Cliente a;

    if(a.CargarCliente()==true)
    {
        if(a.grabarCliente()==true){
            cout <<"ID CLIENTE AGREGADO"<<endl;
        }
    }

    else
    {
        cout<<"NO SE PUDO AGREGAR ID CLIENTE."<<endl;
    }
}
bool Cliente::leerDiscoCliente(int posicion)
{
    FILE *archivo_cliente=fopen(CLIENTE_CHAR,"rb");
    if(archivo_cliente==NULL)
    {
        return false;
    }
    fseek(archivo_cliente,sizeof *this *posicion,0);
    bool leyo=fread(this,sizeof *this,1,archivo_cliente);
    fclose(archivo_cliente);
    return leyo;
}
void Cliente::listarCliente()
{
    textcolor(cNEGRO,cVERDE);
    FILE *archivo_cliente=fopen(CLIENTE_CHAR,"rb");
    Cliente a;
    int pos=0;
    if(archivo_cliente==NULL)
    {
        exit(1);
    }
    while(a.leerDiscoCliente(pos++))
    {
        a.MostrarCliente();
        cout<<endl;
        cout<<"-------------------"<<endl;
    }
    fclose(archivo_cliente);
}

void Cliente::MostrarCliente()
{
    textcolor(cNEGRO,cVERDE);
    if (activo==true)
    {
        cout<<"ID CLIENTE: ";
        cout<<idCliente<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"APELLIDO: ";
        cout<<apellido<<endl;
        cout<<"DNI: ";
        cout<<dni<<endl;
        cout<<"NÚMERO DE TELEFONO: ";
        cout<<nroTelefono<<endl;
        cout<<"EMAIL: ";
        cout<<email<<endl;
        cout<<"DOMICILIO: ";
        cout<<domicilio<<endl;
    }
}

void Cliente::bajaCliente()
{
    textcolor(cNEGRO,cVERDE);
    FILE *archivo_cliente=fopen(CLIENTE_CHAR,"rb+");
    char opcion;
    int pos=0;
    int aux;
    Cliente a;
    if(archivo_cliente==NULL)
    {
        exit(1);
    }
    cout<<" INGRESE EL ID CLIENTE A ELIMINAR: ";
    cin>>aux;
    cout<<endl;
    while(a.leerDiscoCliente(pos++))
    {
        if (aux==a.idCliente)
        {
            cout<< "¿DESEA ELIMINAR A ESTE ID CLIENTE?: "<<endl;
            a.MostrarCliente();
            cout<<endl;
            cout<<"..........................."<<endl;
            cout<<" INGRESE S ( SI ) O N (NO):  " ;
            cin>> opcion;
            if (opcion=='s'||opcion=='S')
            {
                a.activo=false;
                cout<<" ELIMINADO CORRECTAMENTE "<<endl;
                fseek(archivo_cliente,ftell(archivo_cliente)-sizeof a,0);
                fwrite(this, sizeof (Cliente), 1, archivo_cliente);
                fclose(archivo_cliente);
            }
            fclose(archivo_cliente);
            return;
        }
    }
    cout<< "NO SE ENCONTRO AL ID CLIENTE";
    fclose(archivo_cliente);
}
void Cliente::listarPorIDCliente()
{
    textcolor(cNEGRO,cVERDE);
    Cliente a;
    int aux;
    int pos=0;
    cout<<" INGRESE ID CLIENTE QUE QUIERE BUSCAR: ";
    cin>>aux;
    cout<<endl;
    while(a.leerDiscoCliente(pos++))
    {
        if (aux==a.idCliente)
        {
            a.MostrarCliente();
        }
        else
        {
            cout<<"NO HAY NINGUN ID CLIENTE"<<endl;
        }
    }
}
bool Cliente::modificarCliente(int posicion)
{
    FILE *archivo_cliente=fopen(CLIENTE_CHAR,"rb+");
    if(archivo_cliente==NULL)
    {
        return false;
    }
    fseek(archivo_cliente,sizeof*this*posicion,0);
    bool escribio=fwrite(this, sizeof*this, 1, archivo_cliente);
    fclose(archivo_cliente);

}
int Cliente::buscarCliente(int idClienteNuevoAux)
{
    int pos=0;
    Cliente a;
    while(a.leerDiscoCliente(pos)==1)
    {
        if (idClienteNuevoAux==a.idCliente)
        {
            return pos;

        }
        pos++;
    }
    return -1;
}
void Cliente::modificarClienteNuevo()
{
    textcolor(cNEGRO,cVERDE);
    int idClienteNuevoAux;
    int pos;
    Cliente a;
    cout<<"INGRESE EL ID CLIENTE QUE DESEA MODIFICAR: ";
    cin>>idClienteNuevoAux;
    pos=buscarCliente(idClienteNuevoAux);
    if(pos!=-1)
    {

        a.CargarCliente();
        a.modificarCliente(pos);
    }
    else
    {
        cout<<"NO EXISTE EL ID CLIENTE"<<endl;
    }
}
#endif // CLIENTE_H_INCLUDED
