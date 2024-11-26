CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
LDFLAGS =

SRC_DIR = src
OBJ_DIR = lib
BIN_DIR = bin

SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/dna.cpp $(SRC_DIR)/chromosome.cpp $(SRC_DIR)/gene.cpp
OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/dna.o $(OBJ_DIR)/chromosome.o $(OBJ_DIR)/gene.o
EXEC = $(BIN_DIR)/program.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)