CMP = g++
CLASS = board
MAIN = path
EXEC = path

$(EXEC): $(MAIN).o $(CLASS).o
		$(CMP) $(MAIN).o $(CLASS).o gfx.o -std=c++11 -o $(EXEC)

$(MAIN).o: $(MAIN).cpp $(CLASS).h
		$(CMP) -c $(MAIN).cpp -o $(MAIN).o

$(CLASS).o: $(CLASS).cpp $(CLASS).h
		$(CMP) -c $(CLASS).cpp -o $(CLASS).o


clean:
	rm $(CLASS).o
	rm $(MAIN).o
	rm $(EXEC)
