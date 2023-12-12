#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*Exercício 4: 

Modele uma struct "ContaBancaria" que represente uma conta bancária com número da conta, nome do titular, 
saldo e tipo de conta (poupança ou corrente). Implemente funções para depositar e sacar dinheiro da conta, 
bem como para imprimir o saldo atual. Crie um programa que utilize essas funções para simular operações 
bancárias. Crie um menu para as operações disponíveis.
*/

struct Conta_Bancaria
{
    int numerodaConta;
    char nomedoTitular[50];
    float saldo;
    int tipodeConta; // Alterei para int, pois parece representar um tipo numérico
};

struct Conta_Bancaria banco[999];
int i = 0;
int j = 0;
int k = 0;
int opcao;
char resposta[50];
int numerodaConta;
float valor;
float sacar;

// Função para deposito
float depositando(float valor_recebido, float salario_recebido)
{
    salario_recebido = salario_recebido + valor_recebido;
    return salario_recebido;
}

// Função para saque
float sacando(float saque_recebido, float salario_recebido)
{
    salario_recebido = salario_recebido - saque_recebido;
    return salario_recebido;
}

void imprimirSaldo()
{
    printf("Saldo atual: R$%.2f\n", banco[j].saldo);
}

int main()
{
    do
    {
        k = k + 1;
        printf("Digite o nome do titular: ");
        fgets(banco[k].nomedoTitular, sizeof(banco[k].nomedoTitular), stdin);

        printf("Digite o número da conta: ");
        scanf("%d", &banco[k].numerodaConta);

        printf("Digite seu saldo: R$ ");
        scanf("%f", &banco[k].saldo);

        printf("Escolha o tipo de conta 1 - Conta corrente, 2 - Conta poupança: ");
        scanf("%d", &banco[k].tipodeConta);

        getchar();

        puts("");

        printf("Deseja continuar cadastrando as contas? 'S' 'N' \n");
        printf("Digite 'S' para sim e 'N' para não: ");
        fgets(resposta, sizeof(resposta), stdin);

        puts("");

    } while (strcmp(resposta, "S\n") == 0 || strcmp(resposta, "S\n") == 0);

    // Exibindo o menu
    do
    {
        puts("");
        puts("");
        printf("Digite a conta para realizar as operações: ");
        scanf("%d", &numerodaConta);

        for (i = 1; i <= k; i++)
        {
            if (numerodaConta == banco[i].numerodaConta)
            {
                j = i;
                break;
            }
        }

        printf("\nMenu \n");
        printf("1. Depositar \n");
        printf("2. Sacar \n");
        printf("3. Consultar Saldo \n");
        printf("0. Sair\n ");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor para depósito: R$ ");
            scanf("%f", &valor);

            banco[j].saldo = depositando(valor, banco[j].saldo);

            puts("");

            printf("Deposito realizado com sucesso! \n");
            printf("Seu saldo atual é de R$ %.2f \n", banco[j].saldo);
            break;
        case 2:
            printf("Digite um valor para sacar: R$ ");
            scanf("%f", &sacar);

            banco[j].saldo = sacando(sacar, banco[j].saldo);

            puts("");

            printf("Saque realizado com sucesso! \n");
            printf("Seu saldo atual é R$ %.2f \n", banco[j].saldo);
            break;
        case 3:
            imprimirSaldo();
            break;
        case 0:
            printf("Saindo do programa. \n");
            break;
        default:
            break;
        }

    } while (opcao != 0);

    return 0;
}
