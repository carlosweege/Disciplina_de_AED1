/*Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
https://leetcode.com/problems/sqrtx/description/ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int RaizQuadrada(int x);

int main(){
	
	int numero, raiz;
	
	printf("digite um inteiro positivo: ");
	scanf(" %d", &numero);
		
	
	while( 1 ){
		
		if ( numero < 0 ) {
			printf("digite um numero positivo!: ");
		    scanf(" %d", &numero);
		} else {
			raiz = RaizQuadrada ( numero );
			printf("%d", raiz);
			exit(0);
		}	
	}
	
	
	return 0;
}

int RaizQuadrada ( int x ) {
	int y;
	y = sqrt ( x );
	
	return y;
}