#ifndef COLORMENUES_H_INCLUDED
#define COLORMENUES_H_INCLUDED

enum Color
{
    cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15
};


void textcolor(short colorTexto=15, short colorFondo=0)
{
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

void gotoxy(short x, short y)  ///UBICA EL CURSOR EN LA POSICIÓN x,y DE LA PANTALLA
{
    HANDLE manipulador;
    COORD coordenadas;
    manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
    coordenadas.X= x;
    coordenadas.Y= y;
    SetConsoleCursorPosition(manipulador,coordenadas);
}


void MENUCOLORMAIN() ///muestra el punto en la pantalla en la posición que se eligió previamente
{
    textcolor(cNEGRO,cVERDE);
    gotoxy(35,4);
    cout<<"----------BIENVENIDO A HARD GAME------------"<<endl;
    gotoxy(35,5);
    cout<<endl;
    gotoxy(30,6);
    cout<<"----------PRECIONE UNA TECLA PARA CONTINUAR----------"<<endl;
    gotoxy(30,7);
    cout<<"[-> 1. PRODUCTO                                     |"<<endl;
    gotoxy(30,8);
    cout<<"[-> 2. PROVEEDOR                                    |"<<endl;
    gotoxy(30,9);
    cout<<"[-> 3. CLIENTE                                      |"<<endl;
    gotoxy(30,10);
    cout<<"[-> 4. VENTA                                        |"<<endl;
    gotoxy(30,11);
    cout<<"[-> 5. EMPLEADO                                     |"<<endl;
    gotoxy(30,12);
    cout<<"[-> 6. RECIBO DE COMPRA                             |"<<endl;
    gotoxy(30,13);
    cout<<"[-> 7. INFORME                                      |"<<endl;
    gotoxy(30,14);
    cout<<"[-> 8. CONFIGURACION                                |"<<endl;
    gotoxy(30,15);
    cout<<"[-> 0. SALIR DE PROGRAMA                            |"<<endl;
    gotoxy(30,16);
    cout<<"-----------------------------------------------------"<<endl;
}


void MENUCOLORCLIENTE() ///muestra el punto en la pantalla en la posición que se eligió previamente
{
        textcolor(cNEGRO,cVERDE);
    gotoxy(35,4);
    cout<<"============SUB MENU DE CLIENTE============"<<endl;
    gotoxy(35,5);
    cout<<endl;
    gotoxy(35,6);
    cout<<"--------------ELIJA UNA OPCION-------------"<<endl;
    gotoxy(35,7);
    cout<<"[-> 1. ALTA                               |"<<endl;
    gotoxy(35,8);
    cout<<"                                          |"<<endl;
    gotoxy(35,9);
    cout<<"[-> 2. BAJA                               |"<<endl;
    gotoxy(35,10);
    cout<<"                                          |"<<endl;
    gotoxy(35,11);
    cout<<"[-> 3. MODIFICAR                          |"<<endl;
    gotoxy(35,12);
    cout<<"                                          |"<<endl;
    gotoxy(35,13);
    cout<<"[-> 4. LISTADO                            |"<<endl;
    gotoxy(35,14);
    cout<<"                                          |"<<endl;
    gotoxy(35,15);
    cout<<"[-> 0. VOLVER AL MENU PRINCIPAL           |"<<endl;
    gotoxy(35,16);
    cout<<"-------------------------------------------"<<endl;
}



void MENUCOLORCONFIGURACION() ///muestra el punto en la pantalla en la posición que se eligió previamente
{

}

void MENUCOLOREMPLEADO() ///muestra el punto en la pantalla en la posición que se eligió previamente
{
    textcolor(cNEGRO,cVERDE);
    gotoxy(35,4);
    cout<<"============SUB MENU DE EMPLEADO============"<<endl;
    gotoxy(35,5);
    cout<<endl;
    gotoxy(35,6);
    cout<<"--------------ELIJA UNA OPCION--------------"<<endl;
    gotoxy(35,7);
    cout<<"[-> 1. ALTA                                |"<<endl;
    gotoxy(35,8);
    cout<<"                                           |"<<endl;
    gotoxy(35,9);
    cout<<"[-> 2. BAJA                                |"<<endl;
    gotoxy(35,10);
    cout<<"                                           |"<<endl;
    gotoxy(35,11);
    cout<<"[-> 3. MODIFICAR                           |"<<endl;
    gotoxy(35,12);
    cout<<"                                           |"<<endl;
    gotoxy(35,13);
    cout<<"[-> 4. LISTADO                             |"<<endl;
    gotoxy(35,14);
    cout<<"                                           |"<<endl;
    gotoxy(35,15);
    cout<<"[-> 0. VOLVER AL MENU PRINCIPAL            |"<<endl;
    gotoxy(35,16);
    cout<<"--------------------------------------------"<<endl;
}

void MENUCOLORINFORME() ///muestra el punto en la pantalla en la posición que se eligió previamente
{

}

void MENUCOLORPRODUCTO() ///muestra el punto en la pantalla en la posición que se eligió previamente
{
    textcolor(cNEGRO,cVERDE);
    gotoxy(35,4);
    cout<<"============SUB MENU DE PRODUCTO============"<<endl;
    gotoxy(35,5);
    cout<<endl;
    gotoxy(35,6);
    cout<<"--------------ELIJA UNA OPCION--------------"<<endl;
    gotoxy(35,7);
    cout<<"[-> 1. ALTA                                |"<<endl;
    gotoxy(35,8);
    cout<<"                                           |"<<endl;
    gotoxy(35,9);
    cout<<"[-> 2. BAJA                                |"<<endl;
    gotoxy(35,10);
    cout<<"                                           |"<<endl;
    gotoxy(35,11);
    cout<<"[-> 3. MODIFICAR                           |"<<endl;
    gotoxy(35,12);
    cout<<"                                           |"<<endl;
    gotoxy(35,13);
    cout<<"[-> 4. LISTADO                             |"<<endl;
    gotoxy(35,14);
    cout<<"                                           |"<<endl;
    gotoxy(35,15);
    cout<<"[-> 0. VOLVER AL MENU PRINCIPAL            |"<<endl;
    gotoxy(35,16);
    cout<<"--------------------------------------------"<<endl;
}

void MENUCOLORPROVEEDOR() ///muestra el punto en la pantalla en la posición que se eligió previamente
{
    textcolor(cNEGRO,cVERDE);
    gotoxy(35,4);
    cout<<"============SUB MENU DE PROVEEDOR============"<<endl;
    gotoxy(35,5);
    cout<<endl;
    gotoxy(35,6);
    cout<<"---------------ELIJA UNA OPCION--------------"<<endl;
    gotoxy(35,7);
    cout<<"[-> 1. ALTA                                 |"<<endl;
    gotoxy(35,8);
    cout<<"                                            |"<<endl;
    gotoxy(35,9);
    cout<<"[-> 2. BAJA                                 |"<<endl;
    gotoxy(35,10);
    cout<<"                                            |"<<endl;
    gotoxy(35,11);
    cout<<"[-> 3. MODIFICAR                            |"<<endl;
    gotoxy(35,12);
    cout<<"                                            |"<<endl;
    gotoxy(35,13);
    cout<<"[-> 4. LISTADO                              |"<<endl;
    gotoxy(35,14);
    cout<<"                                            |"<<endl;
    gotoxy(35,15);
    cout<<"[-> 0. VOLVER AL MENU PRINCIPAL             |"<<endl;
    gotoxy(35,16);
    cout<<"---------------------------------------------"<<endl;
}

void MENUCOLORVENTA() ///muestra el punto en la pantalla en la posición que se eligió previamente
{
    textcolor(cNEGRO,cVERDE);
    gotoxy(35,4);
    cout<<"============SUB MENU DE VENTA============"<<endl;
    gotoxy(35,5);
    cout<<endl;
    gotoxy(35,6);
    cout<<"-------------ELIJA UNA OPCION------------"<<endl;
    gotoxy(35,7);
    cout<<"[-> 1. ALTA                             |"<<endl;
    gotoxy(35,8);
    cout<<"                                        |"<<endl;
    gotoxy(35,9);
    cout<<"[-> 2. BAJA                             |"<<endl;
    gotoxy(35,10);
    cout<<"                                        |"<<endl;
    gotoxy(35,11);
    cout<<"[-> 3. MODIFICAR                        |"<<endl;
    gotoxy(35,12);
    cout<<"                                        |"<<endl;
    gotoxy(35,13);
    cout<<"[-> 4. LISTADO                          |"<<endl;
    gotoxy(35,14);
    cout<<"                                        |"<<endl;
    gotoxy(35,15);
    cout<<"[-> 0. VOLVER AL MENU PRINCIPAL         |"<<endl;
    gotoxy(35,16);
    cout<<"-----------------------------------------"<<endl;
}

void MENUCOLORCOMPRA() ///muestra el punto en la pantalla en la posición que se eligió previamente
{
        textcolor(cNEGRO,cVERDE);
    gotoxy(35,4);
    cout<<"============SUB MENU DE COMPRA============"<<endl;
    gotoxy(35,5);
    cout<<endl;
    gotoxy(35,6);
    cout<<"-------------ELIJA UNA OPCION-------------"<<endl;
    gotoxy(35,7);
    cout<<"[-> 1. ALTA                              |"<<endl;
    gotoxy(35,8);
    cout<<"                                         |"<<endl;
    gotoxy(35,9);
    cout<<"[-> 2. BAJA                              |"<<endl;
    gotoxy(35,10);
    cout<<"                                         |"<<endl;
    gotoxy(35,11);
    cout<<"[-> 3. MODIFICAR                         |"<<endl;
    gotoxy(35,12);
    cout<<"                                         |"<<endl;
    gotoxy(35,13);
    cout<<"[-> 4. LISTADO                           |"<<endl;
    gotoxy(35,14);
    cout<<"                                         |"<<endl;
    gotoxy(35,15);
    cout<<"[-> 0. VOLVER AL MENU PRINCIPAL          |"<<endl;
    gotoxy(35,16);
    cout<<"------------------------------------------"<<endl;
}


#endif // COLORMENUES_H_INCLUDED
