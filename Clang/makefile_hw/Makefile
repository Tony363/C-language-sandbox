# user all to build the binaries
# use doc to build the API doc
# use clean to delete generated files

CFLAGS=-Isrc
all: build/summary

# build/summary: main.c src/aggs.c src/aggs.h
# 	gcc -g -Isrc main.c src/aggs.c -lm -o build/summary
	
build/summary: build/main.o build/libmylib.a
	gcc -o $@ $< -Lbuild -lmylib -lm

build/main.o: main.c src/aggs.h
	gcc -c $(CFLAGS) -o $@ $< 

build/%.o: src/%.c src/aggs.h
	gcc -c $(CFLAGS) -o $@ $< 

build/aggs.o: src/aggs.c src/aggs.h

build/libmylib.a: build/aggs.o
	ar rcs $@ $^

.PHONY: doc clean

doc: src/*.h
	doxygen 

clean:
	rm -f build/*
	rm -fr doc/*