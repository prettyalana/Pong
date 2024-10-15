# Replace this with the path you get from `brew info sfml`
SFML_PATH = /opt/homebrew/Cellar/sfml/2.6.1

# Replace "src" with the name of the folder where all your cpp code is
cppFileNames := $(shell find . -type f -name "*.cpp")

# Target executable
TARGET = bin/app

all: $(TARGET)

$(TARGET): $(cppFileNames)
	mkdir -p bin
	g++ $(cppFileNames) -I$(SFML_PATH)/include -o $(TARGET) -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

clean:
	rm -rf bin/*