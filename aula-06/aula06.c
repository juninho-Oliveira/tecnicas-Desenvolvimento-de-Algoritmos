#include <stdio.h>

void loopcount(int *i){ //void não retrona valor
printf("Na funcãoLoop count, i = ");
while(*i<10) 
    printf("%d ", (*i)++);
}

int main()
{
    /*int x = 10;
    int *px;
    px = &x;

    printf("Valor de x (direto): %d\n", x);
    printf("Valor de px (direto): %d\n", *px);

    printf("Endereço de x:: %p\n", &x);

    printf("Endereço guardado em px: %p\n", px);*/

        int i = 2;
    printf("\nEmmain antes a chamada da função, i = %d. \n", i);
    loopcount( &i);
    printf("\nEmmain antes a chamada da função, i = %d. \n", i);

    return 0;
}