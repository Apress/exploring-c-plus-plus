DEBUG = -g3 -O0
CXXFLAGS = -ansi -pedantic -Wall -MMD $(DEBUG)

all: runtest

runtest: test datatest mpg lpk fakemake palindrome word_count
	./test
	./datatest < datatest.in | diff - datatest.out
	./mpg < mpg.in | diff - mpg.out
	./lpk < lpk.in | diff - lpk.out
	./fakemake < fakemake.in | diff - fakemake.out
	./word_count < word_count.in | diff - word_count.out

% : %.o
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^

fakemake : fakemake.o depgraph.o artifact.o artifact_impl.o variables.o
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^

test : testmain.o test_power10.o test_rational.o gcd.o test_fixed.o
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^

datatest : datatest.o
randomint : randomint.o
lpk: lpk.o
mpg: mpg.o
palindrome: palindrome.o
word_count: word_count.o

clean:
	$(RM) *.o *.d test datatest randomint mpg lpk fakemake palindrome word_count

.PHONY: all runtest clean

-include *.d
