#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

//Função de comparação
int myCOMP(void* x, void* y){
	int ptx = *((int*)x);
	int pty = *((int*)y);

	if(ptx < pty) {
		return -1;
	} else if(ptx > pty) {
		return 1;
	} else {
		return 0;
	}
}

//Print para a estrutura
void print(void** vet, int P){
	int i;
	printf("TAMANHO DO VETOR: %d\n", P);
	for(i = 0; i < P; i++){
		printf("%d ", *((int*)vet[i]));
	}
	printf("\n");
}

int main(){
   	VETORORD* vet = VETORD_create(10, myCOMP);
   	
   	int* x;
   	int i;
   	int meu_vetor[10] = {5, 3, 7, 1, 9, 2, 8, 4, 6, 0};

   	printf("ADICIONANDO NUMEROS... \n");
	for(i = 0; i < 10; i++){
		x = malloc(sizeof(int));
		*x = meu_vetor[i];
		VETORD_add(vet, x);
	}
	
	print(vet->elems, vet->P);
	
  	printf("REMOVENDO O MENOR!\n");
  	VETORD_remove(vet);
  	
	print(vet->elems, vet->P);
   
	return 0;  
}
