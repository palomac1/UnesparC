#include <stdlib.h>
#include <stdio.h>

// Ponteiro: aponta para um endereço de memória.
// ptr: endereço da variavel
// &ptr: endereço de ptr

int main (){
	
	//valor é variavel que será apontado pelo ponteiro
	int valor = 27;

	// *ptr: apontado por, conteudo do endereço da var que ptr aponta
	int *ptr;

	//atribuindo o endereço da variável valor ao ponteiro
	ptr = &valor;
	
	printf("Utilzando ponteiro\n\n");
	printf("Conteudo da variavel valor: %d\n", valor);
	printf("Endereco da variavel valor: %x\n", &valor);//x mostra hexadecimal
	printf("Conteudo da variavel ponteiro ptr: %x\n", ptr);//Conteudo da variavela
	
	return 0;
	
}