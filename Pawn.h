# include "ChessPiece.h"

class Pawn: public ChessPiece {

public:

  Pawn(PieceColor color): ChessPiece(color) { };

  virtual std::string getPieceName() const;

  virtual bool isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
                                 const ChessPosition start,
                                 const ChessPosition end);
};