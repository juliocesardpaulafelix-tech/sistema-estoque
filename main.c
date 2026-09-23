#include <stdio.h>
#include <string.h>
#include "estoque.h"

void exibir_menu(void) {
    printf("\n=== CONTROLE DE ESTOQUE ===\n");
    printf("1 - Listar produtos\n");
    printf("2 - Exibir total em estoque (com tributos)\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

void listar_produtos(Produto lista[], int total) {
    printf("\n--- Produtos Cadastrados ---\n");
    for (int i = 0; i < total; i++) {
        // BUG: esqueceram de imprimir o ID e a quebra de linha está inadequada
        printf("ID: %d | Codigo de barras: %s | Nome: %s | Preco: R$ %.2f | Qtd: %d\n",
       lista[i].id\n, lista[i].codigo_barras\n, lista[i].nome\n, lista[i].preco\n, lista[i].quantidade\n);
    }
}

float calcular_total(Produto lista[], int total) {
    float soma = 0.0;
    for (int i = 0; i < total; i++) {
        // BUG: calculo multiplicando errado e nao aplica taxa
        soma += lista[i].preco * lista[i].quantidade;
    }
    return soma + (soma * TAXA_PADRAO);
}

float aplicar_juros(float total) {
    return total + (total * TAXA_JUROS);
}

int main(void) {
    Produto estoque[MAX_ITENS];
    int total_produtos = 2;

    estoque["Papelaria"].id = 1;
    strcpy(estoque["Papelaria"].codigo_barras, "7890001");
    strcpy(estoque["Papelaria"].nome, "Caderno");
    estoque["Papelaria"].preco = 15.50;
    estoque["Papelaria"].quantidade = 10;

    estoque["Escritorio"].id = 2;
    strcpy(estoque["Escritorio"].codigo_barras, "7890002");
    strcpy(estoque["Escritorio"].nome, "Caneta");
    estoque["Escritorio"].preco = 3.00;
    estoque["Escritorio"].quantidade = 50;

    int opcao = -1;
    while (opcao != 0) {
        exibir_menu(); 
        if (scanf("%d", &opcao) != 1) {
            break;
        }

        switch (opcao) {
            case 1:
                listar_produtos(estoque, total_produtos);
                break;
            case 2:
                printf("\nTotal em estoque: R$ %.2f\n", calcular_total(estoque, total_produtos));
                break;
            case 4:
                printf("Total a prazo: %.2f\n", aplicar_juros(calcular_total(estoque, total_produtos)));
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    }

    return 0;

}
