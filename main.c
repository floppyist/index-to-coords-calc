#include <stdio.h>
#include <stdlib.h>

struct dim {
    int width;
    int height;
} dim;

struct coords {
    int x;
    int y;
} coords;

int getIndexFromCoords( int *x, int *y ) { 
    return ( *x + ( *y * dim.width ) );
}

struct coords getCoordsFromIndex( int *index ) {
    coords.x = ( *index % dim.width );
    coords.y = ( ( *index - coords.x ) / dim.width );

    return coords;
}

void printArray( int *arr, int *x, int *y ) {
    printf( "\n  " );

    int isLine = 0;

    struct coords temp;
    temp.x = *x;
    temp.y = *y;

    for ( int i = 0; i < ( dim.width * dim.height ); i++ ) {
        if ( temp.x == getCoordsFromIndex( &i ).x ) {
            printf( "\x1B[34m" );
        }

        if ( temp.y == getCoordsFromIndex( &i ).y ) {
            printf( "\x1B[34m" );
        }

        if ( temp.x == getCoordsFromIndex( &i ).x && temp.y == getCoordsFromIndex( &i ).y ) {
            isLine = 1;
            printf( "\x1B[37m" );
        }

        printf( "%i ", arr[i] );

        if ( ( i + 1 ) % dim.width == 0 ) {
        printf( "\x1B[0m" );
            if ( isLine ) {
                printf( "[%i][%i]\n  ", temp.x, temp.y );
                isLine = 0;
            } else {
                printf( "\n  " );
            }
        }

        printf( "\x1B[0m" );
    }
}

int main( void ) {
    /* Test variables */
    int x = 3;
    int y = 7;

    int *arr = NULL;

    dim.width = 9;
    dim.height = 9;

    arr = malloc( sizeof( arr ) * dim.width * dim.height );

    if ( arr == NULL ) {
        perror( "Couln't allocate array memory." );
        exit( 1 );
    }

    printArray( arr, &x, &y );

    free( arr );

    printf( "\n\n" );
}
