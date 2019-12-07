# include "Rook.h"

std::string Rook::getPieceName() const {
  return "Rook";
}

void Rook::getAllMoves(std::map<ChessPosition, ChessPiece *> &board,
                       const ChessPosition start) {
  std::vector<ChessPosition> moves;
  checkFile(board, start, moves);
  checkRank(board, start, moves);
  allMoves = moves;
}
