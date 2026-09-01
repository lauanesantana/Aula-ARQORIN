#include <stdio.h> 
#include "busca.h"

//função de impressão para o tipoDado = int 
// se TipoDado mudar, basta escrever essa função de acordo com o novo tipo 
void imprimeInt (TipoDado valor) {
    printf ("%d", valor); 
}

int main () { 

    Vetor v; 
    int resultado; 
    
    criaVetor(&v); 

    TipoDado valores[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    //sizeof da o tamanho em bytes, por isso divide 
    int n = sizeof(valores) / sizeof (valores[0]); 

    int i; 
    //inserir valores no vetor v 
    for (i = 0; i < n; i++) { 
        insereNovoVetor(&v, valores[i]); 
    }

    //imprime o vetor
    printf ("Vetor: "); 
    imprimeVetor(&v, imprimeInt); 

    //Busca sequencial 
    resultado = buscaSequencial(&v, 7); 
    printf ("Busca sequencial (Chave = 7): Posição %d\n", resultado); 

    resultado = buscaSequencial(&v, 8); 
    printf ("Busca sequencial (Chave = 8): Posição %d\n", resultado); 

    //Busca sequencial com parada antecipada 
    resultado = buscaSequencialComParada (&v, 9); 
    printf ("Busca sequencial (Chave = 9): Posição %d\n", resultado); 

    resultado = buscaSequencialComParada(&v, 12); 
    printf ("Busca sequencial (Chave = 12): Posição %d\n", resultado); 

    //Busca sequencial com sentinela 
    resultado = buscaSequencialComSentinela(&v, 17); 
    printf ("Busca sequencial (Chave = 17): Posição %d\n", resultado); 

    resultado = buscaSequencialComSentinela(&v, 16); 
    printf ("Busca sequencial (Chave = 16): Posição %d\n", resultado); 

    //EXERCICIO: Em main.c, insira ao menos 10 elementos ordenados no vetor e demonstre o uso de ambas as funções, testando: (i) uma chave existente e (ii) uma chave inexistente.

    //Busca binária iterativa - com chave existente
    resultado = buscaBinaria(&v, 5); 
    printf ("Busca binária (Chave = 5): Posição %d\n", resultado); 

    //Busca binária iterativa - com chave inexistente
    resultado = buscaBinaria(&v, 4); 
    printf ("Busca binária (Chave = 4): Posição %d\n", resultado); 

    //Busca binária recursiva - com chave existente 
    resultado = buscaBinariaRecursiva(&v, 1, TAM_MAX, TAM_MAX/2); 
    printf ("Busca binária (Chave = 1): Posição %d\n", resultado); 

     //Busca binária recursiva - com chave inexistente 
    resultado = buscaBinariaRecursiva(&v, 18, TAM_MAX, TAM_MAX/2); 
    printf ("Busca binária (Chave = 18): Posição %d\n", resultado);

}