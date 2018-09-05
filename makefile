# change application name here (executable output name)
TARGET=xaero.exe
 
# compiler
CC=gcc
# warnings
WARN=-Wall

 
CCFLAGS=$(WARN)

SRC= main.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CCFLAGS) -lm

run:
	./$(TARGET)

clean:
	rm $(TARGET)