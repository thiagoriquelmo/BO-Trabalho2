//Autor: Thiago Riquelmo Marques Nascimento

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


#include <iostream>

using namespace std;

#define MAX_VALORES 100

class Lista{
public:
    int valores[MAX_VALORES];
    unsigned tamanho;
    bool trocou;


    Lista() {         
        tamanho=0;
    }
    ~Lista() {}

    void insere(int valor){
        //erro: nao tem mais espaco
        if (tamanho == MAX_VALORES){
            cout << "Sem espaço"<< endl;
            return;
        }

        else{
            valores[tamanho]=valor;
            tamanho++;
        }
        
    }

    void swap(unsigned pos1, unsigned pos2){
        int aux;
        aux = valores[pos1];
        valores[pos1] = valores[pos2];
        valores[pos2] = aux;
    }

    void BubbleSort(bool imprimir, bool interacoes){
        trocou = true;
        int n = tamanho;
        int aux = tamanho-1;
        int acessos = 0;

        while(trocou){
            trocou = false;

            for(int j = 0; j <= n-2 ; j++){
                if(valores[j] > valores[j+1]){
                    trocou = true;
                    aux = j;
                    swap(j, j+1);
                }
                acessos++;
            }
            n = aux+1;
            if(imprimir){
                imprime();
            }            
        }
        if(interacoes){
            cout<< "O numero de acessos foi de "<< acessos <<" vezes!"<<endl;
        }
        
    }

    void imprime(){
        cout << endl << "Do inicio ao fim" << endl;
        for(unsigned i = 0; i < tamanho; i++){
            cout<< "<" << valores[i] << "> ";
        } 
        cout<<"\n";
    }

};

#endif
