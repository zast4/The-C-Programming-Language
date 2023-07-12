TARGET = calc
CC = gcc 
CC_FLAGS = -c

PREF_OBJ = ./obj/

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, $(PREF_OBJ)%.o, $(SRC))

all: $(TARGET) run

run: 
	./$(TARGET)

$(TARGET) : $(OBJ)
	$(CC) -g $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : %.c
	$(CC) $(CC_FLAGS) $< -o $@

clean : 
	rm -rf $(TARGET) $(PREF_OBJ)*.o