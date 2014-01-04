DEBUGGER=ggdb


all:
	mkdir -p build
	gcc src/*.c demo/*.c -o build/main

debug:
	mkdir -p build
	gcc src/*.c demo/*.c -o build/main -g 
	$(DEBUGGER) ./build/main

clean:
	rm -rf build/*