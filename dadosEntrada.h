#ifndef DADOSENTRADA_H_INCLUDED
#define DADOSENTRADA_H_INCLUDED

void Menu() //autoexplicativo
{
    cout<<"Generic Queue 3.1415"<<endl;
    cout<<"====================="<<endl;
    cout<<"1 - Insert"<<endl;
    cout<<"2 - Remove"<<endl;
    cout<<"3 - Show Queue"<<endl;
    cout<<"4 - Exit"<<endl;
    cout<<"====================="<<endl;
}

void menuInsere()
{
    cout<<"Insert"<<endl;
    cout<<"====================="<<endl;
    cout<<"1 - Insert at the Start"<<endl;
    cout<<"2 - Insert at the End"<<endl;
    cout<<"====================="<<endl;
}

void menuRetira()
{
    cout<<"Remove"<<endl;
    cout<<"====================="<<endl;
    cout<<"1 - Remove at the Start"<<endl;
    cout<<"2 - Remove at the End"<<endl;
    cout<<"====================="<<endl;
}

bool checkInputNum(string num) //checagem de dados para input de valores inteiros para o menu
{
    for(int i=0; i<num.length(); i++)
        if(!isdigit(num[i]))
            return false;
    return true;
}

bool checkOption(int num)
{
    if(num<1 or num>2)
        return false;
    return true;
}

int inputOptionMenu() //funcao para o menu principal (as entradas de 1 a 3 pra acessar cada op��o)
{
    int op1;
    string op;
    bool check;
    do{
        cout<<"Choose any of the available options above."<<endl;
        cout<<"A: ";
        getline(cin, op);
        check = checkInputNum(op);
        if((check) and (op!=""))
            op1 = stoi(op);
        if((op1<1 or op1>4) or (op=="")){
            cout<<"This option does not exist."<<endl;
            system("pause");
            system("clear||cls");
        }
    }while(!check and op1<1 and op1>4);
    return op1;
}

template<typename T, int MAX>
void inputInsere(DequeEstaticoCircular<T, MAX> &fila)
{
    T elemento; int insercao; string checaInsercao;
    cout<<"Insert"<<endl;
    cout<<"========"<<endl;
    cout<<"Element: ";
    cin>>elemento;
    cin.ignore();
    do{
        menuInsere();
        cout<<"Where does it go?"<<endl;
        cout<<"A: ";
        getline(cin, checaInsercao);
        if((checkInputNum(checaInsercao))&&(checaInsercao!=""))
            insercao = stoi(checaInsercao);
        if((!checkOption(insercao))or checaInsercao==""){
            cout<<"This option does not exist."<<endl;
            system("pause");
            system("clear||cls");
        }
        else if(insercao==1){
            insereInicio(fila, elemento);
            cout<<"Successfully inserted at the Start!"<<endl;
        }
        else{
            insereFim(fila, elemento);
            cout<<"Successfully inserted at the End!"<<endl;
        }
    }while(!checkOption(insercao));

    system("pause");
    system("clear||cls");
}

template<typename T, int MAX>
void inputRemove(DequeEstaticoCircular<T, MAX> &fila)
{
    int remocao; string checaRemocao;
    do{
        menuRetira();
        cout<<"Where do you want to remove?"<<endl;
        cout<<"A: ";
        getline(cin, checaRemocao);
        if((checkInputNum(checaRemocao))&&(checaRemocao!=""))
            remocao = stoi(checaRemocao);
        if((!checkOption(remocao))or checaRemocao==""){
            cout<<"This option does not exist."<<endl;
            system("pause");
            system("clear||cls");
        }
        else if(remocao==1){
            removeInicio(fila);
            cout<<"Successfully removed at the Start!"<<endl;
        }
        else{
            removeFim(fila);
            cout<<"Successfully removed at the end!"<<endl;
        }
    }while(!checkOption(remocao));

    system("pause");
    system("clear||cls");
}

#endif // DADOSENTRADA_H_INCLUDED
