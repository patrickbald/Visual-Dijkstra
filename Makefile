CMP = g++
CLASS = board
MAIN = project
EXEC = run
FLAGS = -std=c++11 -lX11
GRAPHICS = gfx2.o

$(EXEC): $(MAIN).o $(CLASS).o
		$(CMP) $(MAIN).o $(CLASS).o $(GRAPHICS) $(FLAGS) -o $(EXEC)

$(MAIN).o: $(MAIN).cpp $(CLASS).h
		$(CMP) -c $(MAIN).cpp $(FLAGS) -o $(MAIN).o

$(CLASS).o: $(CLASS).cpp $(CLASS).h
		$(CMP) -c $(CLASS).cpp $(FLAGS) -o $(CLASS).o


clean:
	rm $(CLASS).o
	rm $(MAIN).o
	rm $(EXEC)
