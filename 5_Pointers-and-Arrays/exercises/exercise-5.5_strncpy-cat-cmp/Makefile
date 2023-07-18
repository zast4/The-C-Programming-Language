TARGET = 5.5_strn
CC = gcc 
# CC_FLAGS = -fsanitize=address -g -std=c11  # Sanitizer
CC_FLAGS = -g -std=c11
CHECK_FLAGS = -lcheck
TEST = test

PREF_OBJ = ./

SRC = $(wildcard 5.5*.c)
OBJ = $(patsubst %.c, $(PREF_OBJ)%.o, $(SRC))

LIB = 5.5_strn

all: $(TARGET)

# 1. Library
$(LIB).a:
	$(CC) $(CC_FLAGS) -c $(SRC)
	ar rcs $(LIB).a $(OBJ)

# 2. Tests
$(TEST) : $(LIB).a
	$(CC) $(CC_FLAGS) $(TEST).c $(LIB).a $(CHECK_FLAGS) -o $(TEST)
	./$(TEST)

# 3. Clean
clean : 
	rm -rf $(TARGET) $(PREF_OBJ)*.o *.a $(TEST)

# 4. Leaks



# $(TARGET) : $(OBJ)
# 	$(CC) $(CC_FLAGS) $(OBJ) -o $(TARGET)

# $(PREF_OBJ)%.o : %.c
# 	$(CC) $(CC_FLAGS) -c $< -o $@
