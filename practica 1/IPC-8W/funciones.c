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

 /***********************************************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
 **********************************************************************************************************************************/
/**
    \fn     iniciaMSJ
    \brief  inicializa la estructura mensaje
    \author Luis Mora
    \date 02-05-2020
    \param [in] type el tipo del mensaje
    \param [in] text el texto del mensaje
    \param [out] struct msj inicializada
    \return 0 si hay exito, 1 si hay un error;
*/
struct msj iniciaMSJ( int type,char* text ){
    struct msj aux;
    aux.mtype = type;
    strcpy( aux.mtext,text );
    return aux;
}
/**
    \fn     escribirMSJ
    \brief  Envia el mensaje a la cola.
    \author Luis Mora
    \date 02-05-2020
    \param [in] text el texto del mensaje
    \param [out]
    \return 0 si hay exito, 1 si hay un error al enviar el mensaje,
              al obtener la cola o al generar la llave;
*/
int escribir( char* text ){
    int cid = obtencola( KEYFILE,PRKEY );
    struct msj m= iniciaMSJ( 1,text );
    printf( "ENVIANDO MENSAJES:\n" );
    for ( int i=0;i<CANTMSJ; i++ ){
        escribemensaje( cid,&m,sizeof( struct msj ),0 );
        printf( "MENSAJE ENVIADO: %s\n",text );
    }
    exit(0);
}
