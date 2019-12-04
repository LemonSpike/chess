# ifndef CHESSBOARD_H
# define CHESSBOARD_H

# include <iostream>
# include <map>
# include <string>
# include "ChessMove.h"
# include "ChessPiece.h"

class ChessBoard {
  std::map<std::string, ChessPiece *> board;

public:
  void resetBoard();
  void submitMove(std::string positionOne, std::string positionTwo);
};

#endif
