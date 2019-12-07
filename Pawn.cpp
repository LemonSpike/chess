# include "Pawn.h"

std::string Pawn::getPieceName() const {
    return "Pawn";
  }

void Pawn::getAllMoves(std::map<ChessPosition, ChessPiece *> &board,
                       const ChessPosition start) {

  std::vector<ChessPosition> moves;

  // Check capture moves.
  addCaptureMoves(board, start, moves);

  // Check single step.
  ChessPosition move = start;
  move.pos[1] += (color == white) ? 1 : -1;

  if (!board[move])
    moves.push_back(move);

  // Check double step.
  move = start;
  char startRank = (color == white) ?
    WHITE_PAWN_START_RANK : BLACK_PAWN_START_RANK;

  if (start.pos[1] == startRank) {
    move.pos[1] += (color == white) ? 2 : -2;
    if (!board[move])
      moves.push_back(move);
  }
  allMoves = moves;
}

void Pawn::addCaptureMoves(std::map<ChessPosition, ChessPiece *> &board,
                           const ChessPosition start,
                           std::vector<ChessPosition> &moves) {

  PieceColor oppositeColor = (color == white) ? black : white;

  ChessPosition move = start;

  int step = (color == white) ? 1 : -1;

  (move.pos[1]) += step;
  (move.pos[0])++;
  if (board[move] and ((board[move] -> color) == oppositeColor)) {
    moves.push_back(move);
  }

  (move.pos[0]) -= 2;
  if (board[move] and ((board[move] -> color) == oppositeColor)) {
    moves.push_back(move);
  }
}
