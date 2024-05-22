#include <stdio.h>
#include <stdlib.h>

int main(){

    int arr[5] = {10, 20, 30, 40, 50};
    arr[2] = 100;
    char arrs[6] = {'G', 'e', 'e', 'k', 's', '\0'};

    printf("--- Elementos da Array --- \n");

    for(int i = 0; i < 5; i++){
        printf("%d\n", arr[i]);
    }

    printf("-------------------\n");

    int y = 0;

    // Enquanto arr[y] for diferente de 0, imprime a string
    while(arr[y]){
        printf("%c", arrs[y++]); // imprime a string e incrementa o valor de y
    }

    printf("\n");
    return 0;

}
