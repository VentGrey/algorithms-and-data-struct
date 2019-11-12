# --- C Compilers
CC = gcc
# -- Clang Alternative
CL = clang-8

# --- C++ Compilers
CPPC = g++

# --- Compiler Flags
CFLAGS = -O2 -Wall -lm

# --- C Directories
BIN_SRCH_DIR = binarysearch-tree/
BRT_FRC_DIR = Brute-Force/
C_FRT_DIR = C-Fractal/
DFS_BFS_DIR = DFS_BFS/
FIB_DIR = fibonacci/
HSH_DIR = Hashing/
HEAP_DIR = heap/
STC_DIR = Stack/
LHM_DIR = luhm-algorithm/

# --- C++ Directories
MTH_PSR = math-parser/

# --- OUTPUT DIRECTORY
OUT_DIR = bin/

# THIS FILE IS INNEFICIENT AND WILL COMPILE DIR BY DIR AND NOT
# RECURSIVELY

alone:
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS)  -o $(OUT_DIR)BinarySearch $(BIN_SRCH_DIR)binary_search_tree.c
	$(CC) $(CFLAGS)  -o $(OUT_DIR)SearchingElement $(BIN_SRCH_DIR)SearchingElement.c

	$(CC) $(CFLAGS) 	-o $(OUT_DIR)Tetromino $(BRT_FRC_DIR)tetromino.c

#	$(CC) $(CFLAGS) -lm	-o $(OUT_DIR)Mandelbrot $(C_FRT_DIR)fract.c

	$(CC) $(CFLAGS) 	-o $(OUT_DIR)Answer $(DFS_BFS_DIR)answer.c

	$(CC) $(CFLAGS) 	-o $(OUT_DIR)Fibonacci $(FIB_DIR)fibonacci.c

	$(CC) $(CFLAGS) 	-o $(OUT_DIR)h_answer $(HSH_DIR)h_answer.c
	$(CC) $(CFLAGS) 	-o $(OUT_DIR)HashingFunctions $(HSH_DIR)hashingfunctions.c

	$(CC) $(CFLAGS) 	-o $(OUT_DIR)MaxHeap $(HEAP_DIR)max_heap.c
	$(CC) $(CFLAGS) 	-o $(OUT_DIR)MinHeap $(HEAP_DIR)min_heap.c

	$(CC) $(CFLAGS) 	-o $(OUT_DIR)ParenMatch $(STC_DIR)ParenthesisMatching.c
	$(CC) $(CFLAGS) 	-o $(OUT_DIR)ReversePrint $(STC_DIR)ReversePrint.c

alone-clang:
	mkdir -p $(OUT_DIR)
	$(CL) -o $(OUT_DIR)BinarySearch $(BIN_SRCH_DIR)binary_search_tree.c
	$(CL) $(CFLAGS) 	-o $(OUT_DIR)SearchingElement $(BIN_SRCH_DIR)SearchingElement.c

	$(CL) $(CFLAGS) 	-o $(OUT_DIR)Tetromino $(BRT_FRC_DIR)tetromino.c

	$(CL) $(CFLAGS) 	-o $(OUT_DIR)Mandelbrot $(C_FRT_DIR)fract.c

	$(CL) $(CFLAGS) 	-o $(OUT_DIR)Answer $(DFS_BFS_DIR)answer.c

	$(CL) $(CFLAGS) 	-o $(OUT_DIR)Fibonacci $(FIB_DIR)fibonacci.c

	$(CL) $(CFLAGS) 	-o $(OUT_DIR)h_answer $(HSH_DIR)h_answer.c
	$(CL) $(CFLAGS) 	-o $(OUT_DIR)HashingFunctions $(HSH_DIR)hashingfunctions.c

	$(CL) $(CFLAGS) 	-o $(OUT_DIR)MaxHeap $(HEAP_DIR)max_heap.c
	$(CL) $(CFLAGS)	 -o $(OUT_DIR)MinHeap $(HEAP_DIR)min_heap.c

	$(CL) $(CFLAGS) 	-o $(OUT_DIR)ParenMatch $(STC_DIR)ParenthesisMatching.c
	$(CL) $(CFLAGS) 	-o $(OUT_DIR)ReversePrint $(STC_DIR)ReversePrint.c
