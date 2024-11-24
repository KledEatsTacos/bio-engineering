CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
LDFLAGS =

SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/dna.cpp $(SRC_DIR)/chromosome.cpp $(SRC_DIR)/gene.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = program.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)