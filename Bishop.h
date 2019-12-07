# ifndef BISHOP_H
# define BISHOP_H

# include "ChessPiece.h"

class Bishop: public ChessPiece {

public:

  Bishop(PieceColor color): ChessPiece(color) { };

  virtual std::string getPieceName() const;

  virtual void getAllMoves(std::map<ChessPosition, ChessPiece *> &board,
                           const ChessPosition start);

};

# endif
