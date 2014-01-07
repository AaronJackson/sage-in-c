demos:
	mkdir -p build
	gcc demo/main.c src/*.c -o build/main -Wall
	gcc demo/invoice_list.c src/*.c -o build/invoice_list -Wall

clean:
	rm -rf build/*
