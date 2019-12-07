# include "Queen.h"

std::string Queen::getPieceName() const {
  return "Queen";
}

void Queen::getAllMoves(std::map<ChessPosition, ChessPiece *> &board,
                        const ChessPosition start) {
  std::vector<ChessPosition> moves;
  checkDiagonals(board, start, moves);
  checkFile(board, start, moves);
  checkRank(board, start, moves);
  allMoves = moves;
}
