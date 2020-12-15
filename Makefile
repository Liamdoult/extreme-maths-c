all:
	@mkdir -p ./bin
	gcc -O3 -fPIC --shared -I include src/vector.c -o ./bin/libem.so
	# icc -mkl -O3 -fPIC --shared -I include src/vector.c -o ./bin/libiem.so

test:
	@mkdir -p ./build
	gcc -g -I include src/vector.c src/test.c -o ./build/c_test 
	@./build/c_test
	# icc -mkl -g -I include src/vector.c src/test.c -o ./build/c_itest 
	# @./build/c_itest
