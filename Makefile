CXX = clang++
CXXFLAGS = -g3 -std=c++11 -Wall -Wextra

char: testCharArrayList.o CharArrayList.o
	${CXX} -o char testCharArrayList.o CharArrayList.o

testCharArrayList: testCharArrayList.cpp CharArrayList.h
CharArrayList.o: CharArrayList.cpp	CharArrayList.h

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -rf *.o