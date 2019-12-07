# ifndef KNIGHT_H
# define KNIGHT_H

# include "ChessPiece.h"

class Knight: public ChessPiece {

public:

  Knight(PieceColor color): ChessPiece(color) { };

  virtual std::string getPieceName() const;

  virtual bool isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
                                 const ChessPosition start,
                                 const ChessPosition end);
};

# endif
