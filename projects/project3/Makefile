DEBUG = -g3 -O0 -MMD
CXXFLAGS = -ansi -pedantic -Wall $(DEBUG)
TEST = gcd.cpp test.cpp
TESTOBJ = $(TEST:.cpp=.o)

all : runtest

test : $(TESTOBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(TESTOBJ)

runtest : cleantest test
	./test

clean : cleantest
	$(RM) -r $(TESTOBJ) test html *.d

cleantest :
	$(RM) *.{gcov,gcda}

.PHONY : runtest clean cleantest