all:
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS)  -o $(OUT_DIR)BinarySearch $(BIN_SRCH_DIR)binary_search_tree.c
	$(CC) $(CFLAGS)	 -o $(OUT_DIR)SearchingElement $(BIN_SRCH_DIR)SearchingElement.c

	$(CC) $(CFLAGS)	 -o $(OUT_DIR)Tetromino $(BRT_FRC_DIR)tetromino.c

	$(CC) $(CFLAGS)	 -o $(OUT_DIR)Mandelbrot $(C_FRT_DIR)fract.c

	$(CC) $(CFLAGS)	 -o $(OUT_DIR)Answer $(DFS_BFS_DIR)answer.c

	$(CC) $(CFLAGS)	 -o $(OUT_DIR)Fibonacci $(FIB_DIR)fibonacci.c

	$(CC) $(CFLAGS)	 -o $(OUT_DIR)h_answer $(HSH_DIR)h_answer.c
	$(CC) $(CFLAGS)	 -o $(OUT_DIR)HashingFunctions $(HSH_DIR)hashingfunctions.c

	$(CC) $(CFLAGS)	 -o $(OUT_DIR)MaxHeap $(HEAP_DIR)max_heap.c
	$(CC) $(CFLAGS)	 -o $(OUT_DIR)MinHeap $(HEAP_DIR)min_heap.c

	$(CC) $(CFLAGS)	 -o $(OUT_DIR)ParenMatch $(STC_DIR)ParenthesisMatching.c
	$(CC) $(CFLAGS)	 -o $(OUT_DIR)ReversePrint $(STC_DIR)ReversePrint.c

	$(CPPC) $(CFLAGS)  -c main.cpp stack.hpp -o $(OUT_DIR) parser main.o stack.hpp.gch $(MTH_PSR) main.cpp stack.hpp

all-clang:
	mkdir -p $(OUT_DIR)
	$(CL) $(CFLAGS)  -o $(OUT_DIR)BinarySearch $(BIN_SRCH_DIR)binary_search_tree.c
	$(CL) $(CFLAGS)	 -o $(OUT_DIR)SearchingElement $(BIN_SRCH_DIR)SearchingElement.c

	$(CL) $(CFLAGS)	 -o $(OUT_DIR)Tetromino $(BRT_FRC_DIR)tetromino.c

	$(CL) $(CFLAGS)	 -o $(OUT_DIR)Mandelbrot $(C_FRT_DIR)fract.c

	$(CL) $(CFLAGS)	 -o $(OUT_DIR)Answer $(DFS_BFS_DIR)answer.c

	$(CL) $(CFLAGS)	 -o $(OUT_DIR)Fibonacci $(FIB_DIR)fibonacci.c

	$(CL) $(CFLAGS)	 -o $(OUT_DIR)h_answer $(HSH_DIR)h_answer.c
	$(CL) $(CFLAGS)	 -o $(OUT_DIR)HashingFunctions $(HSH_DIR)hashingfunctions.c

	$(CL) $(CFLAGS)	 -o $(OUT_DIR)MaxHeap $(HEAP_DIR)max_heap.c
	$(CL) $(CFLAGS)	 -o $(OUT_DIR)MinHeap $(HEAP_DIR)min_heap.c

	$(CL) $(CFLAGS)	 -o $(OUT_DIR)ParenMatch $(STC_DIR)ParenthesisMatching.c
	$(CL) $(CFLAGS)	 -o $(OUT_DIR)ReversePrint $(STC_DIR)ReversePrint.c

	$(CL) $(CFLAGS)  -c main.cpp stack.hpp -o $(OUT_DIR) parser main.o stack.hpp.gch $(MTH_PSR) main.cpp stack.hpp

clean:
	rm -rf $(OUT_DIR)
