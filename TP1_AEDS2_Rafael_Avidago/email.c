#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "email.h"

void criaEmails(int ID, int prioridade, char *conteudo)
{
    user *destino = NULL;
    for (int i = 0; i < numerodeusuarios; i++)
    {
        if (users[i]->id == ID)
        {
            destino = users[i];
        }
    }

    if (destino == NULL)
    {
        printf("ERRO: CONTA DE DESTINO %d INEXISTENTE\n", ID);
        return;
    }
    // cria um novo email
    email *novoemail = (email *)malloc(sizeof(email));
    novoemail->pri = prioridade;
    strncpy(novoemail->conteudo, conteudo, 1019); // 1024 - 5 para adicao da palavra FIM
    strcat(novoemail->conteudo, " FIM");
    novoemail->numdeEmails = destino->tamanhoinbox + 1;

    novoemail->prox = destino->inbox;
    destino->inbox = novoemail;
    destino->tamanhoinbox++;

    printf("OK: EMAIL ENVIADO PARA A CONTA %d COM A PRIORIDADE %d\n", ID, prioridade);
}

void consultaEmail(int ID)
{
    user *u = NULL;
    for (int i = 0; i < numerodeusuarios; i++)
    {
        if (users[i]->id == ID)
        {
            u = users[i];
            break;
        }
    }
    if (u == NULL)
    {
        printf("ERRO: CONTA %d NAO EXISTE\n\n", ID);
        return;
    }
    if (u->inbox == NULL)
    {
        printf("CONSULTA %d: CAIXA DE ENTRADA VAZIA\n\n", ID);
        return;
    }

    // Criar uma lista auxiliar para armazenar os emails do usuário ordenados por prioridade
    email *emailOrdem[MAX_PRI + 1] = {NULL}; // +1 para incluir a prioridade 0
    email *e = u->inbox;
    while (e != NULL)
    {
        email *prox = e->prox;
        e->prox = NULL;
        email *atual = emailOrdem[e->pri];
        if (atual == NULL)
        {
            emailOrdem[e->pri] = e;
        }
        else
        {
            while (atual->prox != NULL)
            {
                atual = atual->prox;
            }
            atual->prox = e;
        }
        e = prox;
    }

    // Imprime os emails ordenados por prioridade 
    for (int pri = MAX_PRI; pri >= 0; pri--)
    {
        email *atual = emailOrdem[pri];
        while (atual != NULL)
        {
            printf("CONSULTA %d: %d %s\n", ID, pri, atual->conteudo);
            email *prox = atual->prox;
            free(atual);
            atual = prox;
        }
    }

    // Limpar a caixa de entrada do usuário
    u->inbox = NULL;
    u->tamanhoinbox = 0;
}