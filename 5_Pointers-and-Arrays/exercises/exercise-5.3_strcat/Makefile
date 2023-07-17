TARGET = 5.3_strcat
CC = gcc 
CC_FLAGS = -fsanitize=address -g

PREF_OBJ = ./obj/

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, $(PREF_OBJ)%.o, $(SRC))

all: $(TARGET)

run: 
	./$(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(CC_FLAGS) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

clean : 
	rm -rf $(TARGET) $(PREF_OBJ)*.o