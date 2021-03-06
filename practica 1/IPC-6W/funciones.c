/**********************************************************************************************************************************
 *
 * @file		funciones.c
 * @brief		Descripcion del modulo
 * @date		02-05-2020
 * @author		Luis Mora
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "funciones.h"

/***********************************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 **********************************************************************************************************************************/
int fd;
/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** PROTOTIPO DE FUNCIONES PRIVADAS AL MODULO
 **********************************************************************************************************************************/

 /***********************************************************************************************************************************
 *** FUNCIONES PRIVADAS AL MODULO
 **********************************************************************************************************************************/
/**
    \fn     inthandler
    \brief  elimina el fifo cuando hay una interrupcion
    \author Luis Mora
    \date 02-05-2020
    \return 0 si hay exito, 1 si hay un error;
*/
void inthandler( int sig ){
    cierrafifo( FIFOPATH,fd );
}

 /***********************************************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
 **********************************************************************************************************************************/
/**
    \fn     enviar
    \brief  Escribe NUMVAL numeros aleatorios en el FIFO
    \author Luis Mora
    \date 02-05-2020
    \return 0 si hay exito, 1 si hay un error;
*/
int enviar( ){
    int rnd;
    signal( SIGINT,inthandler );
    fd = abrefifo( FIFOPATH,O_WRONLY );
    srand( time(NULL) );
    for ( int ctr=0; ctr<NUMVAL; ctr++ ){
        rnd = rand()%LIMSUP + LIMINF;
        escribefd( fd,&rnd,sizeof( int ) );
        printf( "enviado[%d]: %d\n",ctr+1,rnd );
    }
    exit(0);
}
