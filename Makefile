CXX = clang++

FLAGS = -std=c++14 -fPIE -fpermissive

AR = ar

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses -Wfloat-equal -Wno-multichar

DEBUG = -g -O0 -DDEBUG $(WARN)

RELEASE = -Ofast -DNDEBUG $(WARN)

#OPT = $(DEBUG)
OPT = $(RELEASE)

game : $(MAIN) 
	g++ $(WARN) test.C -I./DeSiGNAR/include -L./DeSiGNAR/include -lDesignar -o test

clean:
	$(RM) *~ $(INCLUDEDIR)/*~ $(SRCDIR)/*~ $(SAMPLESDIR)/*~ $(OBJECTS) $(BIN)
