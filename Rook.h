# include "ChessPiece.h"

class Rook: public ChessPiece {

public:
  Rook(PieceColor color): ChessPiece(color) { };

  virtual std::string getPieceName() const;

  virtual bool isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
                                 const ChessPosition start,
                                 const ChessPosition end);
};
