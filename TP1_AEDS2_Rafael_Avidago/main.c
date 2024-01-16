#include "user.h"
#include "email.h"

#define MAX_USUARIOS 1000000

int main(){

    users = (user**) malloc(MAX_USUARIOS*sizeof(user*));
    int opcao, ID, prioridade;
    char conteudo[1024];

    while(1) {
        printf("~x~BEM VINDO AO E-MAIL~x~\n");
        printf("DIGITE O NUMERO DO PROCESSO QUE DESEJA REALIZAR\n");
        printf("1 - CADASTRO\n");
        printf("2 - REMOCAO DE USUARIO\n");
        printf("3 - ENVIAR EMAIL\n");
        printf("4 - CONSULTAR EMAIL\n");

        scanf("%d", &opcao);
        switch(opcao) {
            case 1: // cadastraUser
                printf("DIGITE O NUMERO DO NOVO ID A SER CRIADO\n");
                scanf("%d", &ID);
                cadastraUser(ID);
                break;

            case 2: // removeUser
                printf("DIGITE O NUMERO DO ID A PARA SER REMOVIDO\n");
                scanf("%d", &ID);
                removeUser(ID);
                break;

            case 3: // criaEmails
                printf("DIGITE O NUMERO DO ID PARA QUAL A MENSAGEM SERA ENVIADA\n");
                printf("[ID] [PRIORIDADE] [CONTEUDO]\n");
                scanf("%d %d %[^\n]s", &ID, &prioridade, conteudo);
                criaEmails(ID, prioridade, conteudo);
                break;

            case 4: // consultaEmail
                printf("DIGITE O NUMERO DO ID QUE DESEJA CONSULTAR\n");
                scanf("%d", &ID);
                consultaEmail(ID);
                break;

            default:
                return 0;
        }
    }
    return 0;
}
