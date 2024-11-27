/*Melhorias Implementadas:
Alunos: 
Pedro Antonio Pereira de Araujo
Saulo Contreras de Assis
Arthur Gomes de Albuquerque Labbê
João Pedro Oliveira Anhaia
Samuel Colaço Lira Carvalho


Função mostrarPlacas: Modularização do código para exibir placas, tornando-o mais organizado.

Menu com formato mais claro: Melhor apresentação do menu, usando uma interface mais amigável.

Validação de entradas: Adição de validação de escolha no menu e confirmação para sair.

Remoção de limite fixo de 20 placas: Aumentado para até 100 placas(PORQUE SIM :]).

Mensagem final personalizada: Exibe o número de placas registradas ao encerrar o programa.
Limpeza do buffer (fflush(stdin)): Previne problemas ao processar entradas consecutivas

Abstração: on
O QUE:
    Escrever um algoritmo em C para entrada de dados de uma placa de carro com 7 digitos sendo 3 letras, 4 números e listas as placas registradas.
COMO?:
    Por meio da entrada de dados do usuário, o algoritmo verifica e registra a placa digitada,e após isso ele pergunta ao usúario se quer digitar uma nova placa ou visualizar as placas registradas.
ALGORITMO:
*/
#include <stdio.h>  // Biblioteca padrão de entrada e saída
#include <string.h> // Biblioteca para manipulação de strings
#include <locale.h> // Biblioteca para configurar o idioma e região

// Função auxiliar para mostrar as placas registradas
void mostrarPlacas(char placas[][8], int total) {
    if (total == 0) { // Verifica se não há placas registradas
        printf("Nenhuma placa registrada até o momento.\n");
    } else {
        printf("Placas registradas:\n");
        for (int i = 0; i < total; i++) { // Percorre o array de placas
            printf("%s\n", placas[i]); // Exibe cada placa registrada
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura o idioma para Português

    // Criação de um array para armazenar até 100 placas
    // Cada placa contém 7 caracteres (3 letras + 4 números) e 1 caractere nulo
    char placas[100][8]; 
    int numeros;         // Variável para armazenar os números da placa (até 4 dígitos)
    char letras[4];      // Variável para armazenar as letras da placa (3 caracteres + 1 nulo)
    int continuar = 1;   // Variável para controlar o loop do programa (1 = continuar, 2 = sair)
    int total_placas = 0; // Contador de placas registradas no sistema
    int escolha;         // Variável para armazenar a opção do usuário no menu principal

    // Mensagem inicial do programa
    printf("=== Sistema de Registro de Placas ===\n");
    printf("Bem-vindo! Este programa permite registrar e visualizar placas de veículos.\n");

    // Início do loop principal
    do {
        // Exibe o menu principal com as opções disponíveis
        printf("\n=== Menu Principal ===\n");
        printf("1 - Registrar uma nova placa\n");
        printf("2 - Ver todas as placas registradas\n");
        printf("=======================\n");
        printf("Escolha uma opção: ");
        fflush(stdin); // Limpa o buffer do teclado para evitar problemas na leitura
        scanf("%d", &escolha); // Lê a escolha do usuário

        if (escolha == 1) { // Caso o usuário escolha registrar uma nova placa
            // Verifica se o limite de placas foi atingido
            if (total_placas >= 100) {
                printf("Limite de placas registradas atingido.\n");
                break; // Encerra o loop caso o limite tenha sido atingido
            }

            // Solicita ao usuário que insira as letras da placa
            printf("Digite as três letras da placa do carro: ");
            scanf("%s", letras);

            // Verifica se a entrada contém exatamente 3 caracteres e se são letras maiúsculas
            if (strlen(letras) != 3 || !(letras[0] >= 'A' && letras[0] <= 'Z') || 
                !(letras[1] >= 'A' && letras[1] <= 'Z') || !(letras[2] >= 'A' && letras[2] <= 'Z')) {
                printf("As letras devem conter exatamente 3 caracteres e ser letras maiúsculas.\n");
                continue; // Retorna ao início do loop para nova entrada
            }

            // Solicita ao usuário que insira os números da placa
            printf("Digite os números da placa do carro (até 4 dígitos): ");
            scanf("%d", &numeros);

            // Verifica se os números estão no intervalo permitido (0 a 9999)
            if (numeros < 0 || numeros > 9999) {
                printf("Os números devem ter até 4 dígitos.\n");
                continue; // Retorna ao início do loop para nova entrada
            }

            // Formata as letras e números como uma única string de placa
            sprintf(placas[total_placas], "%s%04d", letras, numeros);

            // Exibe a placa registrada ao usuário
            printf("Placa registrada: %s\n", placas[total_placas]);
            total_placas++; // Incrementa o contador de placas registradas

        } else if (escolha == 2) { // Caso o usuário escolha visualizar as placas registradas
            // Chama a função auxiliar para exibir as placas
            mostrarPlacas(placas, total_placas);

        } else { // Caso o usuário insira uma opção inválida
            printf("Opção inválida. Por favor, escolha 1 ou 2.\n");
            continue; // Retorna ao início do loop
        }

        // Pergunta ao usuário se deseja continuar no menu principal
        printf("\nDeseja voltar ao menu principal? (1 = Sim, 2 = Não): ");
        fflush(stdin); // Limpa o buffer do teclado para evitar problemas na leitura
        scanf("%d", &continuar);

        // Confirma se o usuário realmente deseja sair do programa
        if (continuar != 1) {
            printf("Tem certeza que deseja sair? (1 = Sim, 2 = Não): ");
            fflush(stdin); // Limpa o buffer do teclado
            scanf("%d", &continuar);
        }

    } while (continuar == 1); // Continua o loop enquanto o usuário escolher continuar

    // Finalização do programa com mensagens apropriadas
    if (total_placas > 0) { // Caso tenham sido registradas placas
        printf("\nVocê registrou %d placas. Até mais!\n", total_placas);
    } else { // Caso nenhuma placa tenha sido registrada
        printf("\nNenhuma placa foi registrada. Até mais!\n");
    }

    return 0; 
}