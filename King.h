# ifndef KING_H
# define KING_H

# include "ChessPiece.h"

class King: public ChessPiece {

public:

  King(PieceColor color): ChessPiece(color) { };

  virtual std::string getPieceName() const;

  virtual void getAllMoves(std::map<ChessPosition, ChessPiece *> &board,
                           const ChessPosition start);

};

# endif
