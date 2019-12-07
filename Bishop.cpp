# include "Bishop.h"

std::string Bishop::getPieceName() const {
  return "Bishop";
}

void Bishop::getAllMoves(std::map<ChessPosition, ChessPiece *> &board,
                         const ChessPosition start) {
  std::vector<ChessPosition> moves;
  checkDiagonals(board, start, moves);
  allMoves = moves;
}
