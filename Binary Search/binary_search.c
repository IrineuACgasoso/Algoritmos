#include <stdlib.h>
#include <stdio.h>


int binary_Search(int searched, int *array, int array_size) {
    // Salva os índices inicial e final do array
    int front = 0;
    int back = array_size - 1;
    int current;

    // Enquanto front não chegar/passar de back
    while (front <= back) {
        // Avança o cursor para a metade do array
        current = (back + front) / 2;
        // Encontrou o número buscado
        if (searched == array[current]) {
            return current;
        }
        // Se o valor é menor que o encontrado, "corta" a metade da direita do array
        else if (searched < array[current]) {
            back = current - 1;
        }
        // Se o valor é maior que o encontrado, "corta" a metade da esquerda do array
        else {
            front = current + 1;
        }
    }
    // Caso não haja o valor
    return -1;
}


int main() {
    int size_array;
    printf("Tamanho do array: ");
    scanf("%d", &size_array);

    int array[size_array];
    printf("Digite os %d elementos ordenados:\n", size_array);
    for (int i = 0; i < size_array; i++) {
        scanf("%d", &array[i]); 
    }

    int valor_procurado;
    printf("Digite o valor procurado: ");
    scanf("%d", &valor_procurado);

    // Salva o índice retornado
    int resultado = binary_Search(valor_procurado, array, size_array);

    if (resultado != -1) {
        printf("Valor encontrado na posicao: %d\n", resultado);
    } else {
        printf("Valor nao encontrado.\n");
    }

    return 0;
}