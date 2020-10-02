CPP=gcc    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS= -lSDLmain -lSDL -lSDL_image -lSDL_ttf#Linker
EXEC=main #Nom du programme à modifier

all: ${EXEC}

main : game.o main.o 
	${CPP} $(CFLAGS) -o ${EXEC} game.o main.o ${LDFLAGS}

game.o: game.c constant.h game.h 
	${CPP} $(CFLAGS) -o game.o  -c game.c 

main.o: main.c game.h constant.h 
	${CPP} $(CFLAGS) -o main.o -c main.c 

clean:
	rm -fr *.o

mrproper: clean
	rm -fr ${EXEC}
