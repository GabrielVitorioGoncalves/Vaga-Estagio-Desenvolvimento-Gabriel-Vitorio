#include <stdio.h>
#include <stdlib.h>

int troca(int valor);

int main(){
    
    int valor;

    printf ("Digite um valor inteiro positivo: ");
    scanf("%d", &valor);

    if(valor <=0){
        printf("O valor deve ser um numero inteiro e positivo");
    } else {
        troca(valor);
    }
    
    
    return 0;
}

int troca(int valor){

    int n[] = {100,50,20,10,5,2,1};
    int q,i;

    printf("Valor : %d\n", valor);

    for(i = 0; i < 7; i++){ // passa por todas as notas
        q = valor / n[i]; // AQUI QUE CALCULA QUANTAS NOTAS PODEM SER USADAS DESSE VALOR
        if(q > 0) {
            printf ("%d notas(s) de %d\n", q , n[i]);
            valor -= q * n[i]; //AQUI atualiza o valor restante
        }
    }

}