# include "Pawn.h"

std::string Pawn::getPieceName() const {
    return "Pawn";
  }

bool Pawn::isSquareReachable(std::map<ChessPosition, ChessPiece *> &board,
                             const ChessPosition start,
                             const ChessPosition end) {

  int xMove = end.pos[0] - start.pos[0];
  int yMove = end.pos[1] - start.pos[1];

  yMove *= (color == white) ? 1 : -1;

  PieceColor oppositeColor = (color == white) ? black : white;

  switch (abs(xMove)) {
  case 1:
    if (yMove != 1)
      return false;
    return (board[end] and board[end] -> color == oppositeColor);
  case 0: {
    char startRank = (color == white) ? WHITE_PAWN_START_RANK :
    BLACK_PAWN_START_RANK;

    if (yMove == 1)
      return (!board[end]);

    if (yMove == 2)
      return (!board[end] and start.pos[1] == startRank);
  }
    return false;
  default:
    return false;
  }
}
