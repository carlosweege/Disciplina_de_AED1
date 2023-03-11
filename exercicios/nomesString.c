#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addNome( char *string );
void removeNome( char *string );
void listar( char *string );

int main(){

    int opcao;
    char *string = (char*)malloc( sizeof( char ) );
    do{
        printf( "===============================\n");
        printf("Digite a opcao desejada\n");
        printf("1 - add nome\n");
        printf("2 - remove nome\n");
        printf("3 - listar\n");
        printf("4 - sair\n");
        printf("================================\n" );
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            addNome(string); break;
        case 2:
            removeNome(string); break;
        case 3:
            listar(string); break;
        case 4:
            break;
        }

    }while( opcao != 4 );

    return 0;
}
void addNome( char *string ){
    char nome[10];
    int i;

    for( i = 0; i<10; i++ )
        nome[i] = '*';

    scanf( " %10s", nome );

    string = ( char* )realloc( string, (10 * sizeof(char) + sizeof(string) ) );
    strcat( string, nome );

    
}
void removeNome( char *string ){
    char nome[11], *p;
    int i;

    for ( i = 0; i<10; i++ ){
        nome[i] = '*'; 
    }
    
    printf("digite o nome que deseja remover: ");
    scanf(" %10s", nome);
    p = strstr( string, nome );

    if ( p == NULL ){
        printf("palavra nao encontrada");
        return;
    }

    if(sizeof(string) <= 11){
        string = ( char* )realloc( string, 1 * sizeof(char) );
        return;
    }

    if ( *(p+10) == '\0' ){
        *p = '\0';
        return;
    }

    for ( i = 0; *( p+10+i ) != '\0'; i++ ){}

    memmove( p, (p+10), i );


}
void listar( char *string ){
    int i, tam;

    for ( tam = 0; *string != '\0'; tam++ )

    for ( i = 0; i <= tam; i++ ){
        printf( "%c", string[i] );
        if ( ( i+1 ) % 10 == 0 ){
            putchar( '\n' );
        }
    }

}
