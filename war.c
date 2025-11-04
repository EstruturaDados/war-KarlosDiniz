// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.

#include <stdio.h>
#include <string.h>

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.

#define MAX_TERRITORIOS 5
#define TAM_STRING 50

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.

struct Territorio {
    char nome[TAM_STRING];
    char corExercito[TAM_STRING];
    int qtdTropas;
};

// --- Função para limpar o buffer de entrada ---
void LimparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função Principal ---
int main() {
    struct Territorio territorios[MAX_TERRITORIOS];

    printf("========================================\n");
    printf("   WAR ESTRUTURADO - CADASTRO INICIAL \n");
    printf("========================================\n\n");

    // Cadastro de territórios
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf(" --- Cadastro de Território %d --- \n", i + 1);

        printf("Nome do Território: ");
        fgets(territorios[i].nome, TAM_STRING, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Cor do Exército (ex.: Azul, Verde, Amarelo, Branco, Vermelho...): ");
        fgets(territorios[i].corExercito, TAM_STRING, stdin);
        territorios[i].corExercito[strcspn(territorios[i].corExercito, "\n")] = '\0';

        printf("Número de Tropas: ");
        scanf("%d", &territorios[i].qtdTropas);
        LimparBufferEntrada();

        printf("\n");
    }

    // Exibe os 5 territórios cadastrados
    printf("\n=======================================================\n");
    printf("             MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("=======================================================\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("TERRITÓRIO %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Dominado por: %s\n", territorios[i].corExercito);
        printf("Tropas: %d\n", territorios[i].qtdTropas);
        printf("-----------------------------------------\n");
    }

    printf("\nCadastro concluído!!!\n");

    return 0;
}

