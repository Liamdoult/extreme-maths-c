all:
	gcc -O3 -fPIC --shared -I include src/vector.c -o ./bin/libem.so

test:
	gcc -g -I include src/vector.c src/test.c -o ./build/c_test 
	@./build/c_test
