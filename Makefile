OBJ = ChessMain.o ChessBoard.o Queen.o ChessPiece.o ChessPosition.o
EXE = chess
CXX = g++
CXXFLAGS = -Wall -Wextra -g -MMD

$(EXE): $(OBJ)
	$(CXX) $^ -o $0

%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -c $<

-include $(OBJ:.o=.d)

clean:
	rm -f $(OBJ) $(EXE) $(OBJ:.o=.d)

.PHONY: clean
