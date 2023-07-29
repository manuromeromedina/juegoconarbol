#include <iostream>
#include <cstdlib>
#include <ctime>
#include "arbol.h"

using namespace std;

ArbolBinario::ArbolBinario() {
    raiz = nullptr;
}

ArbolBinario::~ArbolBinario() {
    destruirArbol(raiz);
}

void ArbolBinario::destruirArbol(Nodo* hoja) {
    if(hoja != nullptr) {
        destruirArbol(hoja->izquierda);
        destruirArbol(hoja->derecha);
        delete hoja;
    }
}

void ArbolBinario::insertar(int valor, Nodo* hoja) {
    if(valor < hoja->valor) {
        if(hoja->izquierda != nullptr)
            insertar(valor, hoja->izquierda);
        else {
            hoja->izquierda = new Nodo;
            hoja->izquierda->valor = valor;
            hoja->izquierda->izquierda = nullptr; 
            hoja->izquierda->derecha = nullptr;
        }  
    }
    else if(valor >= hoja->valor) {
        if(hoja->derecha != nullptr)
            insertar(valor, hoja->derecha);
        else {
            hoja->derecha = new Nodo;
            hoja->derecha->valor = valor;
            hoja->derecha->derecha = nullptr;
            hoja->derecha->izquierda = nullptr;
        }
    }
}

bool ArbolBinario::buscar(int valor, Nodo* hoja) {
    if(hoja != nullptr) {
        if(valor == hoja->valor)
            return true;
        if(valor < hoja->valor)
            return buscar(valor, hoja->izquierda);
        else
            return buscar(valor, hoja->derecha);
    } else
        return false;
}

void ArbolBinario::insertar(int valor) {
    if(raiz != nullptr)
        insertar(valor, raiz);
    else {
        raiz = new Nodo;
        raiz->valor = valor;
        raiz->izquierda = nullptr;
        raiz->derecha = nullptr;
    }
}

bool ArbolBinario::buscar(int valor) {
    return buscar(valor, raiz);
}

void ArbolBinario::imprimir() {
    imprimir(raiz,0);
    cout << endl;
}

void ArbolBinario::imprimir(Nodo* hoja, int espacio) {
    int COUNT = 10;

    // Si el nodo es null, salimos de la función
    if(hoja== nullptr) {
        return;
    }
    
    // Aumentamos la distancia para el próximo nivel
    espacio += COUNT;

    // Llamado recursivo para la rama derecha
    imprimir(hoja->derecha, espacio);
        cout << endl;

        for(int i = COUNT; i < espacio; i++) {
        cout << " ";
        }

        cout << hoja->valor << "\n";

    // Llamado recursivo para la rama izquierda
    imprimir(hoja->izquierda, espacio);
}

int main() {
    ArbolBinario arbol;
    srand(time(0)); 
    int secreto = rand() % 100 ;
    int adivinanza;
    int intentos = 10;
    int min = 1;
    int max = 100;

    cout << "¡Adivina el numero secreto del 0 al 100! Tienes 10 intentos."<<endl;

    while (intentos > 0) {
        cout << "Intentos restantes: " << intentos << endl;
        cin >> adivinanza;

        if (arbol.buscar(adivinanza)) {
            cout << "Ya has intentado con este numero, prueba otro."<<endl;
            continue;
        }

        arbol.insertar(adivinanza);
        intentos--;

        if (adivinanza == secreto) {
            cout << "¡Felicidades! Has adivinado el numero secreto: " << secreto << endl;
            break;
        } else {
            cout << "Ese no es el numero. ";

            if (adivinanza < secreto) {
                min = adivinanza;
                cout << "El numero secreto está entre " << min+1 << " y " << max << endl;
            } else {
                max = adivinanza;
                cout << "El numero secreto está entre " << min << " y " << max-1 << endl;
            }
        }
    }

    if (intentos == 0) {
        cout << "Lo siento, no has adivinado el numero. El numero secreto era: " << secreto << endl;
    }

    cout << "Los numeros que ingresaste fueron: ";
    arbol.imprimir();

    return 0;
}
