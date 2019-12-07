# ifndef PAWN_H
# define PAWN_H

# include "ChessPiece.h"

class Pawn: public ChessPiece {

  void addCaptureMoves(std::map<ChessPosition, ChessPiece *> &board,
                       const ChessPosition start,
                       std::vector<ChessPosition> &moves);

public:

  Pawn(PieceColor color): ChessPiece(color) { };

  virtual std::string getPieceName() const;

  virtual void getAllMoves(std::map<ChessPosition, ChessPiece *> &board,
                           const ChessPosition start);
};

# endif
