all: src
src: main.o ray.o vec3.o sphere.o hittable_list.o
	g++ -Wall main.o ray.o vec3.o sphere.o hittable_list.o -o src

#main object files
main.o: main.cpp
	g++ -c -Wall main.cpp 
ray.o: ray.cpp
	g++ -c -Wall ray.cpp
vec3.o: vec3.cpp
	g++ -c -Wall vec3.cpp

#hittable object files
sphere.o: sphere.cpp
	g++ -c -Wall sphere.cpp
hittable.o: hittable_list.cpp
	g++ -c -Wall hittable_list.cpp


clean:
	del *.o