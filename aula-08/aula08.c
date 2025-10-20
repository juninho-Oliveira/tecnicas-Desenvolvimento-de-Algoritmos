
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
    int tam, n;
    char alfa[26];
    strcpy(alfa, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    printf("Digite um numero: ");
    scanf("%d", &n);

    if(n < 1 || n > 26) {
        printf("Numero invalido digite de 1 a 26. \n");
        return 1;
    } 
	
    tam = strlen(alfa);
    for (int i = 0; i < n; i++) {
        alfa[tam + n] = alfa[i];
    }

    alfa[tam + n] = "\0";
    printf("Resultado: %s\n", alfa);
    return 0;
    
}
