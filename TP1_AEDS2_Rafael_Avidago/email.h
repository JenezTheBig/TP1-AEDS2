#ifndef EMAIL_H
#define EMAIL_H

#define MAX_PRI 9

typedef struct email_t {
    int pri;
    char conteudo[1024];
    int numdeEmails;
    struct email_t* prox;
} email;

void criaEmails(int, int, char*);
void consultaEmail(int);

#endif