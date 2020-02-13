CC = g++ -g
exe_file = zootycoon
$(exe_file): zoo.o animal.o sea_lion.o bear.o tiger.o driver.o
	$(CC) zoo.o animal.o sea_lion.o bear.o tiger.o driver.o -o $(exe_file)
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
animal.o: animal.cpp
	$(CC) -c animal.cpp
sea_lion.o: sea_lion.cpp
	$(CC) -c sea_lion.cpp
bear.o: bear.cpp
	$(CC) -c bear.cpp
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
