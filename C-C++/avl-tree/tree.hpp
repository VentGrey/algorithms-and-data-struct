#ifndef __TREE_H_
#define __TREE_H_

class Nodo {
    public:
        int id;
        Nodo *izq;
        Nodo *der;
        int alt;
};

int height(Nodo *N)
{
    if (N == NULL)
        return 0;
    return N-> alt;
}

int max(int a, int b) {

        if (a > b)
                return a;
        else
                return b;
}



#endif // __TREE_H_
