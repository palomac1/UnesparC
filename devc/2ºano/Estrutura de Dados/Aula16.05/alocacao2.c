#include <stdio.h>
#include <stdlib.h>

int main() {
    int *valores; 
    int soma = 0;
    int n = 5; 
    float media = 0;

    valores = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valores[i]);

        soma += valores[i];
    }
    	
    	media = soma/5;
    	
    printf("Media dos valores: %f\n", media);
    printf("Soma dos valores: %d\n", soma);
    
    for(int i = 0; i < n; i++){
    	
    	if(media < valores[i]){
    		
    		printf("O valor %d e maior que a media\n", valores[i]);
    		
		} else if(media == valores[i]){
			
			printf("O valor %d e igual a media\n", valores[i]);
			
		} else {
			
			printf("O valor %d e menor que a media\n", valores[i]);
			
		}
	}

    free(valores); 
    return 0;
}