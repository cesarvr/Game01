CC=g++

CFLAGS = -g -Wall -std=c++11 -lm

TARGET = math_test

All: $(TARGET)

objects = main.o vector.o matrix.o

math_test: $(objects)
	$(CC) -o $(TARGET) $(objects)


main.o: mathla.h matrix.h vector.h
	$(CC) -c $(CFLAGS) main.cpp

matrix.o: matrix.cpp matrix.h
	$(CC) -c $(CFLAGS) matrix.cpp

vector.o: vector.cpp vector.h
	$(CC) -c $(CFLAGS)  vector.cpp

clean:
	rm $(TARGET) $(objects)
