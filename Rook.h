# ifndef ROOK_H
# define ROOK_H

# include "ChessPiece.h"

class Rook: public ChessPiece {

public:
  Rook(PieceColor color): ChessPiece(color) { };

  virtual std::string getPieceName() const;

  virtual void getAllMoves(std::map<ChessPosition, ChessPiece *> &board,
                           const ChessPosition start);
};

# endif
