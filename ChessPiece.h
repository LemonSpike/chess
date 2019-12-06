# ifndef CHESSPIECE_H
# define CHESSPIECE_H

# include <map>
# include <vector>

# include "Constants.h"
# include "ChessPosition.h"

enum PieceColor { white, black };

class ChessPiece {
protected:
  ChessPiece(PieceColor color): color(color) { };

public:
  PieceColor color;

  friend std::ostream& operator <<(std::ostream& o,
                                   ChessPiece& piece) {
    o << ((piece.color == white) ? "White's " : "Black's ");
    o << piece.getPieceName();
  }

  virtual std::string getPieceName();

  virtual bool isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
                                 ChessPosition start,
                                 ChessPosition end);

  bool canMakeMove(std::map<ChessPosition, ChessPiece *> &board,
                   ChessPosition start,
                   ChessPosition end);

  void checkDiagonals(std::map<ChessPosition, ChessPiece *> &board,
                      const ChessPosition start,
                      std::vector<ChessPosition> &moves) const;

  void checkRank(std::map<ChessPosition, ChessPiece *> &board,
                 const ChessPosition start,
                 std::vector<ChessPosition> &moves) const;

  void checkFile(std::map<ChessPosition, ChessPiece *> &board,
                 const ChessPosition start,
                 std::vector<ChessPosition> &moves) const;
};

# endif
