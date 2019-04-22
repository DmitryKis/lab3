CFLAGS = -Wall -Werror 
OBJ = g++ $(CFLAGS) -c $< -o $@

.PHONY: clean

all:folder folder2 bin/geometry.exe bin/test

folder:
	mkdir -p build 

folder2:
	mkdir -p bin 

bin/geometry.exe : build/main.o build/getters.o build/printTriangle.o build/printcircle.o build/printPoligon.o build/circle_intersects.o build/persistens.o build/proverka.o build/testing.o 
	g++ $(CFLAGS) $^ -o $@

build/main.o: src/main.cpp src/front.h 
	$(OBJ)

build/getters.o: src/getters.cpp src/front.h
	$(OBJ)

build/printTriangle.o: src/printTriangle.cpp src/front.h
	$(OBJ)

build/printcircle.o: src/printcircle.cpp src/front.h
	$(OBJ)

build/printPoligon.o: src/printPoligon.cpp src/front.h
	$(OBJ)

build/circle_intersects.o: src/circle_intersects.cpp src/front.h
	$(OBJ)

build/persistens.o: src/persistens.cpp src/front.h
	$(OBJ)

build/proverka.o: src/proverka.cpp src/front.h
	$(OBJ)

build/testing.o: src/testing.cpp src/front.h
	$(OBJ)

bin/testing: build/testing.o
	g++ -Wall -Werror build/testing.o -o bin/testing

build/testing.o: src/testing.cpp 
	g++ -Wall -Werror -c src/testing.cpp -o build/testing.o -Ithirdparty
