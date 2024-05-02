#include <stdio.h>
#include<stdlib.h>

void mat(int mat[3][4],int vet[12]){
    int i, j, cont=0;
    for (i=0;i<3;i++){ 
        for (j=0;j<4;j++){
            scanf("%d",&mat[i][j]);
            vet[cont++] = mat[i][j];
            
        }
    }

    printf("Valores passados para vetor: ");
    for (i=0;i<12;i++){
        printf("%d ",vet[i]);
    }
}
  
int main(){
    int mat[3][4];
    int vet[12];
    mat(mat,vet);
}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Competidor{
	char nome[100];
	float nota;
	float grauDif;
};

int main(){
	int numCompet, i;
	struct Competidor compet;
	double somaNotas;
	float maior, menor;
		
	scanf("%d", &numCompet);

    while(numCompet--){
		scanf("%s %f", compet.nome, &compet.grauDif);
		
		for(i = 7, somaNotas = maior = 0., menor = 11.; i ;i--){
			scanf("%f", &compet.nota);
			if(compet.nota > maior) maior = compet.nota;
			if(compet.nota < menor) menor = compet.nota;
			somaNotas += compet.nota;
		}
		
		somaNotas -= maior + menor;
		
		printf("%s %.2lf\n", compet.nome, somaNotas*compet.grauDif);
	}
     	
	return 0;
}