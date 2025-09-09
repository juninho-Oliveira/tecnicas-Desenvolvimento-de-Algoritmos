/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int cub [5] [5] [5];
    int j, i, k;
    
    // preenche o array de 3 dimensões com zeros
    for( i=0; i<5; i++) 
	{
    	for (j =0; j<5; j++ ) 
		{
    		for(k=0; k<5; k++) 
			{
    			cub [i] [j] [k] = 0;
			}
		}
	}
	
	for(i=0; i <5; i++) 
	{
		for(j = 0; i<5; j++)
		{
			for(k =0; k<5; k++)
			{
				printf("%d", cub[i][j][k]);
			}
		}
		printf("\n\n");
	}

    return 0;
}
