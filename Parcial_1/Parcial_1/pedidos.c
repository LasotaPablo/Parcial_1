

int initPedidos(struct ePedidos *aArray, int cantidad)
{
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad > 0){
		for(i=0;i<cantidad;i++){
			aArray[i].status = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}
int buscarLugarLibrePedidos(struct ePedidos *aArray, int cantidad)
{
	int retorno = -1;
	int i;
	if(aArray != NULL && cantidad > 0){
		for(i=0;i<cantidad;i++){
			if(aArray[i].status == STATUS_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaPedidosPorIdClientes(struct ePedidos *aArray, int cantidad, struct ePedidos buffer,struct eClientes.id item)
{
	int retorno = -1;
	int index;
	if(aArray != NULL && cantidad > 0)
	{
		index = buscarLugarLibrePedidos(aArray,cantidad);
		if(index >= 0)
		{
			aArray[index] = buffer;
			aArray[index].status = STATUS_NOT_EMPTY;
			aArray[index].id =
		}
	}
}
