/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int mdc(int x, int y);
void simplificar_fracao(int n, int d);

int main() {
    int a, b, c, d;
    char escolha;

    while (1) {
        printf("\n1. Somar\n");
        printf("2. Subtrair\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("9. Fim\n");
        printf("O que deseja? ");
        scanf(" %c", &escolha);

        if (escolha == '9') {
            break;
        }

        printf("Digite a primeira fração (numerador denominador): ");
        if (scanf("%d %d", &a, &b) != 2 || b == 0) {
            printf("Erro: entrada inválida ou denominador zero.\n");
            while (getchar() != '\n'); 
            continue;
        }

        printf("Digite a segunda fração (numerador denominador): ");
        if (scanf("%d %d", &c, &d) != 2 || d == 0) {
            printf("Erro: entrada inválida ou denominador zero.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (escolha) {
            case '1': simplificar_fracao(a * d + c * b, b * d); break;
            case '2': simplificar_fracao(a * d - c * b, b * d); break;
            case '3': simplificar_fracao(a * c, b * d); break;
            case '4': 
                if (c == 0) {
                    printf("Erro: divisão por zero.\n"); 
                    continue;
                }
                simplificar_fracao(a * d, b * c); 
                break;
            default: 
                printf("Opção inválida!\n"); 
                continue;
        }
    }
    return 0;
}

void simplificar_fracao(int n, int d) {
    if (n == 0) {
        printf("Resultado: 0\n");
        return;
    }
    int divisor = mdc(abs(n), abs(d));
    n /= divisor;
    d /= divisor;
    if (d < 0) {
        n = -n;
        d = -d;
    }
    printf("Resultado: %d/%d\n", n, d);
}

int mdc(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}
