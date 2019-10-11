#include "Clientes.h"
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct ePedidos
{
	int id;
	int kilos;
	char estadoDelPedido[49];
	int status;
	int idClientes;
}

int initPedidos(struct ePedidos *aArray, int cantidad);
int buscarLugarLibrePedidos(struct ePedidos *aArray, int cantidad);
int altaPedidosPorIdClientes(struct ePedidos *aArray, int cantidad, struct eClientes.id item);
