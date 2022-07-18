all: add fixture_test.o death-test.o
	g++ -o test add_test.c compare_test.c fixture_test.o death-test.o ../src/add.o -lgtest -lgtest_main -lpthread

add: ../src/add.h ../src/add.c
	g++ -c -o ../src/add.o ../src/add.c

death-test.o: death-test.cc
	g++ -c -o death-test.o death-test.cc
