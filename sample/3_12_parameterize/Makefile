# Makefile
all: LeapYearCalendar_cpp

LeapYearCalendar_cpp: LeapYearParameterizedFixture.cpp LeapYearCalendar.cpp
	g++ -o LeapYearCalendar.o -c LeapYearCalendar.cpp -lgcov -fprofile-arcs -ftest-coverage 
	g++ -o LeapYearParameterizedFixture LeapYearCalendar.o LeapYearParameterizedFixture.cpp -lgcov -fprofile-arcs -ftest-coverage -lgtest -lgtest_main -lpthread -lgmock
	./LeapYearParameterizedFixture
	gcov -b ./ LeapYearParameterizedFixture.cpp
	lcov -c -d . -o LeapYearParameterizedFixture.lcov --rc lcov_branch_coverage=1
	genhtml LeapYearParameterizedFixture.lcov --rc lcov_branch_coverage=1 -o coverage

clean:
	rm -rf *.o *.gcda *.gcno *.lcov coverage LeapYearParameterizedFixture