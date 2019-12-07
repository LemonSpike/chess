# ifndef CHESSBOARD_H
# define CHESSBOARD_H

# include <iostream>
# include <map>
# include <string>

# include "ChessPosition.h"
# include "ChessPiece.h"
# include "Pawn.h"
# include "Bishop.h"
# include "Rook.h"
# include "Knight.h"
# include "King.h"
# include "Queen.h"

class ChessBoard {
  std::map<ChessPosition, ChessPiece *> board;
  PieceColor currentPlayer;
  void switchPlayer();

public:
  void resetBoard();
  void submitMove(std::string positionOne, std::string positionTwo);
};

#endif
