DIR=.
CXX=g++
CC=$(CXX)
CFLAGS=-I$(DIR) -x c++ -g -std=c++14 -pedantic -Wall -Wpointer-arith -Wwrite-strings -Wcast-qual -Wcast-align -Wformat-security -Wformat-nonliteral -Wmissing-format-attribute -Winline -funsigned-char
CXXFLAGS=$(CFLAGS)
LDFLAGS=-L$(DIR) -lcity

all:	cwk cwkt

cwk:	sample.o Makefile libcity.a
	$(CXX) sample.o -o cwk $(LDFLAGS)

cwkt:	cwkt.o Makefile libcityt.a
	$(CXX) cwkt.o -o cwkt $(LDFLAGS)t

sample.o: sample.cc sample.h Makefile
main.o: main.cc Makefile
cwkt.o: cwkt.cc samplet.cc samplet.h Makefile

libcity.o: libcity.cc city.hh
	g++ $(CXXFLAGS) -x c++ -c libcity.cc

libcity.a: libcity.o
	ar rc libcity.a libcity.o
	ranlib libcity.a

libcityt.o: libcityt.cc cityt.hh
	g++ $(CXXFLAGS) -x c++ -c libcityt.cc

libcityt.a: libcityt.o
	ar rc libcityt.a libcityt.o
	ranlib libcityt.a

clean:
	-rm *.o *.a cwk cwkt *~ 2> /dev/null

submit:
	./z-submit-it
