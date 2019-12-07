# include "ChessPiece.h"

class Bishop: public ChessPiece {

  virtual std::string getPieceName() {
    return "Bishop";
  }

  virtual bool isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
                                 const ChessPosition start,
                                 const ChessPosition end) {
    std::vector<ChessPosition> moves;
    checkDiagonals(board, start, moves);
    return (std::find(moves.begin(), moves.end(), end) != moves.end());
  }
};
