# include "ChessPiece.h"

class Bishop: public ChessPiece {

  virtual std::string getPieceName() {
    return "Bishop";
  }

  virtual bool isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
				 ChessPosition start,
				 ChessPosition end) {
    vector<ChessPosition> moves;
    checkDiagonals(board, moves, start);
    return (std::find(moves.begin(), moves.end(), end) != moves.end());
  }
};
