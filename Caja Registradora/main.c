#include <stdio.h>
#include <stdlib.h>

/**
 * 
 *      LAS GLOVALES
 * 
 */

int cantUs = -1;




/**

 *      FUNCIONES DE PRODUCTOS

*/

typedef struct{             // PRODUCTOS
    int codigo;
    char nombre[15];
    int cantidad;
    float precio;
    struct nodo *sig;
    struct nodo *ant;
} nodo;

nodo *raiz = NULL;

int existe(int x)
{
     nodo *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == x)
            return 1;
        reco = reco->sig;
    }
    return 0;
}

int cantidadpro()
{
    nodo *reco = raiz;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}

void insertarpro( char nombrep[15], int cantidadp, float preciop ) 
{
    static int x = 0;
    x++;
    int pos = cantidadpro()+1;
    if(!existe(x)){
        if (pos <= cantidadpro() + 1)
        {
            nodo *nuevo;
            nuevo=malloc(sizeof(nodo));
            nuevo->codigo = x;
            strcpy(nuevo->nombre, nombrep);
            nuevo->cantidad = cantidadp;
            nuevo->precio = preciop;
            nuevo->ant=NULL;
            nuevo->sig=NULL;

            if (pos == 1)
            {
                nuevo->sig = raiz;
                if (raiz != NULL)
                    raiz->ant = nuevo;
                raiz = nuevo;
            }
            else
            {
                if (pos == cantidadpro() + 1)
                {
                    nodo *reco = raiz;
                    while (reco->sig != NULL)
                    {
                        reco = reco->sig;
                    }
                    reco->sig = nuevo;
                    nuevo->ant = reco;
                }
                else
                {
                    nodo *reco = raiz;
                    int f;
                    for (f = 1; f <= pos - 2; f++)
                        reco = reco->sig;
                    nodo *siguiente = reco->sig;
                    reco->sig = nuevo;
                    nuevo->ant = reco;

                    nuevo->sig = siguiente;
                    siguiente->ant = nuevo;
                }
            }
        }
    }
}

void imprimirpro()
{
    nodo *reco=raiz;
    while (reco!=NULL)
    {
        printf("\n\n*********************************\n");
        printf("<<<<<<<<<<  %s  >>>>>>>>>>>\n",reco->nombre);
        printf("\t codigo : %i \n",reco->codigo);
        printf("\t precio : %f \n",reco->precio);
        printf("\n\n");
        reco=reco->sig;
    }
    printf("\n");
}

int descontarProducto(int x, int cant)
{
     nodo *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == x)
        {
            if(reco->cantidad >= cant)
            {
                reco->cantidad -= cant;
                return 1;
            }else
                return 0;
        }
        reco = reco->sig;
    }
    return 0;
}

const char* codNombreProduct(int cod)
{
     nodo *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == cod)
            return reco->nombre;
        else
            reco = reco->sig;
    }
    return 0;
}

int precioProduct(int cod)
{
     nodo *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == cod)
            return reco->precio;
        else
            reco = reco->sig;
    }
    return 0;
}




/**
 *
 *      FUNCIONES DE USUARIO
 *
 */

typedef struct{             // USUARIOS
    int codigoUsu;            
    char nombreUs[15];
    char cedulaUs[15];
    struct usuarios *sig;
    struct usuarios *ant;
}usuarios;

usuarios *raizUsu = NULL;
usuarios *nombreClienActu = NULL;


int existeUsu(int x){
    usuarios *recousu = raizUsu;
    while (recousu != NULL)
    {
        if (recousu->codigoUsu == x)
            return 1;
        recousu = recousu->sig;
    }
    return 0;
}

int vaciausu(){
    if (raizUsu == NULL)
        return 1;
    else
        return 0;
}

int cantidadusu()
{
    usuarios *recousu = raizUsu;
    int cant = 0;
    while (recousu != NULL)
    {
        cant++;
        recousu = recousu->sig;
    }
    return cant;
}

