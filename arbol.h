#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
using namespace std;


struct Nodo{
    int valor;
    Nodo* izquierda;
    Nodo* derecha;
};

class ArbolBinario{
    private: 
        Nodo* raiz;
        void destruirArbol(Nodo* hoja);
        void insertar(int valor, Nodo* hoja);
        bool buscar(int valor, Nodo* hoja);
        void imprimir(Nodo* hoja, int espacio);

    public:
        ArbolBinario();
        ~ArbolBinario();
        void insertar(int valor);
        void imprimir();
        bool buscar(int valor);
}; 


#endif