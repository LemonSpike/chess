# include "King.h"

std::string King::getPieceName() const {
  return "King";
}

void King::getAllMoves(std::map<ChessPosition, ChessPiece *> &board,
                       const ChessPosition start) {

  std::vector<ChessPosition> moves;

  PieceColor oppositeColor = (color == white) ? black : white;

  ChessPosition move = start;

  for (int i = 0; i < 9; ++i) {

    move = start;

    int deltaX = (i % 3) - 1;
    int deltaY;
    if (i < 3)
      deltaY = -1;
    else if (i < 6)
      deltaY = 0;
    else
      deltaY = 1;

    if (deltaY == 0 and deltaX == 0)
      continue;

    move.pos[0] += deltaX;
    move.pos[1] += deltaY;

    if (move.isPositionValid() and !board[move])
      moves.push_back(move);
    else if (move.isPositionValid() and board[move] -> color == oppositeColor)
      moves.push_back(move);
  }
  allMoves = moves;
}
