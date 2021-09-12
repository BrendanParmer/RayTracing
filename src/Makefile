all: src
src: main.o ray.o vec3.o
	g++ -Wall main.o ray.o vec3.o -o src
main.o: main.cpp
	g++ -c -Wall main.cpp 
ray.o: ray.cpp
	g++ -c -Wall ray.cpp
vec3.o: vec3.cpp
	g++ -c -Wall vec3.cpp

clean:
	del *.o