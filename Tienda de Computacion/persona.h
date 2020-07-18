#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "colormenues.h"



bool Persona::nuevapersona()
{
    textcolor(cNEGRO,cVERDE);
    cout<<"INGRESE NOMBRE: ";
    cin.ignore();
    cin.getline(nombre,40);
    if (strlen(nombre)==0)
    {
        return false;
    }
    cout<<"INGRESE APELLIDO: ";
    cin.getline(apellido,40);
    if (strlen(apellido)==0)
    {
        return false;
    }
    cout<<"INGRESE DNI: ";
    cin>>dni;
    cout<<"INGRESE NUMERO DE TELEFONO: ";
    cin>>nroTelefono;
    cout<<"INGRESE DOMICILIO: ";
    cin>>domicilio; ///modifique saque getline producia error
    cout<<"FECHA DE NACIMIENTO";
    cout<<endl;
    nacimiento.cargarfecha();
    cout<<"INGRESE EMAIL: ";
    cin.ignore();
    cin.getline(email,50);
    if(strlen(email)==0)
    {
        return false;
    }
    cout<<"INGRESE GENERO: ";
    cin.getline(genero,10);
    if(strlen(genero)==0)
    {
        return false;
    }
    activo=1;
    return true;

}
///GRABAR
bool Persona::grabarpersona()
{
    FILE *p;
    p=fopen("personas.dat", "ab");
    if(p==NULL)
        return false;
    bool escribio=fwrite(this, sizeof (Persona), 1, p);
    fclose(p);
    return escribio;
}
bool Persona::altapersona()
{
    textcolor(cNEGRO,cVERDE);
    Persona a;
    if(a.nuevapersona()==false)
        return false;
///VERIFICACION...
    if (a.dni>0)
    {

    }
    else
    {
        cout << "NO SE PUDO AGREGAR a la persona VERIFICACION DNI INCORRECTO"<<endl;
        system("pause");
        system("cls");
        return false;
    }


    if(a.grabarpersona()==true)
    {
        cout<<"PERSONA AGREGADA."<<endl;

    }
    else
    {
        cout<<"NO SE PUDO AGREGAR PERSONA."<<endl;

    }
    system("pause");
    system("cls");


}

///LISTAR

bool Persona::leerdedisco(int pos)
{
    FILE *p;
    p=fopen("personas.dat","rb");
    if(p==NULL)
        return false;
    fseek(p,sizeof *this *pos,0);
    bool leyo=fread(this,sizeof *this,1,p);
    fclose(p);
    return leyo;


}
void Persona::listarpersona()
{
    textcolor(cNEGRO,cVERDE);
    FILE *p;
    Persona a;
    int pos=0;
    p=fopen("personas.dat","rb");
    if(p==NULL)
        exit(1);
    while(a.leerdedisco(pos++))
    {
        a.mostrarpersona();
        cout<<endl;
        cout<<"-------------------"<<endl;
    }
    fclose(p);
}
void Persona::mostrarpersona()
{
    textcolor(cNEGRO,cVERDE);
    if(activo==1)
    {

        cout<<"NOMBRE:          ";
        cout<<nombre<<endl;
        cout<<"APELLIDO:          ";
        cout<<apellido<<endl;
        cout<<"NOMBRE:          ";
        cout<<nombre<<endl;
        cout<<"DNI:          ";
        cout<<dni<<endl;
        cout<<"NUMERO DE TELEFONO:          ";
        cout<<nroTelefono<<endl;
        cout<<"DOMICILIO:          ";
        cout<<domicilio<<endl;
        cout<<"FECHA DE NACIMIENTO"<<endl;
        cout<<nacimiento.getdia()<<"/"<<nacimiento.getmes()<<"/"<<nacimiento.getanio();
        cout<<"EMAIL:          ";
        cout<<email<<endl;
        cout<<"GENERO:          ";
        cout<<genero<<endl;
        system("pause");

    }
    else
    {
        cout<< "ESTA PERSONA SE ENCUENTRA DADO DE BAJA ACTUALMENTE : "<<endl;
    }

}
///ELIMINAR

void Persona::eliminarpersona()
{
    textcolor(cNEGRO,cVERDE);
    FILE *p;
    char opcion;
    int pos=0;
    int d;
    Persona a;
    p=fopen("personas.dat","rb+");
    if(p==NULL)
        exit(1);
    cout<<" INGRESE DNI DE PERSONA A ELIMINAR: ";
    cin>>d;
    cout<<endl;
    while(a.leerdedisco(pos++))
    {
        if(d==a.dni)
        {
            cout<< "¿DESEA ELIMINAR A ESTA PERSONA?: "<<endl;
            a.mostrarpersona();
            cout<<endl;
            cout<<"..........................."<<endl;
            cout<<" INGRESE S ( SI ) O N (NO):  " ;
            cin>> opcion;
            if (opcion=='s'||opcion=='S')
            {
                a.activo=0;

                cout<<" ELIMINADO CORRECTAMENTE "<<endl;
                fseek(p,ftell(p)-sizeof a,0);
                fwrite(this, sizeof (Persona), 1, p);
                fclose(p);
            }
            fclose(p);
            return;
        }

    }
    cout<< "NO SE ENCONTRO A LA PERSONA ";
    fclose(p);


}
///BUSQUEDAS
void Persona::buscarporDNI()
{
    textcolor(cNEGRO,cVERDE);
    Persona a;
    int d;
    int pos=0;
    cout<<" INGRESE DNI DE LA PERSONA QUE QUIERE BUSCAR: ";
    cin>>d;
    cout<<endl;

    while(a.leerdedisco(pos++))
    {
        if(d==a.dni)
        {
            a.mostrarpersona();

        }
        else
        {
            cout<<"este DNI no es de ninguna persona actualemte "<<endl;

        }
    }

}
#endif // PERSONA_H_INCLUDED
