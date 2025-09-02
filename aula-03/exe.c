/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>


int main()
{
    int x, tam;
    x=1;
    char nome[30];
    
    /*printf("Digite um nome: ");
    scanf("%s", &nome);
    tam = strlen(nome);
    for(x=1; x<= tam; x++)
        printf("\n%s", nome);
    printf("\n\n");*/
    
    printf("Digite um nome: ");
    scanf("%s", &nome);
    
    tam = strlen(nome);
    while(x <= tam){
        printf("\n%s", nome);
        x++;
    }
    printf("\n\n");
    
    return 0;
}