// Biblioteca para Pilas


// - Omar Jair Purata Funes

/* Funciones de la biblioteca
 * - PUSH
 * - POP
 * - VACIO
 * - LLENO
 * - PEEP
 * - MOSTRAR
 * */

#ifndef __STACK_H_
#define __STACK_H_

//-- Función VACIO
bool stack::vacio()
{
    if(sup == -1) {
        cout << "UNDERFLOW ERROR! PANICKING"<< endl;
        return true;
    } else {
        return false;
    }
}

//-- Función LLENO
bool stack::lleno()
{
    if(sup > tam) {
        cout << "OVERFLOW ERROR! PANICKING" << endl;
        return true;
    } else {
        return false;
    }
}

//-- Función PUSH
void stack::push(int valor)
{
    if(!lleno()) {
        sup++;
        s[sup] = valor;
    }
}

//-- Función POP
int stack::pop()
{
    if(!vacio()) {
        int tmp = s[sup];
        sup--;
        return tmp;
    }
}




#endif // __STACK_H_
