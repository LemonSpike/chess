# include "ChessPiece.h"

class Rook: public ChessPiece {

  virtual std::string getPieceName() {
    return "Rook";
  }

  virtual bool isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
				 ChessPosition start,
				 ChessPosition end) {
    vector<ChessPosition> moves;
    checkFile(board, start, moves);
    checkRank(board, start, moves);
    return (std::find(moves.begin(), moves.end(), end) != moves.end());
  }
};
