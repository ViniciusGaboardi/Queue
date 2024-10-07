#ifndef DEQUE_DINAMICO_GENERICO_H_INCLUDED
#define DEQUE_DINAMICO_GENERICO_H_INCLUDED

#include <iostream>
using namespace std;

template <typename T>
struct Nodo
{
    T elemento;
    Nodo<T>* proximo;
};

template<typename T>
struct FilaDinamicaGenerica
{
    int cardinalidade;
    Nodo<T>* inicio;
    Nodo<T>* fim;
};

template<typename T>
void cria(FilaDinamicaGenerica<T> &fila)
{
    fila.cardinalidade = 0;
    fila.inicio = fila.fim = NULL;
}

template<typename T>
void destroi(FilaDinamicaGenerica<T> &fila)
{
    Nodo<T> *p;
    while (fila.inicio != NULL)
    {
        p = fila.inicio;
        fila.inicio = fila.inicio->proximo;
        delete p;
    }
    fila.fim = NULL;
    fila.cardinalidade = 0;
}

template<typename T>
bool ehVazia(FilaDinamicaGenerica<T> fila)
{
    return fila.cardinalidade == 0;
}

template<typename T>
int numeroDeElementos(FilaDinamicaGenerica<T> fila)
{
    return fila.cardinalidade;
}

template<typename T>
void insereInicio(FilaDinamicaGenerica<T> &fila, T elemento)
{
    Nodo<T>* q = new Nodo<T>;
    q->elemento = elemento;
    q->proximo = fila.inicio;

    if (fila.inicio == NULL)
        fila.inicio = fila.fim = q;
    else
        fila.inicio = q;

    fila.cardinalidade++;
}

template<typename T>
void retiraInicio(FilaDinamicaGenerica<T> &fila)
{
    if(fila.cardinalidade == 0)
        throw "Underflow";

    Nodo<T>* q = fila.inicio;
    fila.inicio = fila.inicio->proximo;
    if(fila.cardinalidade == 1)
        fila.fim = NULL;

    delete q;
    fila.cardinalidade--;
}

template<typename T>
void insereFim(FilaDinamicaGenerica<T> &fila, T elemento)
{
    Nodo<T>* q = new Nodo<T>;
    q->elemento = elemento;
    q->proximo = NULL;

    if(fila.inicio == NULL)
        fila.inicio = fila.fim = q;

    else{
        fila.fim->proximo = q;
        fila.fim = q;
    }

    fila.cardinalidade++;
}

template<typename T>
void retiraFim(FilaDinamicaGenerica<T> &fila)
{
    if(fila.cardinalidade == 0)
        throw "Underflow";

    Nodo<T>* q = fila.inicio;

    if(fila.cardinalidade == 1)
        fila.inicio = fila.fim = NULL;

    else
    {
        while (q->proximo != fila.fim)
        {
            q = q->proximo;
        }
        delete fila.fim;
        fila.fim = q;
        fila.fim->proximo = NULL;
    }

    fila.cardinalidade--;
}

template<typename T>
void mostra(FilaDinamicaGenerica<T> fila)
{
    for (Nodo<T>* p = fila.inicio; p != NULL; p = p->proximo)
        cout << p->elemento << " ";
    cout << endl;
}
#endif // DEQUE_DINAMICO_GENERICO_H_INCLUDED
