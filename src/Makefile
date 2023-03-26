.PHONY: all build static install uninstall rebuild dist test gcov_report clean
CC=gcc
CFLAGS= -Wall -Wextra -Werror -pedantic -std=c11
FLAGS_TEST_LIBS = -lcheck -lm -lpthread

SRC=new.c

NAME=new.a
OBJ=$(patsubst %.c, %.o, $(SRC))
OS = $(shell uname)

all: build static

build:
	cd SmartCalc && $(CC) $(CFLAGS) -c $(SRC)

static:
	cd SmartCalc && ar rc new.a $(OBJ)
	cd SmartCalc && ranlib new.a

test: clean 
	cd SmartCalc && gcc $(GCOVFLAGS) new.c test2.c  $(TEST_FLAGS) -o test -lcheck
	cd SmartCalc && ./test

gcov_report: all
	cd SmartCalc && $(CC) $(CFLAGS) --coverage test2.c $(SRC) $(NAME) $(FLAGS_TEST_LIBS) -o gcov_test
	cd SmartCalc && chmod +x *
	cd SmartCalc && ./gcov_test
	cd SmartCalc && lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	cd SmartCalc && genhtml -o report/ gcov_test.info
	cd SmartCalc && open ./report/index.html


install:
	make clean
	mkdir build
	cd SmartCalc && qmake && make && make clean && rm Makefile && cd ../ && mv SmartCalc/SmartCalc.app build

uninstall:
	rm -rf build*

dvi:
	open README.txt

dist: install
	rm -rf Dist_SmartCalc/
	mkdir Dist_SmartCalc/
	mkdir Dist_SmartCalc/src
	mv ./build/SmartCalc.app Dist_SmartCalc/src/
	tar cvzf Dist_SmartCalc.tgz Dist_SmartCalc/
	rm -rf Dist_SmartCalc/
	rmdir build

clean:
	cd SmartCalc && rm -rf *.a && rm -rf *.o  && rm -rf *.dSYM && rm -rf *.out && rm -rf $(EXECUTABLE) && rm -rf gcov_report && rm -rf report && rm -rf CPPLINT.cfg && rm -rf *.gcda 
	cd SmartCalc && rm -rf *.gcno && rm -rf *.info && rm -rf test && rm -rf Dist_SmartCalc && rm -rf *tgz && rm -rf build && rm -rf SC_test && rm -rf gcov_test && rm -rf .qmake.stash

rebuild: clean all
	
style:
	clang-format -style=Google -n *.c *.h *.cpp

