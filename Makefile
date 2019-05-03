CFLAGS = -Wall -Werror
OBJ = g++ $(CFAGS)  -c $< -o $@
TEST = g++ $(GFAGS) -I thirtdparty/catch2 -c $< -o $@
.PHONY: clean

all: folder1 folder2 folder3 folder4  bin/geometry.exe 

folder1:
	mkdir -p build

folder2:
	mkdir -p bin

folder3:
	mkdir -p build/src

folder4:
	mkdir -p build/test


bin/geometry.exe: build/src/main.o build/src/circle_intersects.o build/src/printCircle.o build/src/printPoligon.o build/src/printTriangle.o build/src/proverka.o build/src/proverka_perecech_otrezkov.o build/src/input_data.o build/src/areCollinear.o build/src/getMin.o build/src/getMax.o build/src/prijectionsIntersect.o build/src/getSlope.o build/src/getYIntercept.o build/src/getCos.o build/src/testing.o build/src/perpendicular.o build/src/distan.o build/src/prov_data.o build/src/print_posle_prov.o

	g++ $(CFLAGS) $^ -o $@

build/src/main.o: src/main.c src/geometry.h src/figure.h
	$(OBJ)

build/src/circle_intersects.o: src/circle_intersects.c src/geometry.h
	$(OBJ)

build/src/printCircle.o: src/printCircle.c src/geometry.h
	$(OBJ)

build/src/printPoligon.o: src/printPoligon.c src/geometry.h
	$(OBJ)

build/src/printTriangle.o: src/printTriangle.c src/geometry.h
	$(OBJ)

build/src/proverka.o: src/proverka.c src/geometry.h
	$(OBJ)

build/src/proverka_perecech_otrezkov.o: src/perecechotrezkov.c src/geometry.h
	$(OBJ)

build/src/input_data.o: src/input_data.c src/geometry.h
	$(OBJ)	

build/src/areCollinear.o: src/areCollinear.c src/geometry.h
	$(OBJ)

build/src/getMin.o: src/getMin.c src/geometry.h
	$(OBJ)

build/src/getMax.o: src/getMax.c src/geometry.h
	$(OBJ)

build/src/prijectionsIntersect.o: src/prijectionsIntersect.c src/geometry.h
	$(OBJ)

build/src/getSlope.o: src/getSlope.c src/geometry.h
	$(OBJ)

build/src/getYIntercept.o: src/getYIntercept.c src/geometry.h
	$(OBJ)

build/src/getCos.o: src/getCos.c src/geometry.h
	$(OBJ)

build/src/distan.o: src/distan.c src/geometry.h
	$(OBJ)

build/src/perpendicular.o: src/perpendicular.c src/geometry.h
	$(OBJ)

build/src/testing.o: src/testing.c src/geometry.h
	$(OBJ)

build/src/prov_data.o: src/prov_data.c src/geometry.h src/figure.h
	$(OBJ)

build/src/print_posle_prov.o: src/print_posle_prov.c src/geometry.h src/figure.h
	$(OBJ)


bin/geometry-test: build/test/test.o build/test/circle_intersects.o build/test/printCircle.o build/test/printPoligon.o build/test/printTriangle.o build/test/proverka.o  build/src/input_data.o build/test/areCollinear.o build/test/getMin.o build/test/getMax.o build/test/prijectionsIntersect.o build/test/getSlope.o build/test/getYIntercept.o build/test/getCos.o build/test/testing.o build/test/perpendicular.o build/test/distan.o build/test/prov_data.o 
	g++ $(CFLAGS) -I thirtdparty/catch2  $^ -o $@

build/test/test.o: test/test.c test/geometry.h test/figure.h 
	$(TEST)

build/test/circle_intersects.o: test/circle_intersects-test.c test/geometry.h test/figure.h 
	$(TEST)

build/test/printCircle.o: test/printCircle-test.c test/geometry.h test/figure.h
	$(TEST)

build/test/printPoligon.o: test/printPoligon-test.c test/geometry.h test/figure.h 
	$(TEST)

build/test/printTriangle.o: test/printTriangle-test.c test/geometry.h test/figure.h 
	$(TEST)

build/test/proverka.o: test/proverka-test.c src/geometry.h test/figure.h 
	$(TEST)


build/test/input_data.o: test/input_data-test.c test/geometry.h test/figure.h
	$(TEST)  

build/test/areCollinear.o: test/areCollinear-test.c test/geometry.h test/figure.h 
	$(TEST)

build/test/getMin.o: test/getMin-test.c test/geometry.h test/figure.h 
	$(TEST)

build/test/getMax.o: test/getMax-test.c test/geometry.h test/figure.h
	$(TEST)

build/test/prijectionsIntersect.o: test/prijectionsIntersect-test.c test/geometry.h test/figure.h 
	$(TEST)

build/test/getSlope.o: test/getSlope-test.c test/geometry.h test/figure.h 
	$(TEST)

build/test/getYIntercept.o: test/getYIntercept-test.c test/geometry.h test/figure.h 
	$(TEST)

build/test/getCos.o: test/getCos-test.c test/geometry.h test/figure.h 
	$(TEST)

build/test/distan.o: test/distan-test.c test/geometry.h test/figure.h 
	$(TEST)

build/test/perpendicular.o: test/perpendicular-test.c test/geometry.h test/figure.h
	$(TEST)

build/test/testing.o: test/testing-test.c test/geometry.h test/figure.h 
	$(TEST)

build/test/prov_data.o: test/prov_data-test.c test/geometry.h test/figure.h  	
	$(TEST)




clean:
	
	rm -r build
	rm -r bin	








