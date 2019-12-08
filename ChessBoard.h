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
  std::map<ChessPosition, ChessPiece *> board;
  PieceColor currentPlayer;
  void switchPlayer();
  void removePieces();
  std::vector<ChessPosition> findThreats(std::map<ChessPosition,
                                         ChessPiece *> boardCopy,
                                         ChessPosition kingPosition);
  bool evaluateThreats(std::map<ChessPosition, ChessPiece *> boardCopy,
                       ChessPosition current,
                       PieceColor player);
  ChessPosition findKing(std::map<ChessPosition, ChessPiece *> boardCopy,
                         PieceColor player);

public:

  ChessBoard(): currentPlayer(white) { resetBoard(); };
  ~ChessBoard() { removePieces(); };

  void resetBoard();
  void submitMove(std::string positionOne, std::string positionTwo);
  bool isInCheck(PieceColor player);
  bool isInCheckMate(PieceColor player);
};

#endif
