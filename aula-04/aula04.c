
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int x, y, tam;
    char nome[30];
    
    printf("Digite uma palvra:");
    gets(nome);
    
    tam = strlen(nome);
    printf("\n A palavra de tras pra frente e:");
    
    x = tam - 1;
    while (x>=0) {
    	printf("%c", nome[x]);
        x--;
		printf("\n\n");
	}
	
    /*
    for(x=tam-1; x>=0; x--)
        printf("%c", nome[x]);
        printf("\n\n");
    */    
    system("pause");
    return 0;
    
}
