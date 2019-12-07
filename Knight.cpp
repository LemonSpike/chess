# include "ChessPiece.h"

class Knight: public ChessPiece {

  virtual std::string getPieceName() {
    return "Knight";
  }

  virtual bool isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
				 ChessPosition start,
				 ChessPosition end) {
    if (!end.isPositionValid())
      return false;

    if (board[end] && board[end] -> color == color)
      return false;

    int horz = end[0] - start[0];
    int vert = end[1] - start[1];
    switch (horz) {
    case -1:
    case 1:
      return (abs(vert) == 2*abs(horz));
    case -2:
    case 2:
      return (2*abs(vert) == abs(horz));
    default:
      return false;
    }
  }
};
