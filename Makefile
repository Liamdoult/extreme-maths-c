all:
	gcc -O3 -fPIC --shared -I include src/vector.c -o ./bin/libem.so
	# nvcc --compiler-options '-fPIC -O3' --shared -I include src/vector.cu -o ./bin/libem_cuda.so -DGPU
	# gcc -O3 -fPIC --shared -I include src/vector_cl.c -o ./bin/libem_ocl.so -lOpenCL -lm -DGPU
	# gcc -O3 -fPIC --shared -I include src/vector_threaded.c -o ./bin/libem_threaded.so

open_cl_preprocessing:
	touch include/ocl_kernal_source.h
	bash stringify_ocl src/vector.cl

test: open_cl_preprocessing
	gcc -g -I include src/vector.c src/test.c -o ./build/c_test 
	@./build/c_test
	# nvcc -I include src/vector.cu src/test.c -o ./build/cu_test -DGPU
	# @./build/cu_test
	# gcc -I include src/vector_cl.c src/test.c -o ./build/ocl_test -lOpenCL -lm -DGPU
	# @./build/ocl_test
	# gcc -I include src/vector_threaded.c src/test.c -o ./build/threaded_test -pthread
	# @./build/threaded_test
