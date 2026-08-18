#ifndef BUSCA_H
#define BUSCA_H 

//tipo de dado armazenado no vetor 
typedef int TipoDado; 

//capacidade de armazenamento do vetor 
#define TAM_MAX 100 

//estrutura de dados para o vetor 
typedef struct{ 
    TipoDado dados[TAM_MAX + 1];
    int tamanho; //quantidade de elementos armazenados   
} Vetor;

//inicializar o vetor (construtor)
void criaVetor(Vetor *v);

//insere ym elemento ao final do vetor para construirmos um vetor 
int insereNovoVetor (Vetor *v, TipoDado valor); 

//imprime os elementos do vetor 
void imprimeVetor(const Vetor *v, void(*imprimeElemento)(TipoDado)); 

//busca sequencial básica
int buscaSequencial (const Vetor *v, TipoDado chave);

//busca sequencial com parada antecipada
int buscaSequencialComParada (const Vetor *v, TipoDado chave); 

//busca sequencial com sentinela 
int buscaSequencialComSentinela ( Vetor *v, TipoDado chave); 

#endif //BUSCA H

