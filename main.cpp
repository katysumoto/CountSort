#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio2.h>
#include <stdio.h>

int TAM = 10;
int DOMINIO = 100;

using namespace std;

void aleatorio(int v[]);
void exibir(int v[], int t);
void exibirColoridoValor(int v[], int p, int t);
void exibirColoridoPosicao(int v[], int p, int t);
void countSort(int v[]);
void countSortTutorial(int v[]);

int main()
{
    int v[TAM], opcao;
    while (true)
    {
        system("cls");
        cout << "Escolha uma opcao quanto a demonstracao do CountSort: " << endl << endl;
        cout << "1- Demonstracao sem tutorial" << endl;
        cout << "2- Demonstracao com tutorial" << endl;
        cout << "3- Sair" << endl;
        cin >> opcao;
        switch(opcao)
        {
        case 1:
            aleatorio(v);
            system("cls");
            cout << "Vetor inicial: " << endl;
            exibir(v, TAM);
            cout << endl << "Vetor apos o countSort: " << endl;
            countSort(v);
            exibir(v, TAM);
            cout << endl;
            system("pause");
            break;
        case 2:
            TAM = 5;
            DOMINIO = 10;
            aleatorio(v);
            countSortTutorial(v);
            system("pause");
            system("cls");

            TAM = 10;
            break;
        case 3:
            return 0;
            break;
        }

    }
return 0;
}

void aleatorio(int v[])
{
    srand(time(NULL));
    for(int i=0; i<TAM; i++)
        v[i] = rand()%DOMINIO;
}

void exibir(int v[], int t)
{
    for(int i=0; i<t; i++)
        cout << v[i] << " ";
    cout << endl;
}

void exibirColoridoPosicao(int v[], int p, int t)
{
    for(int i=0; i<t; i++)
    {
        if(i==p)
        {
            textcolor(GREEN);
            cout << v[i] << " ";
            textcolor(WHITE);
        }
        else if(v[i] == -1)
            cout << "__ ";
        else
            cout << v[i] << " ";
    }

    cout << endl;
}

void exibirColoridoValor(int v[], int p, int t)
{
    for(int i=0; i<t; i++)
    {
        if(v[i]==p)
        {
            textcolor(GREEN);
            cout << v[i] << " ";
            textcolor(WHITE);
        }
        else if(v[i] == -1)
            cout << "__ ";
        else
            cout << v[i] << " ";
    }

    cout << endl;
}

void countSort(int v[])
{
    int saida[TAM];
    int aux[DOMINIO];
    for(int i=0; i<DOMINIO; i++)
        aux[i] = 0;
    for(int i=0; i<TAM; i++)
        ++aux[v[i]];
    for(int i=1; i<=DOMINIO; i++)
        aux[i]+=aux[i-1];
    for(int i=0; i<TAM; i++)
    {
        saida[aux[v[i]]-1] = v[i];
        --aux[v[i]];
    }
    for(int i=0; i<TAM; i++)
        v[i] = saida[i];
}

void countSortTutorial(int v[])
{
    system("cls");
    cout << "Este tutorial tentara explicar de forma resumida o funcionamento do Counting Sort, mais conhecido como CountSort." << endl;
    cout << endl;
    system("pause");
    system("cls");
    cout << "Basicamente o que o CountSort faz eh contar quantos elementos menores que um elemento do vetor existem, descobrindo sua posicao no vetor ordenado." << endl;
    cout << endl;
    cout << "A seguir sera exibido uma demonstracao de como esse processo eh executado" << endl << endl;
    system("pause");
    system("cls");
    cout << "Para essa demonstracao usaremos o seguinte vetor de 5 posicoes: " << endl << endl;
    exibir(v, TAM);
    cout << endl;
    system("pause");
    system("cls");
    int aux[DOMINIO], saida[TAM];
    for(int i=0; i<DOMINIO; i++)
        aux[i] = 0;
    cout << "Entao criamos um vetor de tamanho igual ao maior numero possivel no nosso vetor, para guardar as posicoes de cada um doselementos do vetor, e o inicializamos com zeros. " << endl;
    cout << "Neste exemplo nosso dominio eh de 10, entao o vetor auxiliar utilizado tera 10 posicoes, como mostrado abaixo." << endl << endl;
    exibir(aux, DOMINIO);
    system("pause");
    system("cls");
    cout << "A seguir para cada elemento do vetor inicial, acrescentamos em 1 em sua respectiva posicao no vetor auxiliar:" << endl;
    for(int i=0; i<TAM; i++)
    {
        cout << "Acrescentando o elemento " << v[i] << ":" << endl << endl;
        cout << "Vetor inicial: ";
        ++aux[v[i]];
        exibirColoridoPosicao(v, i, TAM);
        cout << endl << "Vetor auxiliar:\t";
        exibirColoridoPosicao(aux, v[i], DOMINIO);
        cout << "Posicao:\t";
        for(int i=0; i<DOMINIO; i++)
            cout << i << " ";
        cout << endl << endl;
        system("pause");
        system("cls");
    }
    cout << "Em seguida para cada elemento do vetor auxiliar somamos ele a seu antecessor, obtendo assim o valor de quantos elementosexistem antes deste, definindo sua posicao correta:" << endl << endl;
    for(int i=1; i<=DOMINIO; i++)
    {
        aux[i]+=aux[i-1];
    }
    cout << "Vetor Auxiliar\t";
    exibir(aux, DOMINIO);
    cout << "Posicao:\t";
    for(int i=0; i<DOMINIO; i++)
        cout << i << " ";
    cout << endl << endl;
    system("pause");
    system("cls");
    cout << "E finalmente colocamos cada um dos elementos do vetor em sua posicao correta num vetor saida" << endl << endl;
    for(int i=0; i<TAM; i++)
    {
        saida[aux[v[i]]-1] = v[i];
        --aux[v[i]];
    }
    cout << "Vetor inicial:\t ";
    exibir(v, TAM);
    cout << "Vetor final:\t ";
    exibir(saida, TAM);
    for(int i=0; i<TAM; i++)
        v[i] = saida[i];
}
