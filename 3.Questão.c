#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*Exercício 3:
Desenvolva uma struct "Produto" que contenha informações como nome, preço e quantidade em estoque. 
Em seguida, desenvolva um menu para facilitar a escolha das opções:

1 - Realizar uma compra
2 - Consultar estoque
3 - Sair do programa. 

Escreva funções necessárias para calcular o valor total em estoque do produto e para atualizar a quantidade 
em estoque com base em uma compra. Crie um programa que utiliza essas funções para um produto.
*/

struct produto_do_galpao
{
    char nome[500];
    float preco;
    int quantidadeEstoque;
};

int opcao;
float calculoFinal;
int i;
int j;
int k;
int produtoAchado = 0;
char nomedoProduto[200];
char resposta[200];
int precodoEstoque;
int estoqueAtualizado;
struct produto_do_galpao produto[500];

void menu()
{
    printf("\t\t Menu \n");
    printf("Digite 1 para realizar a compra \n");
    printf("Digite 2 para ver estoque \n");
    printf("Digite 3 para sair \n");
    scanf("%d", &opcao);

    puts("");
}

float calcularEstoque()
{
    calculoFinal = produto[j].preco * produto[j].quantidadeEstoque;
    return calculoFinal;
}

int atualizaEstoque()
{
    produto[j].quantidadeEstoque = produto[j].quantidadeEstoque + precodoEstoque;

    return produto[j].quantidadeEstoque;
}

int main()
{

    setlocale(LC_ALL, "portuguese");

    do
    {
        menu();

        switch (opcao)
        {
        case 1:
            do
            {
                k = k + 1;
                fflush(stdin);
                printf("Digite o nome do produto: ");
                gets(produto[k].nome);

                printf("Digite o preço do produto: ");
                scanf("%f", &produto[k].preco);

                printf("Digite a quantidade de produto: ");
                scanf("%d", &produto[k].quantidadeEstoque);
                puts("");

                getchar();

                printf("Quer continuar cadastrando produto? \n");
                printf("Digite 'S' para sim e 'N' para não: ");
                gets(resposta);

                fflush(stdin);

            } while (strcmp(resposta, "S") == 0);

            break;
        case 2:

            produtoAchado = 0;

            fflush(stdin);

            printf("Digite o nome do produto a que deseja consultar: ");
            gets(nomedoProduto);

            fflush(stdin);

            for (i = 0; i <= k; i++)
            {

                if (strcmp(nomedoProduto, produto[i].nome) == 0)
                {
                    produtoAchado = 1;
                    j = i;

                    printf("Quantidade atual no estoque: %d\n", produto[j].quantidadeEstoque);

                    fflush(stdin);

                    printf("\n Deseja tualizar estoque? \n");
                    printf("Digite 'S' para sim e 'N' para não: ");
                    gets(resposta);

                    fflush(stdin);

                    if (strcmp(resposta, "S") == 0)
                    {
                        printf("Qual valor para adicionar ao estoque? \n");
                        scanf("%d", &precodoEstoque);

                        atualizaEstoque();

                        printf("Estoque atualizado!");
                        printf("Estoque atual: %d\n", produto[j].quantidadeEstoque);
                    }
                }
            }

            if (produtoAchado == 0)
            {
                printf("Produto não encotrado.\n");
            }

            break;

        default:
            break;
        }

    } while (opcao != 3);

    return 0;
}
