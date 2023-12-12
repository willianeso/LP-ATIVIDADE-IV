#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*Exercício 2:
Crie uma função chamada "calcularMedia" que recebe como parâmetro uma struct "Aluno" com informações como: 
nome, data de nascimento, duas notas e média. e retorna a média das notas. Em seguida, crie um programa que 
declare um array de 5 alunos e utilize a função "calcularMedia" para imprimir a média de cada aluno. 
Também crie uma função para verificar se um aluno está aprovado ou reprovado sendo necessário média maior ou 
igual a 7,0 para aprovação.
*/

struct dados_do_aluno {
    char nome[100];
    int datadeNascimento;
    float notaUm;
    float notaDois;
    float media;

};

struct dados_do_aluno aluno[3];
int i;
char renome[40];
float j;

float calculandoMedia(int j) {
    aluno[j].media = (aluno[j].notaUm + aluno[j].notaDois) / 2;
    return aluno[j].media;

}

char AprovadoouNao(char *renome) {
    int j;

    for (i = 0; i < 3; i++) {
        if (strcmp(renome, aluno[i].nome) == 0) {
            j = i;
            j = calculandoMedia(j);

            if (j >= 7) {
                printf("Aprovado.");

            } else {
                printf("Reprovado");

            }
        }
    }
}

int main() {
    float mediaSeparada;

    setlocale(LC_ALL, "");

    for (i = 0; i < 3; i++) {

        printf("Digite os dados dos alunos: ");

        puts("");
        fflush(stdin);

        printf("Digite o nome do %dº aluno: ", 1 + i);
        gets(aluno[i].nome);

        fflush(stdin);

        printf("Digite o ano de nascimento de %s: ", aluno[i].nome);
        scanf("%d", &aluno[i].datadeNascimento);
        fflush(stdin);

        printf("Digite a nota de %s: ", aluno[i].nome);
        scanf("%f", &aluno[i].notaUm);
        fflush(stdin);

        printf("Digite a nota de %s: ", aluno[i].nome);
        scanf("%f", &aluno[i].notaDois);

        puts("");
    }

    system("cls");

    fflush(stdin);

    printf("Digite o nome do aluno que deseja verificar se está aprovado ou reprovado: \n");
    gets(renome);

    puts("");
    fflush(stdin);

    AprovadoouNao(renome);

    puts("");

    return 0;
}
