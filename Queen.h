# ifndef QUEEN_H
# define QUEEN_H

# include "ChessPiece.h"

class Queen: public ChessPiece {

public:

  Queen(PieceColor color): ChessPiece(color) { };

  virtual std::string getPieceName() const;

  virtual void getAllMoves(std::map<ChessPosition, ChessPiece *> &board,
                           const ChessPosition start);
};

# endif
