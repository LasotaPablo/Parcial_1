#define CANT_CLIENTES 100
#define CANT_CARAC 49
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct eClientes
{
    int id;
    char nombreEmpresa[CANT_CARAC];
    int CUITEmpresa;
    char direccionEmpresa[CANT_CARAC];
    char localidadEmpresa[CANT_CARAC];
    int status;
};

int initClientes(struct eClientes* aArray,int cantidad);
int altaClientesID(struct eClientes *aArray, int cantidad, struct eClientes item);
int buscarLugarLibreClientes(struct eClientes *aArray, int cantidad);
int altaClientes(struct eClientes *aArray,int len);
int modificarClientesID(struct eClientes *aArray, int cantidad, struct eClientes item);
int buscarClientesID(struct eClientes *aArray, int cantidad, int id);
int modificarClientes(struct eClientes *aArray, int cantidad,int ID);
int imprimirClientes(struct eClientes *aArray, int cantidad);
int bajaClientesID(struct eClientes *aArray, int cantidad,int id);
int bajaClientes(struct eClientes *aArray, int cantidad, int ID);


