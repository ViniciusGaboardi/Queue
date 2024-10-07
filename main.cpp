#include <iostream>
#include <clocale>
#include"funcoesDeque.h"
#include"dadosEntrada.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    DequeEstaticoCircular<string, 5> fila; cria(fila);

    bool isQuitTrue = false;
    do{
        Menu();
        int op1 = inputOptionMenu();
        switch(op1){
            case 1:
                system("clear||cls");
                inputInsere(fila);
                break;
            case 2:
                system("clear||cls");
                inputRemove(fila);
                break;
            case 3:
                system("clear||cls");
                if(numeroDeElementos(fila)>0){
                    cout<<"First: "<<retornaPrimeiroElemento(fila)<<endl;
                    cout<<"Last: "<<retornaUltimoElemento(fila)<<endl;
                }
                mostra(fila);
                system("PAUSE");
                system("clear||cls");
                break;
            case 4:
                cout<<"========="<<endl;
                cout<<"Leaving..."<<endl;
                isQuitTrue = true;
        }
    }while(!isQuitTrue);

    return 0;
}