void insertarusu( char nombreusu[15], char cedula[15] )
{
    static int codigo = 0;
    codigo++;
    int pos = cantidadusu()+1;
    if(!existeUsu(codigo)){
        if (pos <= cantidadusu() + 1)
        {
            usuarios *nuevo;
            nuevo=malloc(sizeof(usuarios));
            nuevo->codigoUsu = codigo;
            strcpy(nuevo->nombreUs, nombreusu);
            strcpy(nuevo->cedulaUs, cedula);
            nuevo->ant=NULL;
            nuevo->sig=NULL;

            if (pos == 1)
            {
                nuevo->sig = raizUsu;
                if (raizUsu != NULL)
                    raizUsu->ant = nuevo;
                raizUsu = nuevo;
            }
            else
            {
                if (pos == cantidadusu() + 1)
                {
                    usuarios *reco = raizUsu;
                    while (reco->sig != NULL)
                    {
                        reco = reco->sig;
                    }
                    reco->sig = nuevo;
                    nuevo->ant = reco;
                }
                else
                {
                    usuarios *reco = raizUsu;
                    int f;
                    for (f = 1; f <= pos - 2; f++)
                        reco = reco->sig;
                    usuarios *siguiente = reco->sig;
                    reco->sig = nuevo;
                    nuevo->ant = reco;
                    nuevo->sig = siguiente;
                    siguiente->ant = nuevo;
                }
            }
            
        nombreClienActu = &nuevo;
        printf("PRIMERA :%p \n", &nuevo);
        }
    }
}

void imprimirUsu()
{
    usuarios *recous=raizUsu;
    while (recous!=NULL)
    {
        printf("\n\n*********************************\n");
        printf("<<<<<<<<<<  %s  >>>>>>>>>>>\n",recous->nombreUs);
        printf("\t cedula : %i \n",recous->cedulaUs);
        printf("\t cod : %i \n",recous->codigoUsu);
        printf("\n\n");
        recous=recous->sig;
    }
    printf("\n");
}

//usuarios *usuPedidos = NULL;

void imprimirUsuespe()
{
    //nombreClienActu =malloc(sizeof(usuarios));
    //usuarios *recous = usuPedidos;
        printf("\n*********************************\n");
        printf("\t nombre \t cedula \t codigo\n");
        printf("%s \t %s \t %i\n\n",nombreClienActu->nombreUs ,nombreClienActu->cedulaUs ,nombreClienActu->codigoUsu);
}




/**
 *
 *      FUNCIONES DE PEDIDO
 *
 */

typedef struct{             // STRUCT PEDIDOS
    int codigoPedido; 
    struct usuarios *usuarioP;
    char nombreP[15];
    int cantidadproducts;
    float valorC;
    struct pedidos *sig;
    struct pedidos *ant;
}pedidos[50];

pedidos *raizPed = NULL;


int existePedido(int x, int pos)
{
    pedidos *recoped = raizPed;
    while (recoped != NULL)
    {
        if (recoped[pos]->codigoPedido == x)
            return 1;
        recoped = recoped[pos]->sig;
    }
    return 0;
}

int vaciaped()
{
    if (raizPed == NULL)
        return 1;
    else
        return 0;
}

int cantidadPed(int pos)
{
    pedidos *recoped = raizPed;
    int cant = 0;
    while (recoped[pos] != NULL)
    {
        cant++;
        recoped = recoped[pos]->sig;
    }
    return cant;
}

void insertarPedido( int pos, char nombreProd[15] , int cantProd, float valor)
{
    static int codigo = 0;
    codigo++;

    int posi = cantidadPed(pos)+1;
    if(!existePedido(codigo, pos)){
        if (posi <= cantidadPed(pos) + 1)
        {
            pedidos *nuevo;
            nuevo=malloc(sizeof(pedidos));
            nuevo[pos]->codigoPedido = codigo;
            nuevo[pos]->usuarioP = nombreClienActu;
            strcpy(nuevo[pos]->nombreP , nombreProd);
            nuevo[pos]->cantidadproducts = cantProd;
            nuevo[pos]->valorC = valor;
            nuevo[pos]->ant=NULL;
            nuevo[pos]->sig=NULL;

            if (posi == 1)
            {
                nuevo[pos]->sig = raizPed;
                if (raizPed != NULL)
                    raizPed[pos]->ant = nuevo;
                raizPed = nuevo;
            }
            else
            {
                if (posi == cantidadPed(pos) + 1)
                {
                    pedidos *reco = raizPed;
                    while (reco[pos]->sig != NULL)
                    {
                        reco = reco[pos]->sig;
                    }
                    reco[pos]->sig = nuevo;
                    nuevo[pos]->ant = reco;
                    
                }
                else
                {
                    pedidos *reco = raizPed;
                    int f;
                    for (f = 1; f <= posi - 2; f++)reco = reco[pos]->sig;

                    pedidos *siguiente = reco[pos]->sig;
                    reco[pos]->sig = nuevo;
                    nuevo[pos]->ant = reco;
                    nuevo[pos]->sig = siguiente;
                    siguiente[pos]->ant = nuevo;
                }
            }
        }
    }
}

