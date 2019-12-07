# include "ChessPiece.h"

class Queen: public ChessPiece {

  virtual std::string getPieceName() {
    return "Queen";
  }

  virtual bool isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
				 const ChessPosition start,
				 ChessPosition end) {
    std::vector<ChessPosition> moves;
    checkDiagonals(board, start, moves);
    checkFile(board, start, moves);
    checkRank(board, start, moves);
    return (std::find(moves.begin(), moves.end(), end) != moves.end());
  }
};
