#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*Exerc�cio 1:
Crie uma struct Contato para representar informa��es de contatos, incluindo nome, n�mero de telefone e email.
Solicite que o usu�rio cadastre 3 contatos. Escreva uma fun��o que recebe um array de contatos e um nome como
par�metro, e retorna o n�mero de telefone correspondente a esse nome. Em seguida, implemente um programa que
utiliza essa fun��o para buscar e imprimir o n�mero de telefone de um contato espec�fico.
*/

struct dados_do_contato {
    char nome[500];
    char telefone[500];
    char email[500];
    
};

struct dados_do_contato contato[3];
int i;

char *conversor(char *renome) {
    int j;

    for (i = 0; i < 3; i++) {
        if (strcmp(renome, contato[i].nome) == 0) {
            j = i;
            return contato[j].telefone;

        }

    }

    return 0;
}

int main()
{

    setlocale(LC_ALL, "");

    char *c;
    char renome[500];

    for (i = 0; i < 3; i++) {
        printf("Digite o %dº nome: ", i + 1);
        gets(contato[i].nome);

        fflush(stdin);

        printf("Digite o telefone de %s: ", contato[i].nome);
        gets(contato[i].telefone);

        fflush(stdin);

        printf("Digite o email de %s: ", contato[i].nome);
        gets(contato[i].email);

        puts("");
        fflush(stdin);

    }

    system("cls");

    printf("Qual contato você deseja achar? ");

    puts("");

    gets(renome);
    fflush(stdin);

    c = conversor(renome);

    if (c == 0) {
        printf("O contato digitado não foi encontrado.\n");

    } else {
        printf("O número de %s é %s\n", renome, c);

    }

    return 0;
}
