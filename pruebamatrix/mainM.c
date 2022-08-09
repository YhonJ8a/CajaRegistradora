

#include <stdio.h>
#include <conio.h>
#include <string.h>

void cargar(char *nombre[20][20], int edad[20], int len)
{

    int f;

    for (f = 0; f < 1; f++)
    {
        printf("Ingrese nombre: \n");
        scanf("%s", &nombre[f]);

        printf("Ingrese la edad: \n");
        scanf("%d", &edad[f]);
    }




}

void imprimirMayores(char *nombre[5][20], int edad[5], int len)
{

    int f;
    int c=0;

    for (f = 0; f < 1; f++)
    {

//for ( c = 0;nombre[f][c]!= 0x00 ; c++)
//{
//    printf("En la fila %d, en la calumna %d, el carecter es %c\n\n", f,c,nombre[f][c]);
//
//}


        //while (nombre[f][c]!= 0x00)
        while (c!=5)
        {

            printf("En la fila %d, en la calumna %d, el carecter es %c \n\n", f,c, nombre[f][c]);
            printf("Nombre Completo%c\n",nombre[f][c]);
            //printf("En la fila %d, en la calumna %d, el carecter es %c\n\n", f,c,nombre[f][1]);
            c++;

        }

        printf("\nLa matriz en la fila %d, tiene %d caracteres\n", f, c);
        c=0;
    }


    for (f = 0; f < len; f++)
    {

        if (edad[f] >= 18)
        {

            printf("Nombre:  %s\nEdad: %i\n\n", nombre[f], edad[f]);
        }
    }


     for (int i = 0; i < 5; i++){
        for (int j = 0; j < 20; j++){
            printf(" %c",nombre[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    char nombre[5][20];
    int edad[5];

    memset(nombre, 0x00, sizeof(nombre));
    memset(edad, 0x00, sizeof(edad));
    int len = sizeof(nombre)/sizeof(nombre[0]);

    //printf("\nLEN: %d", len);

    cargar(nombre, edad, len);
    imprimirMayores(nombre, edad, len);
    return 0;
}
