CXXFLAGS = -ansi -pedantic -Wall

all: bmi

bmi: bmi.o
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) bmi.o

clean:
	$(RM) -r bmi bmi.o html

.PHONY: all clean
