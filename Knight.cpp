# include "Knight.h"

std::string Knight::getPieceName() const {
  return "Knight";
}

void Knight::getAllMoves(std::map<ChessPosition, ChessPiece *> &board,
                         const ChessPosition start) {

  std::vector<ChessPosition> moves;

  int dX[8] = { 1, 2, -1, -2, -2, -1, 1, 2 };
  int dY[8] = { 2, 1, 2, 1, -1, -2, -2, -1 };
  ChessPosition move = start;

  for (int i = 0; i < 8; i++) {
    move = start;
    move.pos[0] += dX[i];
    move.pos[1] += dY[i];

    if (move.isPositionValid() and !board[move])
      moves.push_back(move);
    else if (move.isPositionValid() and (board[move] -> color != color))
      moves.push_back(move);
  }

  allMoves = moves;
}
