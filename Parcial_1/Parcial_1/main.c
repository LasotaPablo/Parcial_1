#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"
#include "utn.h"

int main()
{
    struct eClientes aClientes[CANT_CLIENTES];
    int opcion;
    int ID;
    initClientes(aClientes,CANT_CLIENTES);
    do
    {
        printf("-------------------------------\n\n"
               "¿Que accion deseea realizar?\n\n"
               "1.Alta de una nuevo cliente\n"
               "2.Modificar un la direccion y localidad de un cliente\n"
               "3.Dar de baja a un cliente\n"
               "4.Mostrar la lista de clientes e ingresar pedido de recolecicion\n"
               "0.Salir\n\n"
               "-------------------------------\n");
        getInt(&opcion,"Ingrese un numero: ","Error\n",0,9,2);
        switch(opcion)
        {
        case 1:
            altaClientes(aClientes,CANT_CLIENTES);
            break;
        case 2:
            getInt(&ID,"Ingrese el id para modificar\n","Error\n",0,100000,2);
            modificarClientes(aClientes,CANT_CLIENTES,ID);
            break;
        case 3:
   			getInt(&ID,"Ingrese el id para dar de baja\n","Error\n",0,100000,2);
   			bajaClientes(aClientes,CANT_CLIENTES,ID);
   			break;
        case 4:
            imprimirClientes(aClientes,CANT_CLIENTES);
            break;
        default:
            printf("Precione enter para salir del programa\n");
            break;
        }

    }while(opcion < 5 && opcion > 0);
}
