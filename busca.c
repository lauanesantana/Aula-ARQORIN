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
int buscaSequencial (const Vetor *v, TipoDado chave){
    int i; 
    for (i = 0; i < v->tamanho; i++ ) { 
        if (v-> dados [i] == chave ) { 
        return i; 
        }
    }
    return -1;
}

//busca sequencial com parada antecipada, vetor ordenado 
int buscaSequencialComParada (const Vetor *v, TipoDado chave) {

    int i; 
    for (i = 0; i < v->tamanho; i++) { 
        //encontra chave 
        if (chave == v->dados [i]) { 
            return 1;
        }
        //chave é menor que o elemento do vetor 
        else if (v-> dados [i] > chave) {
            return -1; 
        }
    }
    return -1; //nao encontrou 
}

int buscaSequencialComSentinela (Vetor *v, TipoDado chave) { 

    int i =0; 
    //insere chave na ultima posicao do array/vetor
    v->dados[v->tamanho] = chave; 

    while(v->dados[i] != chave) { 
        i++;
    }

    return (i < v->tamanho) ? i : -1;
}

// EXERCICIO: versão iterativa, que recebe o vetor e uma chave, e retorna o índice do elemento encontrado ou -1 caso não exista.
// As duas funções exigem que o vetor esteja ordenado, visto que vamos dividir ao meio e ir procurando, o vetor nao pode estar com ordem 'aleatoria'
int buscaBinaria ( Vetor *v, TipoDado chave ) { 
    
    int inicio = 0; 
    int fim = TAM_MAX - 1; 
    int meio; 

    while (inicio <= fim) { 
        meio = (inicio + fim) / 2; 
    }
    if (v->dados[meio] == chave) { 
        return meio; 
    } else if (v->dados[meio] < chave) { 
        inicio = meio+1; //segundo exemplo de sala, busca na metade direita 
    } else { 
        fim = meio-1; //segundo exemplo de sala, busca na metade esquerda
    } 
    return -1; //nao encontrado
}
//EXERCICIO:  — versão recursiva, com a mesma semântica de retorno, recebendo também os limites início e fim do intervalo de busca.

int buscaBinariaRecursiva ( Vetor *v, TipoDado chave, int fim, int meio ) { 
    int inicio = 0; 
    int fim = TAM_MAX - 1; 
    int meio; 

    if (inicio > fim) { 
        return -1; //não encontrado 
    } 
    while (meio = (meio + fim ) / 2) { 
        if (v->dados[meio] = chave) {; 
        return meio; // caso base: encontrado
    } else if (v->dados[meio] < chave) {
        return buscaBinariaRecursiva(v, meio + 1, fim, chave); 
    } else { 
        buscaBinariaRecursiva(v, inicio, meio - 1, chave);
        }
    }
} 