void imprimirPedi()
{
    pedidos *reco = raizPed;
    for (int i = 0; i < cantUs+1; i++)
    {
        printf("\n*********************************\n");
        printf("<<<<<<<<<<  pedido N:%i  >>>>>>>>>>>\n",reco[i]->codigoPedido);
        printf("------>>> %p :",reco[i]->usuarioP );

        nombreClienActu = reco[i]->usuarioP;
        imprimirUsuespe();
        
        while (reco[i]!=NULL)
        {
            printf("\t%s\n", reco[i]->nombreP);
            printf("\n");
            reco=reco[i]->sig;
        }
        printf("\n");
    }
}





/**
 *
 *      FUNCIONES DE MAIN
 *
 */


void datosUser()
{
    system("cls");

    char nombreUs[15];
    char cedula[15];

    static int contUsers = 0;
    contUsers++;

    fflush(stdin);
    printf("Ingrese su nombre: ");
    gets(nombreUs);

    fflush(stdin);
    printf("Ingrese su cedula: ");
    gets(cedula);

    insertarusu(nombreUs, cedula);
    cantUs++;
}

static void registrarVenta()
{
    printf("___LISTA DE PRODUCTOS___");
    imprimirpro();
    printf("\n\n");

    int codigo;
    int cantidadp;

    char opcion ;
    fflush(stdin);
    printf("----- ¿DESEA COMPRAR? ('s/n') -----  \n");
    scanf("%c",&opcion);

    if(opcion!= 'n') datosUser();
    
    while(opcion!= 'n')
    {
        printf("-->Ingrese el codigo del producto: ");
        scanf("%i", &codigo);
        fflush(stdin);
        printf("-->Ingrese el cantidad del producto: ");
        scanf("%i", &cantidadp);

        float valor = (float) cantidadp * precioProduct(codigo);
        char nombre[15]; 
        strcpy(nombre, codNombreProduct(codigo));

        insertarPedido(cantUs, nombre , cantidadp, valor);

        fflush(stdin);
        printf("decea adquirir otro producto? 's/n' \n");
        scanf("%c",&opcion);
    }
}

static void NuevoProducto()
{
    char nombrep[15];
    int cantidadp;
    float preciop;

    char opcion;
    do {
        printf("-->Ingrese el nombre del producto: ");
        gets(nombrep);
        printf("-->Ingrese el cantidad del producto: ");
        scanf("%i", &cantidadp);
        printf("-->Ingrese el precio del producto: ");
        scanf("%f", &preciop);
        system("cls");

        insertarpro( nombrep, cantidadp, preciop );
        printf("-- paso..\n");

        fflush(stdin);
        printf("decea continuar? 's/n' \n");
        scanf("%c",&opcion);
        system("cls");

    } while(opcion!= 'n');
}

static void menuPrincipal()
{
    int opcion;
    do {
        printf("1-Registrar venta.\n");
        printf("2-Inventario.\n");
        printf("3-Lista de ventas.\n");
        printf("4-Salir.\n\n");
        printf("Elija su opcion:");
        scanf("%i",&opcion);
        system("cls");
        switch (opcion) {
            case 1:registrarVenta();
                break;
            case 2:NuevoProducto();
                break;
            case 5:imprimirUsu();
                break;
            case 6:imprimirPedi();
                break;
            default:
                printf("la opcion no es valida");
        }
    } while(opcion!=4);
}

int main()
{

    insertarpro( "MANZANA", 15, 1000.0 );
    insertarpro( "PERA", 15, 1000.0 );
    insertarpro( "ZANAHORIA", 15, 1000.0 );


    insertarusu("YHON J", "1645543");
    insertarusu("YHON OCHOA", "16455763");
    insertarusu("MARIA J", "154555543");
    insertarusu("YJ OCHOA", "13789763");

    menuPrincipal();

    return 0;
}
