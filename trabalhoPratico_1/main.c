#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encontrarHorario( char *tempo );
int haveConflict( char *evento1[], char *evento2[] );

int main(){

    int resultado;
    char *evento1[] = {"01:00", "02:00"};
    char *evento2[] = {"03:00", "04:00"};


    /*p = malloc( 2 * sizeof(char*) );

    for( i = 0; i < 2; i++ ){
        p[i] = malloc( 10 * sizeof(char) );  ***nao consegui fazer array para array***
        printf("digite o inicio e o fim do evento no formato HH:MM,HH:MM" ); 
    }*/

    resultado = haveConflict ( evento1, evento2);

    if ( resultado == 1 ){
        puts( "true" );
    } else{
        puts( "false" );
    }

    return 0;
}

int encontrarHorario( char *tempo ) {
    int hrs, min;
    sscanf(tempo, "%d:%d", &hrs, &min);
    return hrs * 60 + min;
}

int haveConflict( char *evento1[], char *evento2[] ){
    int inicio1 = encontrarHorario( evento1[0] );
    int fim1 = encontrarHorario( evento1[1] );
    int inicio2 = encontrarHorario( evento2[0] );
    int fim2 = encontrarHorario( evento2[1] );

    if ( inicio1 <= fim2 && inicio2 <= fim1) {
        return 1;
    } else {
        return 0;
    }

}