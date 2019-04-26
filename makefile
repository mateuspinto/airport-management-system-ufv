# change application name here (executable output name)
TARGET=xaero.o

# compiler
CC=gcc
CCO=clang
# warnings
WARN=-Wall


CCFLAGS=$(WARN)

SRC= main.c TAD_AUXILIAR/horario.c TAD/VOO.c TAD/LISTA_DE_VOOS.c TAD/ITEM_MATRIZ.c TAD/MATRIZ_VOOS.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm

run:
	./$(TARGET)

clear:
	rm $(TARGET)

clang:
	$(CCO) -o $(TARGET) $(SRC) $(CCFLAGS) -lm -O3
