#include <stdio.h>
#include <stdlib.h>

/**
 * 
 *      LAS GLOVALES
 * 
 */

#define TAMANO 50
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
        printf(" codigo: %i\t precio : %0.0f \n",reco->codigo,reco->precio);
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
                    nombreClienActu = reco->sig;
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
        }
    }
}

void imprimirUsu()
{
    usuarios *recous=raizUsu;
    while (recous!=NULL)
    {
        printf("\n\n************************************\n");
        printf("<<<<<<<<<<  %s  >>>>>>>>>>>\n",recous->nombreUs);
        printf("\t cedula : %s \n",recous->cedulaUs);
        printf("\t cod : %i \n\n",recous->codigoUsu);
        recous=recous->sig;
    }
    printf("\n");
}

void imprimirUsuespe(usuarios *usuarioProd)
{
        printf("\n*************************************\n");
        printf(" nombre\t cedula\t codigo\n");
        printf(" %s \t %s \t %i\n\n",usuarioProd->nombreUs ,usuarioProd->cedulaUs ,usuarioProd->codigoUsu);
}


/**
 *
 *      FUNCIONES DE PEDIDO
 *
 */

typedef struct{             // STRUCT PEDIDOS
    int codigoPedido; 
    usuarios *usuarioP;
    char nombreP[15];
    int cantidadproducts;
    float valorC;
    struct pedidos *sig;
    struct pedidos *ant;
}pedidos;

pedidos *raizPed = NULL;
pedidos *vectorPedidos[TAMANO]; // la idea es en este array meter las raices de cada lista ok 
//int i;


int existePedido(int x, pedidos *raizPedEx)
{
    pedidos *recoped = raizPedEx;
    while (recoped != NULL)
    {
        if (recoped->codigoPedido == x)
            return 1;
        recoped = recoped->sig;
    }
    return 0;
}

int vaciaped(pedidos *raizPedEx)
{
    if (raizPedEx == NULL)
        return 1;
    else
        return 0;
}

int cantidadPed(pedidos *raizPedCa)
{
    int cantd = 0;
    pedidos *recoped = raizPedCa;
    while (recoped != NULL)
    {
        printf("name::: %s\n", recoped->nombreP);
        recoped = recoped->sig;
        cantd++;
        printf("::: %i\n",cantd);
    }
    return cantd;
}

void insertarPedido( int pos , char nombreProd[15] , int cantProd, float valor, pedidos *vect[TAMANO])
{
    static int codigo = 0;
    codigo++;
    
    printf("guardar : %i , %s , %i , %0.0f \n", pos , nombreProd, cantProd, valor);
    int posi = cantidadPed(vect[pos])+1;
    if(!existePedido(codigo, vect[pos])){
        if (posi <= cantidadPed(vect[pos])+1 ){
            pedidos *nuevo;
            nuevo=malloc(sizeof(pedidos));
            nuevo->codigoPedido = codigo;
            nuevo->usuarioP = nombreClienActu;
            strcpy(nuevo->nombreP , nombreProd);
            nuevo->cantidadproducts = cantProd;
            nuevo->valorC = valor;
            nuevo->ant=NULL;
            nuevo->sig=NULL;

            if (posi == 1)
            {
                nuevo->sig = vect[pos];
                if (vect[pos] != NULL) vect[pos]->ant = nuevo;
                vect[pos] = nuevo;
            }
            else
            {
                if (posi == cantidadPed(vect[pos]) + 1)
                {
                    pedidos *reco = vect[pos];
                    while (reco->sig != NULL)reco = reco->sig;
                    reco->sig = nuevo;
                    nuevo->ant = reco;
                }
                else
                {
                    pedidos *reco = vect[pos];
                    int f;
                    for (f = 1; f <= posi - 2; f++)reco = reco->sig;

                    pedidos *siguiente = reco->sig;
                    reco->sig = nuevo;
                    nuevo->ant = reco;
                    nuevo->sig = siguiente;
                    siguiente->ant = nuevo;
                }
            }
        }
    }
}

void imprimirPedi(pedidos *vectP[TAMANO])
{
    system("cls");
    int i = 0;
    pedidos *reco = vectP[i];
    printf("se mama");
    while (reco != NULL)
    {
        reco = vectP[i];
        printf("\n*************************************\n");
        printf("<<<<<<<<<<  pedido N:%i  >>>>>>>>>>>\n", reco->codigoPedido);
        imprimirUsuespe(reco->usuarioP);
        
        while (reco!=NULL) reco=reco->sig;
        printf("\n");
        i++;
    }
}



/**
 *
 *      FUNCIONES DE MAIN
 *
 */


void datosUser(){
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
    scanf("%s", &cedula);

    insertarusu(nombreUs, cedula);
    cantUs++;
}

static void registrarVenta()
{
    int codigo;
    int cantidadp;

    char opcion ;
    fflush(stdin);
    printf("----- ¿DESEA COMPRAR? ('s/n') -----  \n");
    scanf("%c",&opcion);

    if(opcion!= 'n'){
        datosUser(); 
        printf("\t___LISTA DE PRODUCTOS___");
        imprimirpro();
    } 
    
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

        insertarPedido(cantUs, nombre , cantidadp, valor , &vectorPedidos); // el dilema es el campo cantUs

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
            case 6:imprimirPedi(&vectorPedidos);
                break;
            default:
                printf("la opcion no es valida");
        }
    } while(opcion!=4);
}

int main()
{
    for (int i = 0 ; i< TAMANO ; i++) vectorPedidos[i]= raizPed;

    insertarpro( "MANZANA", 15, 1500.0 );
    insertarpro( "PERA", 15, 1350.0 );
    insertarpro( "ZANAHORIA", 15, 2000.0 );


    insertarusu("YHON J", "1645543");
    insertarusu("YHON OCHOA", "16455763");
    insertarusu("MARIA J", "154555543");
    insertarusu("YJ OCHOA", "13789763");

    menuPrincipal();

    return 0;
}
