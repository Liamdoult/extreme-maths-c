#!/usr/bin/make -f
CC=cl

build:
			cl .\src\vector.c /I .\include\ /MT /Ox
			# $(CC) -O3 --shared -I include src\vector.c -o .\bin\libem.dll
			# $(CC) -O3 -fPIC --shared -I include src\vector.c -o .\bin\libem.so
			# icc -mkl -O3 -fPIC --shared -I include src/vector.c -o ./bin/libiem.so

prepare:
			@mkdir .\bin

test:
			cl .\src\vector.c .\src\test.c /I .\include\ /MT /Ox /std:c11 /Fe
			./vector.exe
