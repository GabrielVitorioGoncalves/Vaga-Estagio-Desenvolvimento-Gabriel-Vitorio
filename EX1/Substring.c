#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int centro(char *s, int esquerda, int direita, int *inicio);

void maior(char *s, char *resultado);

int main(){

    char string[] ="babad";
    char resultado[100];

    maior(string,resultado);

    printf("%s", resultado);

    return 0;
}

int centro(char *s, int esquerda, int direita, int *inicio){
    while(esquerda >= 0 && direita < strlen(s) && s[esquerda] == s[direita])
    {
        esquerda--;
        direita++;
    }
    *inicio = esquerda + 1; // faz o inicio certo do palindromo
    return direita - esquerda - 1; // retorna o tamanho do palindromo
}

void maior(char *s, char *resultado){
    int n = strlen(s);
    if(n == 0){
        strcpy(resultado, "");
        return;
    }

    int inicio = 0, maxLen = 1;

    for(int i = 0; i < n; i++){
        int inicio1, inicio2;

        int len1 =  centro(s,i,i,&inicio1);

        int len2 =  centro(s,i,i+1,&inicio2);

        if(len1> maxLen){
            maxLen = len1;
            inicio = inicio1;
        }
        if(len2>maxLen){
            maxLen = len2;
            inicio = inicio2;
        }
    }

    strncpy(resultado, s+ inicio, maxLen);
    resultado[maxLen] = '\0';
}