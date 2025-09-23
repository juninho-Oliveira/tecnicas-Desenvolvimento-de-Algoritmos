
#include <stdio.h>

int main()
{
    int a[2] [2] = {{1,2}, {3,4}};
    int b[2] [2] = {{5,6}, {7,8}};
    int c[2] [2];
    
    printf("Soma de matrizes 2x2: \n");
    for (int i = 0; i<2; i++) {
        for (int j  = 0; j<2; j++) {
            c[i] [j] = a[i] [j] + b[i] [j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }


    int a[3] [2] = {{1,2}, {3,4}, {5,6}};
    int t[2] [3];
    
    printf("CAlcula a transporta: \n");
    for (int i = 0; i<3; i++) {
        for (int j  = 0; j<2; j++) {
            t[i] [j] = a[i] [j];
        }
    }
    printf("Matriz transporta: \n");
    
    for (int i = 0; i<2; i++) {
        for (int j  = 0; j<3; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    int a[2] [2] [2], b[2] [2] [2], c[2] [2] [2] ;
    
    printf("Digite o valor de A: \n");
    for (int i = 0; i<2; i++) {
        for (int j  = 0; j<2; j++) {
            for (int k =0; k < 2; k++) {
                scanf("%d", &a [i][j][k]);
            }
        }
    }
    
    printf("Digite o valor de B: \n");
    for (int i = 0; i<2; i++) {
        for (int j  = 0; j<2; j++) {
            for (int k =0; k < 2; k++) {
                scanf("%d", &b [i][j][k]);
            }
        }
    }
    
    printf("Digite o valor de C: \n");
    for (int i = 0; i<2; i++) {
        for (int j  = 0; j<2; j++) {
            for (int k =0; k < 2; k++) {
                c[i][j][k] = a[i][j][k] + b[i][j][k];
            }
        }
    }
    
    for (int i = 0; i<2; i++) {
        for (int j  = 0; j<2; j++) {
            for (int k =0; k < 2; k++) {
                printf("c[%d][%d][%d] = %d\n", i, j, k, c[i][j][k]);
            }
        }
    }

    return 0;
}