#ifndef USER_H
#define USER_H

typedef struct email_t email;

typedef struct user_t{
    int id;
    struct email* inbox;
    int tamanhoinbox;

}user;

extern int numerodeusuarios;
extern user** users;

void cadastraUser(int);
void removeUser(int);

#endif
