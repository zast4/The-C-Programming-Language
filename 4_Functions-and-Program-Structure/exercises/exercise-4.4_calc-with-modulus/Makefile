GCC			:= gcc
GCC_FLAGS	:= -g

BIN		:= .
SRC		:= .

EXECUTABLE	:= main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.c
	$(GCC) $(GCC_FLAGS) $^ -o $@

clean: 
	-rm *.main