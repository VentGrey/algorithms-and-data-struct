#ifndef __IFUNCIONOBJETIVO_H_
#define __IFUNCIONOBJETIVO_H_

#include <list> // Para utilizar listas, que flojera hacer las mías

/* Las interfaces en C++ se implementan utilizando clases
 * abstractas y dichas clases abstractas no deberán de ser
 * confundidas con la abstracción de datos el cual es un
 * concepto utilizado para mantener separados los detalles
 * de implementación de los datos asociados.*/


/* Una clase se hace abstracta al declarar al menos una de
 * sus funciones como una "funcion pura y virtual"
 *
 * Una función pura y virtual se especifica poniendo un
 * "= 0" en su declaración */

class IFuncionObjetivo {
public:
        virtual int Evaluar() = 0;
};

#endif // __IFUNCIONOBJETIVO_H_
