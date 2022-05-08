CXX = clang++
CXX_W = clang++ -target x86_64-pc-windows-gnu

FLAGS = -std=c++14 -I./DeSiGNAR/include -L./DeSiGNAR/lib -lDesignar

AR = ar

MAIN = test

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses -Wfloat-equal -Wno-multichar -Wno-invalid-source-encoding

DEBUG = -g -O0 -DDEBUG $(WARN)

RELEASE = -Ofast -DNDEBUG $(WARN)

#OPT = $(DEBUG)
OPT = $(RELEASE)

default: game

game : $(MAIN).C
	$(CXX) $(FLAGS) $(WARN) $(MAIN).C -o $(MAIN)

game_w : $(MAIN).C
	$(CXX_W) $(FLAGS) $(WARN) $(MAIN).C -o $(MAIN)

clean:
	$(RM) *~ $(INCLUDEDIR)/*~ $(SRCDIR)/*~ $(SAMPLESDIR)/*~ $(OBJECTS) $(BIN)
