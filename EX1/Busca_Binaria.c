#include <stdio.h>
#include <stdlib.h>

int busca(int lista[], int tam, int a);

int main(){
    int lista [] = {5,12,18,23,45,70,89};
    int a = 23;
    int tam = sizeof(lista) / sizeof(lista[0]); //Pega o tamanho da lista
    
    int resultado = busca(lista, tam, a);

    printf(" %d", resultado);

    return 0;
}

int busca(int lista[], int tam, int a){
    
    int esquerda = 0, direita = tam -1;

    while (esquerda <= direita){
        int meio = (esquerda + direita)/2;

        if(lista[meio] == a){
            if(meio == 0 || lista[meio - 1] != a){
                return meio; //Retorna o indice da primeira ocorrencia
            }else {
                direita = meio - 1; // Continua buscando a esquerda
            }
        }  else if (lista [meio] < a){
            esquerda = meio + 1; // Buscando a direita
        } else {
            direita = meio - 1;// Buscando a esquerda
        }
    } 

    return -1; //Caso o "a" nao seja encontrado 

}