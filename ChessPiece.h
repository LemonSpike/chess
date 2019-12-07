# ifndef CHESSPIECE_H
# define CHESSPIECE_H

# include <map>
# include <vector>
# include <algorithm>

# include "Constants.h"
# include "ChessPosition.h"

enum PieceColor { white, black };

class ChessPiece {
protected:
  ChessPiece(PieceColor color): color(color) { };

public:
  virtual ~ChessPiece() { };

  PieceColor color;

  friend std::ostream& operator <<(std::ostream& o,
                                   ChessPiece& piece) {
    o << ((piece.color == white) ? "White's " : "Black's ");
    o << piece.getPieceName();
    return o;
  }

  bool operator ==(const ChessPiece& rhs) const {
    return (color == rhs.color) and (getPieceName() == rhs.getPieceName());
  }

  virtual std::string getPieceName() const = 0;

  virtual bool isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
                                 const ChessPosition start,
                                 const ChessPosition end) = 0;

  bool canMakeMove(std::map<ChessPosition, ChessPiece *> &board,
                   const ChessPosition start,
                   const ChessPosition end);

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
