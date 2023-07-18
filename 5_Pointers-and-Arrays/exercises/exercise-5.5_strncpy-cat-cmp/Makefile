OS = $(shell uname -s)

ifeq ($(OS), Darwin)
	CHECK_FLAGS = -lcheck
	CC_FLAGS = -fsanitize=address -g -std=c11  # Sanitizer
else
	CC_FLAGS = -g -std=c11
	CHECK_FLAGS = -lcheck -lsubunit -lm
endif
	

TARGET = 5.5_strn
CC = gcc 
TEST = test

IMAGE_NAME = ubuntu-leak

PREF_OBJ = ./

SRC = $(wildcard 5.5*.c)
OBJ = $(patsubst %.c, $(PREF_OBJ)%.o, $(SRC))

LIB = 5.5_strn

all: $(LIB).a

# 1. Library
$(LIB).a:
	$(CC) $(CC_FLAGS) -c $(SRC)
	ar rcs $(LIB).a $(OBJ)

# 2. Tests
$(TEST) : $(LIB).a
	$(CC) $(CC_FLAGS) $(TEST).c $(LIB).a $(CHECK_FLAGS) -o $(TEST)

run: $(TEST)
	./$(TEST)

# 3. Clean
clean: 
	rm -rf $(TARGET) $(PREF_OBJ)*.o *.a *.dSYM $(TEST)

# 4. Leaks
leaks : $(TEST)
	valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST)

# 5. Docker image
image:
	docker build . -t $(IMAGE_NAME)

# 6. Docker container
container: 
	docker run -it -v "$(shell pwd)":/home $(IMAGE_NAME)

# $(TARGET) : $(OBJ)
# 	$(CC) $(CC_FLAGS) $(OBJ) -o $(TARGET)

# $(PREF_OBJ)%.o : %.c
# 	$(CC) $(CC_FLAGS) -c $< -o $@
