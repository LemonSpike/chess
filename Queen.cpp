# include "Queen.h"

std::string Queen::getPieceName() const {
  return "Queen";
}

bool Queen::isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
                              const ChessPosition start,
                              const ChessPosition end) {
  std::vector<ChessPosition> moves;
  checkDiagonals(board, start, moves);
  checkFile(board, start, moves);
  checkRank(board, start, moves);
  return (std::find(moves.begin(), moves.end(), end) != moves.end());
}
