#include <stdio.h>
#include <stdlib.h>

/**

        STRUCT

*/

typedef struct{  // PRODUCTOS
    int codigo;
    char nombre[15];
    int cantidad;
    float precio;
    struct nodo *sig;
    struct nodo *ant;
} nodo;

typedef struct{  // USUARIOS
    char nombreUs[15];
    char cedulaUs[15];
    struct usuarios *sig;
    struct usuarios *ant;
}usuarios;









static void registrarVenta()
{
    printf("___LISTA DE PRODUCTOS___");
    imprimir();
    printf("\n\n");

    int codigo;
    int cantidadp;

    char opcion ;
    fflush(stdin);
    printf("----- �DECEA COMPRAR? ('s/n') -----  \n");
    scanf("%c",&opcion);


    if (opcion!= 'n')datosUser();

    while(opcion!= 'n')
    {
        printf("-->Ingrese el codigo del producto: ");
        scanf("%i", &codigo);
        fflush(stdin);
        printf("-->Ingrese el cantidad del producto: ");
        scanf("%i", &cantidadp);

        fflush(stdin);
        printf("decea adquirir otro producto? 's/n' \n");
        scanf("%c",&opcion);
    }

}


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
}


static void NuevoProducto()
{
    int codigo;
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

        fflush(stdin);
        printf("decea continuar? 's/n' \n");
        scanf("%c",&opcion);
        system("cls");

    } while(opcion!= 'n');
}


static void menuPrincipal()
{
    system("cls");
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
            default:
                printf("la opcion no es valida");
        }
    } while(opcion!=5);
}


int main()
{

    insertarpro( "MANZANA", 15, 1000.0 );
    insertarpro( "PERA", 15, 1000.0 );
    insertarpro( "ZANAHORIA", 15, 1000.0 );


    menuPrincipal();
    return 0;
}
