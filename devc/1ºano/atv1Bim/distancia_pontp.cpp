#include<stdlib.h>
#include<stdio.h>
#include<math.h> //Operações matemáticas
main(){
	float x1, y1; //Coordenadas para achar a distância entre 2 pontos
	float x2, y2;
	float q1, q2, dist;
	
	printf("Insira as coordenadas: \n");
	printf("x1: ");
	scanf("%f",&x1);
	
	printf("y1: ");
	scanf("%f",&y1);
	
	printf("x2: ");
	scanf("%f",&x2);
	
	printf("y2: ");
	scanf("%f",&y2);
	
	q1 = pow(x2-x1, 2);
	q2 = pow(y2-y1, 2);
	dist = sqrt(q1+q2);
	printf("Distancia entre os dois pontos: %f \n", dist);
	
	system("pause");
}
