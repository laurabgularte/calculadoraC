#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BIN_LEN 32 // Tamanho maximo para numeros binarios

int main() {
    char operacao;
    int base;
    int num1, num2, resultado;
    char bin1[MAX_BIN_LEN], bin2[MAX_BIN_LEN], bin_result[MAX_BIN_LEN];

    // Escolher o sistema numerico
    printf("Escolha o sistema numerico:\n");
    printf("1 - Binario\n2 - Decimal\n3 - Hexadecimal\n");
    printf("Digite a base (1, 2 ou 3): ");
    scanf("%d", &base);

    // Validar a base escolhida
    if (base < 1 || base > 3) {
        printf("Base invalida\n");
        return 1;
    }

    // Solicitar a operacao
    printf("Digite o simbolo da operacao que deseja realizar: +, -, *, / ou %%: ");
    scanf(" %c", &operacao);

    // Verificar se a operacao eh valida
    if (operacao != '+' && operacao != '-' && operacao != '*' && operacao != '/' && operacao != '%') {
        printf("Operacao invalida\n");
        return 1;
    }

    // Solicitar os numeros
    if (base == 1) {
        // Ler numeros binarios como strings
        printf("Digite o primeiro numero em binario: ");
        scanf("%s", bin1);
        printf("Digite o segundo numero em binario: ");
        scanf("%s", bin2);

        // Converter numeros binarios para decimal
        num1 = strtol(bin1, NULL, 2);
        num2 = strtol(bin2, NULL, 2);
    } else if (base == 2) {
        printf("Digite o primeiro numero em decimal: ");
        scanf("%d", &num1);
        printf("Digite o segundo numero em decimal: ");
        scanf("%d", &num2);
    } else if (base == 3) {
        printf("Digite o primeiro numero em hexadecimal: ");
        scanf("%x", &num1);
        printf("Digite o segundo numero em hexadecimal: ");
        scanf("%x", &num2);
    }

    // Processar a operacao escolhida
    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("Erro: divisao por 0\n");
                return 1;
            }
            break;
        case '%':
            if (num2 != 0) {
                resultado = num1 % num2;
            } else {
                printf("Erro: divisao por 0\n");
                return 1;
            }
            break;
        default:
            printf("Operacao invalida\n");
            return 1;
    }

    // Exibir o resultado na base escolhida
    if (base == 1) {
        // Converter o resultado para binario
        itoa(resultado, bin_result, 2);
        printf("Resultado em binario: %s\n", bin_result);
    } else if (base == 2) {
        printf("Resultado em decimal: %d\n", resultado);
    } else if (base == 3) {
        printf("Resultado em hexadecimal: %X\n", resultado);
    }

    return 0;
}

