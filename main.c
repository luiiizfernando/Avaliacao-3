#include <stdio.h>
#include <stdlib.h>
#include "com112_hash.h"

int menu();

int main()
{
    int tamanho, opcao = 0, cont = 0;
    struct aluno aux;
    Hash *tabela;
    while(opcao != 5)
    {
        opcao = menu();
        if (opcao == 1)
        {
            if(cont == 0)
            {
                printf("Digite o tamanho da tabela: ");
                scanf("%d", &tamanho);
                tabela = criaHash(tamanho);
                if (tabela == NULL) {
                    printf("Erro ao alocar memória.\n");
                    return 0;
                }
                cont++;
            }
            else
            {
                printf("Tabala Já criada.\n\n");
            }
        }
        if(opcao == 2)
        {
            tabela = criaHash(1);
            liberaHash(tabela);
            printf("Tabela Liberada\n");
        }
        if(opcao == 3)
        {
            if(cont == 0)
            {
                printf("Digite o tamanho da tabela: ");
                scanf("%d", &tamanho);
                tabela = criaHash(tamanho);
                if (tabela == NULL) {
                    printf("Erro ao alocar memória.\n");
                    return 0;
                }
                cont++;
            }
            if(cont == 1)
            {
                struct aluno al[tamanho];
                for (int i = 0; i < tamanho; i++)
                {
                    printf("Digite o número de matricula do %dª aluno: ", i + 1);
                    scanf("%d", &al[i].matricula);
                    printf("Nome: ");
                    scanf(" %s", &al[i].nome);
                    printf("Digite a n1: ");
                    scanf("%f", &al[i].n1);
                    printf("Digite a n2: ");
                    scanf("%f", &al[i].n2);
                }
                for (int i = 0; i < tamanho; i++)
                {
                    insereHash_SemColisao(tabela, al[i]);
                }
            }
        }
        if(opcao == 4)
        {
            int procurado;
            printf("Número de matricula do aluno procurado: ");
            scanf("%d", &procurado);
            printf("----------------------\n");
            buscaHash_SemColisao(tabela, procurado, &aux);
            printf("%s , %d\n", aux.nome, aux.matricula);
            printf("----------------------\n");
        }
        if(opcao == 5)
        {
            tabela = criaHash(1);
            liberaHash(tabela);
            return 0;
        }
    }

/*    struct aluno al, a[4] = {{12352,"Andre",9.5,7.8},//64
                             {7894,"Ricardo",7.5,8.7},//726
                             {3451,"Bianca",9.7,6.7},//379
                             {5293,"Ana",5.7,6.1}};//173

    int i;
    for(i=0; i < 4; i++){
        insereHash_SemColisao(tabela,a[i]);
    }

    printf("------------\n\n");

    buscaHash_SemColisao(tabela, 12352, &al);
    printf("%s, %d\n",al.nome,al.matricula);

    buscaHash_SemColisao(tabela, 3451, &al);
    printf("%s, %d\n",al.nome,al.matricula);

    buscaHash_SemColisao(tabela, 5293, &al);
    printf("%s, %d\n",al.nome,al.matricula);

    liberaHash(tabela);*/

    return 0;
}

int menu()
{
    int opcao;
    printf("1. Criar tabela hash\n");
    printf("2. Liberar tabela hash\n");
    printf("3. Inserir elemento (Sem colisão)\n");
    printf("4. Consultar elemento (sem colisão)\n");
    printf("5. Sair\n");
    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);

    return opcao;
}