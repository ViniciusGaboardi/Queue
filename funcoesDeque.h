#ifndef FUNCOESDEQUE_H_INCLUDED
#define FUNCOESDEQUE_H_INCLUDED

#include<iostream>
using namespace std;

template<typename T, int MAX>
struct DequeEstaticoCircular{
    int cardinalidade;
    int inicio;
    int fim;
    T elementos[MAX];
};

template<typename T, int MAX>
void cria(DequeEstaticoCircular<T, MAX> &fila)
{
    fila.cardinalidade = 0;
    fila.inicio = 0;
    fila.fim = -1;
}

template<typename T, int MAX>
bool estaVazia(DequeEstaticoCircular<T, MAX> fila)
{
    return fila.cardinalidade == 0;
}

template<typename T, int MAX>
bool estaCheia(DequeEstaticoCircular<T, MAX> fila)
{
    return fila.cardinalidade == MAX;
}

template<typename T, int MAX>
int numeroDeElementos(DequeEstaticoCircular<T, MAX> fila)
{
    return fila.cardinalidade;
}

template<typename T, int MAX>
bool existeElemento(DequeEstaticoCircular<T, MAX> fila, T elemento)
{
    int i = fila.inicio;
    int elementosVerificados = 1;

    while(elementosVerificados <= fila.cardinalidade){
        if (fila.elementos[i] == elemento)
            return true;

        i = (i + 1) % MAX;
        elementosVerificados++;
    }
    return false;
}

template<typename T, int MAX>
bool checaPosicao(DequeEstaticoCircular<T, MAX> fila, int posicao)
{
    if(numeroDeElementos(fila) == 0 || posicao < 1 || posicao > numeroDeElementos(fila))
        return false;

    int indice = (fila.inicio + posicao - 1) % MAX;
    return (indice >= 0 && indice < MAX);
}

template<typename T, int MAX>
T retornaPrimeiroElemento(DequeEstaticoCircular<T, MAX> fila)
{
    return fila.elementos[fila.inicio];
}

template<typename T, int MAX>
T retornaUltimoElemento(DequeEstaticoCircular<T, MAX> fila)
{
    return fila.elementos[fila.fim];
}

template<typename T, int MAX>
T retornaElemento(DequeEstaticoCircular<T, MAX> fila, int posicao)
{
    if(!checaPosicao(fila, posicao))
        throw "Invalid Position";

    int indice = (fila.inicio + posicao - 1) % MAX;
    return fila.elementos[indice];
}

template<typename T, int MAX>
int retornaPosicao(DequeEstaticoCircular<T, MAX> fila, T elemento)
{
    if(numeroDeElementos(fila) == 0)
        return -1;

    int i = fila.inicio;
    int elementosVerificados = 0;
    int posicao = 1;

    while(elementosVerificados < fila.cardinalidade){
        if(fila.elementos[i] == elemento)
            return posicao;

        i = (i + 1) % MAX;
        elementosVerificados++;
        posicao++;
    }
    return -1;
}

template<typename T, int MAX>
void insereInicio(DequeEstaticoCircular<T, MAX> &fila, T elemento)
{
    if(estaCheia(fila))
        throw overflow_error("OVERFLOW");

    if(estaVazia(fila)){
        fila.inicio = 0;
        fila.fim = 0;
    }
    else{
        fila.inicio = (fila.inicio - 1 + MAX) % MAX;
        if(fila.inicio < 0)
            fila.inicio = MAX - 1;
    }
    fila.elementos[fila.inicio] = elemento;
    fila.cardinalidade++;
}

template<typename T, int MAX>
void insereFim(DequeEstaticoCircular<T, MAX> &fila, T elemento)
{
    if(estaCheia(fila))
        throw overflow_error("OVERFLOW");

    fila.fim = (fila.fim + 1) % MAX;
    fila.elementos[fila.fim] = elemento;
    fila.cardinalidade++;
}

template<typename T, int MAX>
void removeInicio(DequeEstaticoCircular<T, MAX> &fila)
{
    if(estaVazia(fila))
        throw underflow_error("UNDERFLOW!");

    fila.inicio = (fila.inicio + 1) % MAX;
    fila.cardinalidade--;
}

template<typename T, int MAX>
void removeFim(DequeEstaticoCircular<T, MAX> &fila)
{
    if(estaVazia(fila))
        throw underflow_error("UNDERFLOW!");

    fila.fim = (fila.fim - 1 + MAX) % MAX;
    fila.cardinalidade--;
}

template<typename T, int MAX>
void geraLinha(DequeEstaticoCircular<T, MAX> fila)
{
    for(int i = 0; i<numeroDeElementos(fila); i++)
        cout<<"===";
    cout<<endl;
}

template<typename T, int MAX>
void mostra(DequeEstaticoCircular<T, MAX> fila)
{
    cout<<"Queue:"<<endl;
    geraLinha(fila);
    if(estaVazia(fila)){
        cout<<"Queue is empty"<<endl;
        return;
    }
    int i = fila.inicio, elementosExibidos = 1;
    while(elementosExibidos <=fila.cardinalidade){
        cout<<"|"<<fila.elementos[i];
        elementosExibidos++;
        i = (i + 1) % MAX;
    }
    cout<<"|"<<endl;
}

#endif // FUNCOESDEQUE_H_INCLUDED
