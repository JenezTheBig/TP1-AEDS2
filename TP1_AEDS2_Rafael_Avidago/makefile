CC=gcc
CFLAGS=-Wall -Wextra -g
OBJ=email.o user.o main.o

all: app

clean:
	rm *.o
	rm ./a.out

app: $(OBJ)
	$(CC) $(CFLAGS) -o app $(OBJ)

email.o: email.c email.h
	$(CC) $(CFLAGS) -c email.c

user.o: user.c user.h
	$(CC) $(CFLAGS) -c user.c

main.o: main.c email.h user.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f app $(OBJ)