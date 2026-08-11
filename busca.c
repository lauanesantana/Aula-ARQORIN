#include<stdio.h>
#include"busca.h" 

void criaVetor(Vetor *v) { 
    v-> tamanho = 0; 

}

int insereNovoVetor (Vetor *v, TipoDado valor) { 

    if (v-> tamanho >= TAM_MAX) { 
        return 0;
    }

    v->dados[v->tamanho] = valor; 
    v->tamanho++; 

    return 1;
}

void imprimeVetor(const Vetor *v, void(*imprimeElemento)(TipoDado)) { 

    int i; 
    for( i = 0; i < v->tamanho; i++) {
        imprimeElemento(v->dados[i]); 
    }
    printf("\n"); 
}

//Tarefa: 
int buscaSequencial (const Vetor *v, TipoDado chave);


int buscaSequencialComParada (const Vetor *v, TipoDado chave); 


int buscaSequencialComSentinela (const Vetor *v, TipoDado chave); 
