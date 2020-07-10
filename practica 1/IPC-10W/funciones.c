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
    \fn     aleatorios
    \brief  genera 10 numeros aleatorios
    \author Luis Mora
    \date 02-05-2020
    \return puntero a la direccion de memoria a almacenar.
*/
int* aleatorios( int* res ){
    srand( time( NULL ) );
    for ( int ctr = 0; ctr<SHMSIZE; ctr++ )
        res[ctr]=rand()%100 + 1;
    return res;
}

/**
    \fn     imprimemem
    \brief  imprime valores almacenados en memoria compartida
    \author Luis Mora
    \date 02-05-2020
    \param [in] mem direccion de memoria compartida
*/
void imprimemem( int* mem ){
    printf("VALORES ESCRITOS:\n");
    for ( int ctr =0; ctr<SHMSIZE; ctr++ )
        printf("valor[%d]: %d\n",ctr+1,mem[ctr]);
}

/**
    \fn     lee
    \brief  lee de la memoria compartida
    \author Luis Mora
    \date 02-05-2020
    \param [in] int shid el id de la memoria
    \return 0 si hay exito, 1 si hay un error
*/
int lee( int shid ){
    int *val = ( int* ) enganchashm( shid,NULL,0 );
    val = aleatorios( val );
    imprimemem( val );
    desenganchashm( val );
    return 0;
}

 /***********************************************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
 **********************************************************************************************************************************/

/**
    \fn     conecta
    \brief  conecta a la memoria compartida y la crea si no existe
    \author Luis Mora
    \date 02-05-2020
    \return 0 si hay exito, 1 si hay un error;
*/
int conecta( void ){
    int shid = conectashm( KEYFILE,SHMSIZE*sizeof( int ),PRKEY,IPC_CREAT|S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH );
    lee( shid );
    return 0;
}
