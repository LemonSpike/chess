# include "ChessPiece.h"

bool ChessPiece::canMakeMove(std::map<ChessPosition, ChessPiece *> &board,
                             ChessPosition start,
                             ChessPosition end) {
    // Check for friendly fire.
  if ((board[end] -> color) == color) {
    std::cout << this << " cannot move to " << end.pos << "!";
    std::cout << "(The piece is occupied by " << board[end] << ")" << std::endl;
    return false;
  }
    // Check if square can be reached.
  if (!isSquareReachable(board, start, end)) {
    std::cout << this << " cannot move to " << end.pos << "!" << std::endl;
    return false;
  }

  return true;
}

void ChessPiece::checkDiagonals(std::map<ChessPosition, ChessPiece *> &board,
                                const ChessPosition start,
                                std::vector<ChessPosition> &moves) const {

  if (((ChessPosition) start).isPositionValid() == false)
    return;

  ChessPosition move = start;

  PieceColor oppositeColor = (color == white) ? black : white;

  for (int i = 0; i < 4; ++i) {

    move = start;

    int deltaX = (i % 2) ? -1 : 1;
    int deltaY = (i > 2) ? -1 : 1;

    move.pos[0] += deltaX;
    move.pos[1] += deltaY;

    while (move.isPositionValid() and !board[move]) {
      moves.push_back(move);
      move.pos[0] += deltaX;
      move.pos[1] += deltaY;
    }

    if (move.isPositionValid() and board[move] -> color == oppositeColor)
      moves.push_back(move);
  }
}

void ChessPiece::checkRank(std::map<ChessPosition, ChessPiece *> &board,
                           const ChessPosition start,
                           std::vector<ChessPosition> &moves) const {

  if (((ChessPosition) start).isPositionValid() == false)
    return;

  ChessPosition move = start;
  int direction = 1;

  PieceColor oppositeColor = (color == white) ? black : white;

  for (int i = 1; i < BOARD_DIMEN; i++) {

    if (move.pos[0] == MAX_FILE) {
      direction = -1;
      move = start;
    }

    if (move.pos[0] == MIN_FILE and direction == -1)
      break;

    move.pos[0] += direction;

    if (!board[move]) {
      moves.push_back(move);
    } else if (direction == 1) {
      if (board[move] -> color == oppositeColor)
        moves.push_back(move);
      direction = -1;
      move = start;
    } else {
      if (board[move] -> color == oppositeColor)
        moves.push_back(move);
      break;
    }
  }
}


void ChessPiece::checkFile(std::map<ChessPosition, ChessPiece *> &board,
                           const ChessPosition start,
                           std::vector<ChessPosition> &moves) const {

  if (((ChessPosition) start).isPositionValid() == false)
    return;

  ChessPosition move = start;
  int direction = 1;

  PieceColor oppositeColor = (color == white) ? black : white;

  for (int i = 1; i < BOARD_DIMEN; i++) {

    if (move.pos[1] == MAX_RANK) {
      direction = -1;
      move = start;
    }

    if (move.pos[1] == MIN_RANK and direction == -1)
      break;

    move.pos[1] += direction;

    if (!board[move]) {
      moves.push_back(move);
    } else if (direction == 1) {
      if (board[move] -> color == oppositeColor)
        moves.push_back(move);
      direction = -1;
      move = start;
    } else {
      if (board[move] -> color == oppositeColor)
        moves.push_back(move);
      break;
    }
  }
}
