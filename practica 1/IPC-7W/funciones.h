#ifndef FUNCIONES_H
#define FUNCIONES_H
// FUNCIONES_H

/*********************************************************************************************************************************
 *
 * @file		funciones.h
 * @brief		Breve descripción del objetivo del Módulo
 * @date		02-05-2020
 * @author		Luis Mora
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include "../libs/fifo/fifo.h"
#include "../libs/iofd/iofd.h"
/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/
#define BUFSIZE 102
#define FIFOPATH "../shared/avisosFIFO"
/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/
// extern tipo nombreVariable;

/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES GLOBALES
 **********************************************************************************************************************************/
int enviar( char* msj );

#endif // FUNCIONES_H
