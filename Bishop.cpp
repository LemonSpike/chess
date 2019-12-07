# include "Bishop.h"

std::string Bishop::getPieceName() const {
  return "Bishop";
}

bool Bishop::isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
                               const ChessPosition start,
                               const ChessPosition end) {
  std::vector<ChessPosition> moves;
  checkDiagonals(board, start, moves);
  return (std::find(moves.begin(), moves.end(), end) != moves.end());
}
