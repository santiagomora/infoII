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
    \fn     handlerPadre
    \brief  Espera la finalizacion de los procesos hijo,
            y los finaliza para que no queden en estado zombie
    \author Luis Mora
    \date 02-05-2020
    \param [in]
    \param [in]
    \param [out]
    \return 0 si hay exito, 1 si hay un error;
*/
void handlerPadre( ){
    int status;
    pid_t chld,npid;
    while ( ( chld= waitpid( -1,&status,0 ) ) >0 ) {
        if ( WIFEXITED(status) )
            printf( "Padre: hijo %d terminó normalmente.\n",chld );
        else {
            if ( ( npid = fork() ) == 0 )
                handlerHijo( LIMSUP,LIMINF );
            else
                printf( "Padre: hijo %d terminó su actividad inesperadamente, redisparando nuevo proceso con PID:%d.\n",chld,npid );
        }
    }
}

 /***********************************************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
 **********************************************************************************************************************************/
/**
    \fn     crearHijos
    \brief  Bucle donde se crean los N_PROCESOS indicados
            si es el proceso padre, esperaremos a que terminen
            los hijos con esperarHijo, y si es hijo imprimire
            mos el mensaje correspondiente en pantalla
    \author Luis Mora
    \date 02-05-2020
    \param [in] void
    \param [out]
    \return 0 si hay exito, 1 si es interrumpido;
*/
int crearHijos( ){
    signal( SIGCHLD,handlerPadre );
    printf( "Padre: PID %d, Procesos a imprimir: %d.\n",getpid(),N_PROCESOS );
    for ( int ctr=0; ctr<N_PROCESOS; ctr++ ){
        if ( !fork() )
            handlerHijo( LIMSUP,LIMINF );
    }
    while ( ( wait(NULL) )>0 );
    exit(0);
}