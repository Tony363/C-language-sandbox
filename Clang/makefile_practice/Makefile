# user all to build the binaries
# use doc to build the API doc
# use clean to delete generated files

CFLAGS=-Isrc
all: build/myprog

build/myprog: build/main.o build/libmy.a
	gcc -o $@ $< -Lbuild -lmy

build/main.o: main.c src/myheader.h
	gcc -c $(CFLAGS) -o $@ $<

build/%.o: src/%.c src/myheader.h
	gcc -c $(CFLAGS) -o $@ $<

build/f.o: src/f.c src/myheader.h

build/g.o : src/g.c src/myheader.h

build/libmy.a: build/f.o build/g.o
	ar rcs $@ $^

.PHONY: doc clean

doc: src/*.h
	doxygen 

clean:
	rm -f build/*
	rm -fr doc/*