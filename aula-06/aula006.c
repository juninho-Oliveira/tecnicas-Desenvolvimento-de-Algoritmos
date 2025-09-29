/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
//função que troca o valores usando ponteiros 
void trocar(int *a, int *b){
int temp = *a; // temp recebe o valor de a
*a = *b;    //a recebe o valor de b
*b = temp;  //b recebe o valor de temp
}
int main()
{
    int x = 5, y = 10;
    printf("\nAntes da troca: x = %d, y =%d\n", x, y);
    trocar( &x, &y);
    printf("\nAntes da troca: x = %d, y =%d\n", x, y);
    return 0;
}