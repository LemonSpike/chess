# include "Rook.h"

std::string Rook::getPieceName() const {
  return "Rook";
}

bool Rook::isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
                             const ChessPosition start,
                             const ChessPosition end) {
  std::vector<ChessPosition> moves;
  checkFile(board, start, moves);
  checkRank(board, start, moves);
  return (std::find(moves.begin(), moves.end(), end) != moves.end());
}
