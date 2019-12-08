# ifndef CHESSBOARD_H
# define CHESSBOARD_H

# include <iostream>
# include <map>
# include <string>

# include "ChessPosition.h"
# include "ChessPiece.h"
# include "Pawn.h"
# include "Bishop.h"
# include "Rook.h"
# include "Knight.h"
# include "King.h"
# include "Queen.h"

class ChessBoard {

  // Data structure to store pieces and their positions on a Chess board.
  std::map<ChessPosition, ChessPiece *> board;

  // This variable tracks who the current player is.
  PieceColor currentPlayer;

  // Change player after move is made successfully.
  void switchPlayer();
  // Deallocate memory for all pieces and clear the board.
  void removePieces();

  // This helper function is used to store threats against a king.
  // It stores their ChessPositions in a vector.
  std::vector<ChessPosition> findThreats(std::map<ChessPosition,
                                         ChessPiece *> boardCopy,
                                         ChessPosition kingPosition);

  // This helper function returns false if a threat to the king can be defended.
  // It tests all possible moves to get out of check, and returns false if
  // the player can get out of check.
  bool evaluateThreats(std::map<ChessPosition, ChessPiece *> boardCopy,
                       ChessPosition current,
                       PieceColor player);

  // This helper function is used to find the King's position on the board
  // for the player's color.
  ChessPosition findKing(std::map<ChessPosition, ChessPiece *> boardCopy,
                         PieceColor player);

public:

  // This function initialises the board with the initial piece positions and
  // first player set to white.
  ChessBoard(): currentPlayer(white) { resetBoard(); };

  // This function removes all pieces from the board and deallocates memory.
  ~ChessBoard() { removePieces(); };

  // Remove all existing pieces and setup initial piece positions.
  void resetBoard();

  // This function allows the client to submit moves to play.
  void submitMove(std::string positionOne, std::string positionTwo);

  // This function returns true if player is under check.
  bool isInCheck(PieceColor player);

  // This function returns true if player is under checkmate.
  bool isInCheckMate(PieceColor player);
};

#endif
