# Makefile
all: mock_c

mock_c: async_test.cpp
	g++ -o mock_c async_test.cpp -lgcov -fprofile-arcs -ftest-coverage -lgtest -lgtest_main -lpthread -lgmock
	./mock_c

clean:
	rm -rf *.o *.gcda *.gcno *.lcov coverage mock_c