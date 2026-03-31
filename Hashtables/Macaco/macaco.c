#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAMANHO_PRATELEIRA 10

struct No {
    char nome_fruta[50];
    int numero_frutas;
    struct No* proxima_fruta;
};

struct No* prateleira[TAMANHO_PRATELEIRA];

int funcao_Hash(char* nome_fruta) {
    int soma = 0;
    for (int i = 0; nome_fruta[i] != '\0'; i++) {
        soma += nome_fruta[i];
    }
    return soma % TAMANHO_PRATELEIRA;
}

void inserir_Fruta(char* nome_fruta, int valor) {
    int indice = funcao_Hash(nome_fruta);

    struct No* nova_fruta = malloc(sizeof(struct No));
    strcpy(nova_fruta->nome_fruta, nome_fruta);
    nova_fruta->numero_frutas = valor;

    nova_fruta->proxima_fruta = prateleira[indice];
    prateleira[indice] = nova_fruta;

    printf("Guardado: %s na caixa %d\n", nome_fruta, indice);
}

int buscar_Fruta(char* nome_fruta_buscada) {
    int indice = funcao_Hash(nome_fruta_buscada);
    struct No* andar_atual = prateleira[indice];

    while (andar_atual != NULL) {
        if (strcmp(andar_atual->nome_fruta, nome_fruta_buscada) == 0) {
            return andar_atual->numero_frutas;
        }
        andar_atual = andar_atual->proxima_fruta;
    }
    return -1;
}

void limpar_Prateleira() {
    for (int i = 0; i < TAMANHO_PRATELEIRA; i++) {
        struct No* andar_atual = prateleira[i];
        while (andar_atual != NULL) {
            struct No* proxima_fruta = andar_atual->proxima_fruta;
            free(andar_atual);
            andar_atual = proxima_fruta;
        }
        prateleira[i] = NULL;
    }
}


int main() {
    // Inicia a tabela vazia (NULL)
    for(int i = 0; i < TAMANHO_PRATELEIRA; i++) prateleira[i] = NULL;
    printf("Quantas frutas diferentes serão adicionadas?\n");
    int qtd_frutas, numero_frutas;
    char nome_fruta[50];
    scanf("%d", &qtd_frutas);
    printf("Insira suas frutas e suas respectivas qtds:\n");
    for (int i = 0; i < qtd_frutas; i++) {
        scanf("%s %d", nome_fruta, &numero_frutas);
        inserir_Fruta(nome_fruta, numero_frutas);
    }
    printf("Deseja buscar alguma fruta?\n");
    char resposta[5];
    scanf("%s", resposta);

    if (strcmp(resposta, "sim") == 0 || strcmp(resposta, "Sim") == 0) {
        printf("Qual a fruta buscada?\n");
        char fruta_buscada[20];
        scanf("%s", fruta_buscada);
        int qtd = buscar_Fruta(fruta_buscada);

        switch (qtd)
        {
        case -1:
            printf("Não há essa fruta na prateleira.\n"); 
            break;       
        default:
            printf("Temos %d %s.\n", qtd, fruta_buscada);
        }
    }

    limpar_Prateleira();
    
    return 0;
}