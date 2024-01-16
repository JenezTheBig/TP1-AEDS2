#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "email.h"

#define MAX_USUARIOS 1000000

int numerodeusuarios = 0;
user** users;

void cadastraUser(int ID){
    for(int i=0; i<numerodeusuarios; i++){
        if(users[i]->id == ID){
            printf("ERRO: CONTA %d JA EXISTENTE\n", ID);
            return;
        }
    }

    if(numerodeusuarios < MAX_USUARIOS){ 
        user* novouser = (user*) malloc(sizeof(user));
        novouser->id = ID;
        novouser->inbox = NULL;
        novouser->tamanhoinbox = 0;
        users[numerodeusuarios] = novouser;
        numerodeusuarios++;
        printf("OK: CONTA %d CADASTRADA\n", ID);
    }else {
        printf("ERRO: LIMITE DE CONTAS EXCEDIDO\n");
    }
}

void removeUser(int ID){
    int aux = -1;//indice do user
    for (int i=0; i<numerodeusuarios; i++){
        if(users[i]->id == ID){
            aux = i;
            break;
        }
    }

    if(aux == -1){
        printf("ERRO: CONTA %d INEXISTENTE\n", ID);
        return;
    }

    email* auxemail = users[aux]->inbox;
    while(auxemail != NULL){
        email* temp = auxemail;
        auxemail = auxemail->prox;
        free(temp);
    }

    free(users[aux]);

    for(int i = aux; i < numerodeusuarios-1; i++){
        users[i] = users[i+1];
    }

    numerodeusuarios--;
    printf("OK: CONTA %d REMOVIDA\n", ID);
}
