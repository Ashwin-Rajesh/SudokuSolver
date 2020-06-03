# Default target - build the executable
build:bin/Sudoku
.PHONY:build

# Run the executable
run:bin/Sudoku
	bin/Sudoku
.PHONY:run

# Delete contents of bin folder
clean:
	rm bin/*
.PHONY:clean

# Defining dependencies for the executable
bin/Sudoku:src/*.cpp src/*.hpp Makefile
	g++ -g src/*.cpp -o bin/Sudoku