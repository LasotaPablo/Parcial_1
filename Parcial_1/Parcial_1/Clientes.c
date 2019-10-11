#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Clientes.h"
#include "utn.h"

static int crearID(void)
{
    static int ID = 0;
    ID++;
    return ID;
}
int initClientes(struct eClientes* aArray,int cantidad)
{
    int i;
    int retorno = -1;
    if(aArray != NULL && cantidad > 0)
    {
        for(i = 0; i<cantidad; i++)
        {
            aArray[i].status = STATUS_EMPTY;
        }
        retorno = 0;
    }
    return retorno;
}
int buscarLugarLibreClientes(struct eClientes *aArray, int cantidad)
{
	int retorno = -1;
	int i;
	if(aArray != NULL && cantidad > 0)
    {
        for(i=0;i<cantidad;i++)
        {
            if(aArray[i].status == STATUS_EMPTY)
            {
                retorno = i;
                break;
            }
		}
	}
	return retorno;
}
int altaClientesID(struct eClientes *aArray, int cantidad, struct eClientes item)
{
    int retorno = -1;
	int index;
    if(aArray != NULL && cantidad > 0)
    {
		index = buscarLugarLibreClientes(aArray, cantidad);
		if(index >= 0)
		{
			aArray[index] = item;
			aArray[index].status = STATUS_NOT_EMPTY;
			aArray[index].id = crearID();
			retorno = 0;
		}
	}
	return retorno;
}
int buscarClientesID(struct eClientes *aArray, int cantidad, int id)
{
    int i;
    int retorno = -1;
    if(aArray != NULL && cantidad > 0)
    {
        for(i = 0; i < cantidad; i++)
        {
            if(aArray[i].id == id && aArray[i].status == STATUS_NOT_EMPTY)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int altaClientes(struct eClientes *aArrays, int len)
{
	struct eClientes bClientes;
	int retorno = -1;
	if(buscarLugarLibreClientes(aArrays, len) != -1)
        {
            if(getString(bClientes.nombreEmpresa, "Ingrese el nombre: \n", "Error\n", 1, 49, 2) != -1)
            {
                if(getInt(&bClientes.CUITEmpresa, "Ingrese el CUIT: \n", "Error\n", 1, 10000000000, 2) != -1)
                {
                    if(getString(bClientes.direccionEmpresa, "Ingrese la direccion: \n", "Error\n", 0, 49, 2) != -1)
                    {
						if(getString(bClientes.localidadEmpresa, "Ingrese la localidad: \n", "Error\n", 1, 49, 2) != -1)
						{
							if (altaClientesID(aArrays, len, bClientes) == 0)
							{
								printf("ALTA EXITOSA!\n\n\n");
								retorno = 0; // OK
							}
						}
                    }
                }
            }
        }
    if(retorno!=0)
	{
		printf("Error al cargar datos\n");
	}
	return retorno;
}
int modificarClientesID(struct eClientes *aArray, int cantidad, struct eClientes item)
{
    int index;
    int retorno = -1;
    if(aArray != NULL && cantidad > 0)
    {
        index = buscarClientesID(aArray ,cantidad, item.id);
        if(index != -1)
        {
            aArray[index] = item;
            aArray[index].status = STATUS_NOT_EMPTY;
            retorno = 0;
        }
    }
    return retorno;
}
int modificarClientes(struct eClientes *aArray, int cantidad,int ID)
{
    struct eClientes bClientes;
    int retorno = -1;
    if (buscarClientesID(aArray, CANT_CLIENTES,ID) == -1)
    {
        printf("Error el id no existe\n");
        return retorno;
    }
    bClientes.id = ID;
    if (getString(bClientes.direccionEmpresa, "Ingrese la nueva direccion de la empresa: \n", "Error\n", 1, 49, 2) == -1)
    {
        printf("Error al ingresar la direccion.\n");
    }
    if (getString(bClientes.localidadEmpresa, "Ingrese la nueva localidad de la empresa: \n", "Error\n", 1, 49, 2) == -1)
    {
        printf("Error al ingresar la localidad.\n");
    }
    if(modificarClientesID(aArray,CANT_CLIENTES,bClientes) == -1)
    {
        printf("MODIFICACION EXITOSA!\n");
    }
    return retorno;
}
int imprimirClientes(struct eClientes *aArray, int cantidad)
{
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad > 0 )
	{
		retorno = 0;
		printf("id     Razon Social    C.U.I.T.    Direccion     Localidad\n");
		for(i = 0; i < cantidad; i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY){
				printf("%d ----- %s ------- %d ------- %s --------- %s \n",aArray[i].id,aArray[i].nombreEmpresa,aArray[i].CUITEmpresa,aArray[i].direccionEmpresa,aArray[i].localidadEmpresa);
			}

		}
	}
	return retorno;
}
int bajaClientesID(struct eClientes *aArray, int cantidad,int id)
{
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad > 0)
    {
		index = buscarClientesID(aArray, cantidad, id);
		if(index != -1)
        {
			aArray[index].status = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}
int bajaClientes(struct eClientes *aArray, int cantidad, int ID)
{
    int retorno = -1;
    char conf;
    if(bajaClientes(aArray,CANT_CLIENTES, ID) == -1)
    {
        printf("No existe el id\n");
        return retorno;
    }
    getChar(&conf,"¿Esta seguro que desea realizar esta baja?(s/n)\n","No es una respuesta valida(s/n)\n",'a','z',2);
    if(conf == 's')
    {
        if(bajaClientesID(aArray,CANT_CLIENTES,ID) == 0)
        {
            printf("BAJA EXITOSA!\n");
            retorno = 0;
        }
        else
        {
            printf("Error al dar la baja, verifique si el ID existe\n");
        }
    }
    return retorno;
}

