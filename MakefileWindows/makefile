# change application name here (executable output name)
TARGET=xaero.exe
 
# compiler
CC=clang
# warnings
WARN=-Wall

 
CCFLAGS=$(WARN)

SRC= main.c TAD_AUXILIAR/horario.c TAD/VOO.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS)

run:
	$(TARGET)

clean:
	del $(TARGET)
