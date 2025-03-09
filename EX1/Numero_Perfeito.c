#include <stdio.h>
#include <stdlib.h>

int verificar_numero(int n);

int main(){

    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    if(verificar_numero(n)){
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}

int verificar_numero(int n){
    int soma = 0;

    //Devo encontrar todos o divisores do numeros
    for ( int i = 1; i<n; i++){
        if(n % i == 0){
            soma+=i; //Adiciona o divisor
        }
    }

    return soma == n;
    


}