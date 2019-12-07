# include "King.h"

std::string King::getPieceName() const {
  return "King";
}

bool King::isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
                             const ChessPosition start,
                             const ChessPosition end) {

  int xMove = end.pos[0] - start.pos[0];
  int yMove = end.pos[1] - start.pos[1];

  PieceColor oppositeColor = (color == white) ? black : white;

  switch (abs(xMove)) {
  case 1:
    if (abs(yMove) > 1)
      return false;
    return (!board[end] or (board[end] -> color == oppositeColor));
  default:
    return false;
  }
}
