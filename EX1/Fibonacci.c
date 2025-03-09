#include <stdio.h>
#include <stdlib.h>

int fibo(int n);

int main(){

    int n = 0;

    printf("Insira um numero inteiro: ");
    scanf("%d",&n);

    for(int i = 0; i<n; i++){
        printf("[ %d, ", fibo(i));
    }
    printf("]");

}

int fibo(int n){
    if(  n == 0){
        return 0;
    } else if (n == 1)
    {
        return 1;
    } else {
        return fibo(n-1) + fibo (n-2);
    }
}

