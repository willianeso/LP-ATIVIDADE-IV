#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*Exercício 5: 

Crie uma struct "Funcionario" com membros para nome, cargo e salário. Escreva uma função que recebe um array 
de funcionários e um cargo como parâmetro, e retorna a média salarial dos funcionários com esse cargo. 
Em seguida, implemente um programa que utiliza essa função para calcular e imprimir a média salarial dos 
programadores em uma empresa. */

struct funcionariosRegistros
{
    char nome[100];
    int cargo;
    float salario;
};

struct funcionariosRegistros funcionario[99];
int i;
int j;
int K;
int L;
char resposta[50];
int verCargo;
float mediaSalarialAnalista;
float mediaAnalistas;
float mediaProgramadores;
float mediaSalarialProgramador;

float calcularMediaSalarial(float salarioNovo)
{
    if (funcionario[K].cargo == 1)
    {
        mediaSalarialProgramador = (mediaSalarialProgramador + salarioNovo) / j;
        return mediaSalarialProgramador;
    }

    if (funcionario[K].cargo == 2)
    {
        mediaSalarialAnalista = (mediaSalarialAnalista + salarioNovo) / L;
        return mediaSalarialAnalista;
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    do
    {
        K = K + 1;
        fflush(stdin);
        printf("Digite o nome do funcionário: ");
        gets(funcionario[K].nome);

        printf("\nEscolha o CARGO: ");
        printf("\n1 - Programador");
        printf("\n2 - Analista \n");
        scanf("%d", &funcionario[K].cargo);

        printf("\nDigite o valor do salário: R$ ");
        scanf("%f", &funcionario[K].salario);

        if (funcionario[K].cargo == 1)
        {
            j += 1;
            mediaProgramadores = calcularMediaSalarial(funcionario[K].salario);

            printf("Média salarial de programadores R$ %.2f", mediaProgramadores);
        }
        else if (funcionario[K].cargo == 2)
        {
            L = L + 1;
            mediaAnalistas = calcularMediaSalarial(funcionario[K].salario);

            printf("Média salarial de analistas R$ %.2f", mediaAnalistas);
        }

        getchar();

        printf("\nContinuar cadastrando funcionários? [s/n] ");
        gets(resposta);

        fflush(stdin);
        puts("");

    } while (strcmp(resposta, "s") == 0);

    printf("Média salarial de programadores R$ %.2f", mediaProgramadores);
    printf("Média salarial de analistas R$ %.2f", mediaAnalistas);

    printf("Deseja ver a média salarial de qual cargo? 1 ou 2");
    scanf("%d", &verCargo);

    puts("");

    switch (verCargo)
    {
    case 1:
        printf("Média salarial de proramadores R$ %.2f", mediaProgramadores);
        break;

    case 2:
        printf("Média salarial de analistas R$ %.2f", mediaAnalistas);
        break;

    default:
        break;
    }

    return 0;
}
