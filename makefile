# change application name here (executable output name)
TARGET=xaero

# compiler
CC=gcc
# warnings
WARN=-Wall


CCFLAGS=$(WARN)

SRC= main.c TAD_AUXILIAR/horario.c TAD/VOO.c TAD/LISTA_DE_VOOS.c TAD/ITEM_MATRIZ.c TAD/MATRIZ_VOOS.c TAD_AUXILIAR/lista_encadeada_random.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm

run:
	./$(TARGET)

clean:
	rm $(TARGET)
