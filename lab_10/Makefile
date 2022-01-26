CC = g++
DEBUG = -g -Wextra
LFLAGS = -Wall -std=c++11 $(DEBUG)
CFLAGS = -c $(LFLAGS)

BUILD_PATH = build
BIN_PATH = bin

LAB_NUM = 10

all: build

build: bootstrap HashTable.o BSTree.o
	$(CC) $(LFLAGS) -o $(BIN_PATH)/test$(LAB_NUM) build/HashTable.o test$(LAB_NUM).cpp 

buildalt: bootstrap HashTable.o BSTree.o
	$(CC) $(LFLAGS) -o $(BIN_PATH)/test$(LAB_NUM) build/HashTable.o test10std.cpp 

HashTable.o: HashTable.cpp show10.o HashTable.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

BSTree.o: BSTree.cpp show9.o BSTree.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

show10.o: show10.cpp HashTable.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

show9.o: show9.cpp BSTree.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

.PHONY: bootstrap
bootstrap:
	@mkdir -p ./{$(BUILD_PATH),$(BIN_PATH)}

.PHONY: clean
clean:
	@rm -rf $(BUILD_PATH)/* $(BIN_PATH)/*

.PHONY: run
run:
	@ ./bin/test$(LAB_NUM)