all:
	nvcc --compiler-options '-fPIC -O3' --shared -I include src/vector.c -o ./bin/libem.so
	nvcc --compiler-options '-fPIC -O3' --shared -I include src/vector.cu -o ./bin/libem_cuda.so

test:
	nvcc -I include src/vector.c src/test.c -o ./build/c_test
	@./build/c_test
	nvcc -I include src/vector.cu src/test.c -o ./build/cu_test
	@./build/cu_test

