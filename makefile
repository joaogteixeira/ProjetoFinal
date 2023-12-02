CXX = g++
CXXFLAGS = -std=c++11
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = teste

# Lista de arquivos de origem
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Lista de arquivos de cabeçalho
INCS = $(wildcard $(INCLUDE_DIR)/*.hpp)

# Lista de arquivos de objeto
OBJS = $(patsubst $(SRC_DIR)/%.cpp,%.o,$(SRCS))

TARGET = RetroNetflix
TEST_TARGET = teste

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Regra para compilar arquivos de objeto
%.o: $(SRC_DIR)/%.cpp $(INCS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

test: $(TEST_TARGET)

$(TEST_TARGET): $(OBJS) $(TEST_DIR)/$(TEST_TARGET).cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(TEST_DIR)/$(TEST_TARGET).cpp $(OBJS) -o $(TEST_TARGET)

.PHONY: test clean

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_TARGET)
