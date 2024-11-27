/*Melhorias Implementadas:
Alunos: 
Pedro Antonio Pereira de Araujo
Saulo Contreras de Assis
Arthur Gomes de Albuquerque Labbê
João Pedro Oliveira Anhaia
Samuel Colaço Lira Carvalho

O QUE:
    Escrever um algoritmo em C para entrada de dados de uma placa de carro com 7 digitos sendo 3 letras, 4 números e listas as placas registradas.
COMO?:
    Por meio da entrada de dados do usuário, o algoritmo verifica e registra a placa digitada,e após isso ele pergunta ao usúario se quer digitar uma nova placa ou visualizar as placas registradas.
ALGORITMO:
*/

#include <stdio.h>  // Biblioteca padrão de entrada e saída
#include <string.h> // Biblioteca para manipulação de strings
#include <locale.h> // Biblioteca para configurar o idioma e região

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

    char placas[100][8]; 
    int numeros;         
    char letras[4];      
    int continuar;   // Variável para controlar o loop do programa (1 = continuar, 2 = sair)
    int total_placas = 0; 
    int escolha;        

    printf("=== Sistema de Registro de Placas ===\n");
    printf("Bem-vindo! Este programa permite registrar e visualizar placas de veículos.\n");

    do {
        // Exibe o menu principal
        printf("\n=== Menu Principal ===\n");
        printf("1 - Registrar uma nova placa\n");
        printf("2 - Ver todas as placas registradas\n");
        printf("=======================\n");
        printf("Escolha uma opção: ");
        fflush(stdin); 
        scanf("%d", &escolha);

        if (escolha == 1) { //Caso o usuário escolha registrar uma nova placa             
            if (total_placas >= 100) { // Verifica se o limite de placas foi atingido
                printf("Limite de placas registradas atingido.\n");
                break; // Quebra o loop se a condição for verdadeira
            }

            printf("Digite as três letras da placa do carro: ");
            scanf("%s", letras);

            // Verifica se a entrada contém exatamente 3 caracteres e se são letras maiúsculas
            if (strlen(letras) != 3 || !(letras[0] >= 'A' && letras[0] <= 'Z') || 
                !(letras[1] >= 'A' && letras[1] <= 'Z') || !(letras[2] >= 'A' && letras[2] <= 'Z')) {
                printf("As letras devem conter exatamente 3 caracteres e ser letras maiúsculas.\n");
                continue; // Retorna ao início do loop para nova entrada
            }

            printf("Digite os números da placa do carro (até 4 dígitos): ");
            scanf("%d", &numeros);

            // Verifica se foi digitado até 4 numeros
            if (numeros < 0 || numeros > 9999) {
                printf("Os números devem ter até 4 dígitos.\n");
                continue;
            }

             // Formata as letras e números como uma única string de placa
            sprintf(placas[total_placas], "%s%04d", letras, numeros);
            printf("Placa registrada: %s\n", placas[total_placas]); //Exibi as placas registradas
            total_placas++; // Incrementa o contador de placas registradas

        } else if (escolha == 2) { 
            mostrarPlacas(placas, total_placas); // Chama a função auxiliar para exibir as placas
        } else {
            printf("Opção inválida. Por favor, escolha 1 ou 2.\n"); // Caso o usuário insira uma opção inválida
            continue;
        }

        // Pergunta ao usuário se deseja continuar no menu principal
        printf("\nDeseja voltar ao menu principal? (1 = Sim, 2 = Não/Encerrar o programa): "); // Pergunta ao usuário se deseja continuar
        fflush(stdin); // Limpa o buffer do teclado
        scanf("%d", &continuar);

        // Se o usuário digitar 2, o loop terminará
    } while (continuar == 1); // O loop só continua se continuar for igual a 1

    // Finalização do programa com mensagens apropriadas
    if (total_placas > 0) {
        printf("\nVocê registrou %d placas. Até mais!\n", total_placas);
    } else {
        printf("\nNenhuma placa foi registrada. Até mais!\n");
    }

    return 0;
}
