# include "ChessPiece.h"

class Knight: public ChessPiece {

  virtual std::string getPieceName() const {
    return "Knight";
  }

  virtual bool isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
                                 const ChessPosition start,
                                 const ChessPosition end) {
    if (!(((ChessPosition) end).isPositionValid()))
      return false;

    if (board[end] && board[end] -> color == color)
      return false;

    int horz = end.pos[0] - start.pos[0];
    int vert = end.pos[1] - start.pos[1];
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
