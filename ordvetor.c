#include "ordvetor.h"

//Função de criação do vetor
VETORORD* VETORD_create(int n, COMP* compara) {
    VETORORD* vetor = (VETORORD*) malloc(sizeof(VETORORD));
    vetor->N = n;
    vetor->P = 0;
    vetor->elems = (void**) malloc(n * sizeof(void*));
    vetor->comparador = compara;

    return vetor;
};

//Função de adição de elementos no vetor
void VETORD_add(VETORORD* vetor, void* newelem) {
	if (vetor->P < vetor->N) {
		int position = vetor->P;
		int aux;

		for (aux = 0; aux < vetor->P; aux++) {
			if (vetor->comparador(vetor->elems[aux], newelem) > 0) {
				position = aux;
				break;
			}
		}

		for (aux = vetor->P; aux > position; aux--) {
			vetor->elems[aux] = vetor->elems[aux - 1];
		}

		vetor->elems[position] = newelem;
		vetor->P++;
	}	
}

//Função de remoção do menor elemento do vetor
void* VETORD_remove(VETORORD* vetor) {
	void* minimun = vetor->elems[0];

	for (int i = 0; i < vetor->P - 1; i++) {
		vetor->elems[i] = vetor->elems[i + 1];
	}
	
	vetor->P--;

	return minimun;
}