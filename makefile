all: main.cpp
	g++ main.cpp -o main.out

clean:
	rm -rf main.out