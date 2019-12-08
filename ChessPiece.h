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

  // Stores all possible moves the piece can make.
  std::vector<ChessPosition> allMoves;

  // Helper function for printing out a description of the Chess piece.
  // Note that as getPieceName() is virtual and piece is passed by reference.
  // that the derived class implementation of getPieceName() will be called.
  friend std::ostream& operator <<(std::ostream& o,
                                   ChessPiece& piece) {
    o << ((piece.color == white) ? "White's " : "Black's ");
    o << piece.getPieceName();
    return o;
  }

  bool operator ==(const ChessPiece& rhs) const {
    return (color == rhs.color) and (getPieceName() == rhs.getPieceName());
  }

  // Derived classes override this function to print the piece name.
  virtual std::string getPieceName() const = 0;

  // This function checks if an end square can be reached by checking if that
  // square is one of the possible moves from the start position.
  bool isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
                         const ChessPosition start,
                         const ChessPosition end);

  // This function traverses the board to find all possible moves for the piece
  // from the given start position.
  // It stores the possible moves inside allMoves.
  virtual void getAllMoves(std::map<ChessPosition,
                           ChessPiece *> &board,
                           const ChessPosition start) = 0;

  // This function prints a description of a move.
  void printMove(ChessPiece *startPiece,
                 ChessPiece *endPiece,
                 const ChessPosition start,
                 const ChessPosition end);

  // This function updates the board with a move from the start position to
  // the end position.
  void makeMove(std::map<ChessPosition, ChessPiece *> &board,
                const ChessPosition start,
                const ChessPosition end);

  // This function returns true if the square is reachable, and not friendly
  // fire, outputting an error message if needed.
  bool canMakeMove(std::map<ChessPosition, ChessPiece *> &board,
                   const ChessPosition start,
                   const ChessPosition end);

  // This function adds moves to the moves vector if they are reachable from the
  // start position along any of the four diagonals.
  void checkDiagonals(std::map<ChessPosition, ChessPiece *> &board,
                      const ChessPosition start,
                      std::vector<ChessPosition> &moves) const;

  // This function adds moves to the moves vector if they are reachable from the
  // start position along its rank (row).
  void checkRank(std::map<ChessPosition, ChessPiece *> &board,
                 const ChessPosition start,
                 std::vector<ChessPosition> &moves) const;

  // This function adds moves to the moves vector if they are reachable from the
  // start position along its file (column).
  void checkFile(std::map<ChessPosition, ChessPiece *> &board,
                 const ChessPosition start,
                 std::vector<ChessPosition> &moves) const;
};

# endif
