/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


int main(int argo, char *argv[])
{
    
    setlocale(LC_ALL, "Portuguese");
    
    int a, b, c;
    float delta, x1, x2;
    printf("\n****** Cálculo de Báskara ******\n\n");
    printf("Digite o valor para A: ");
    scanf("%d", &a);
    printf("Digite o valor para B: ");
    scanf("%d", &b);
    printf("Digite o valor para C: ");
    scanf("%d", &c);
    delta = pow(b,2) -(4*a*c);
    
    if (b==0) 
    {
        x1 = b*(-1);
        x1 = x1 / (2*a);
        x2 = x1;
        
        printf("\n\nDelta: %.0f\n", delta);
        printf("\n\nnx1: %.0f\nx2: %0f\n", x1,x2);
        
    }
    
    else if (delta > 0)
    {
        x1 = (b*(-1) + sqrt(delta))/ (2*a);
        x2 = (b*(-1) + sqrt(delta))/ (2*a);
        printf("\n\nDelta: %.0f\n", delta);
        printf("\n\nnx1: %.0f\nx2: %0f\n", x1,x2);
    }
    
    if (delta < 0)
        printf("\ ATENÇÃO !!! Não possui raiz real. \n\n");  
        
    return 0;
}