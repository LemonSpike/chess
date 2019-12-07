# include "ChessBoard.h"

void ChessBoard::switchPlayer() {
  if (currentPlayer == white)
    currentPlayer = black;
  else
    currentPlayer = white;
}

void ChessBoard::submitMove(std::string positionOne, std::string positionTwo) {
  // Check positions are valid.
  ChessPosition pos_one(positionOne);
  if (!pos_one.isPositionValid()) {
    std::cout << "Position " << positionOne << " does not exist!" << std::endl;
    return;
  }
  ChessPosition pos_two(positionTwo);
  if (!pos_two.isPositionValid()) {
    std::cout << "Position " << positionTwo << " does not exist!" << std::endl;
    return;
  }

  // Block move if no piece exists at the position.
  if (board[pos_one] == nullptr) {
    std::cout << "There is no piece at position ";
    std::cout << positionOne << "!" << std::endl;
    return;
  }

  // Block move if piece color is incorrect.
  if (board[pos_one] -> color != currentPlayer) {
    std::cout << "It is not " << ((board[positionOne] -> color == white) ?
				  "White's " : "Black's ");
    std::cout << "turn to move!" << std::endl;
    return;
  }

  if (!(board[pos_one] -> canMakeMove(board, pos_one, pos_two)))
    return;

  // TODO: Check for discovered check.

  board[pos_one] -> makeMove(board, pos_one, pos_two);
  switchPlayer();

}

void ChessBoard::removePieces() {
  std::map<ChessPosition, ChessPiece *>::iterator iter = board.begin();
  while (iter != board.end()) {
    if (iter -> second)
      delete iter -> second;
    iter++;
  }
  board.clear();
}

void ChessBoard::resetBoard() {

  // Clear existing board.
  removePieces();

  // Setup white pieces.
  board[ChessPosition("A1")] = new Rook(white);
  board[ChessPosition("H1")] = new Rook(white);
  board[ChessPosition("B1")] = new Knight(white);
  board[ChessPosition("G1")] = new Knight(white);
  board[ChessPosition("C1")] = new Bishop(white);
  board[ChessPosition("F1")] = new Bishop(white);
  board[ChessPosition("D1")] = new Queen(white);
  board[ChessPosition("E1")] = new King(white);

  // Setup white pawns.
  std::string coord;
  coord.push_back(MIN_FILE);
  coord.push_back(WHITE_PAWN_START_RANK);

  for(; coord[0] <= MAX_FILE; ++coord[0])
    board[ChessPosition(coord)] = new Pawn(white);

  // Setup black pieces.
  board[ChessPosition("A8")] = new Rook(black);
  board[ChessPosition("H8")] = new Rook(black);
  board[ChessPosition("B8")] = new Knight(black);
  board[ChessPosition("G8")] = new Knight(black);
  board[ChessPosition("C8")] = new Bishop(black);
  board[ChessPosition("F8")] = new Bishop(black);
  board[ChessPosition("D8")] = new Queen(black);
  board[ChessPosition("E8")] = new King(black);

  // Setup black pawns.
  coord = "";
  coord.push_back(MIN_FILE);
  coord.push_back(BLACK_PAWN_START_RANK);

  for(; coord[0] <= MAX_FILE; ++coord[0])
    board[ChessPosition(coord)] = new Pawn(black);

  currentPlayer = white;
}

bool ChessBoard::isInCheck(PieceColor player) {
  ChessPosition kingPosition = findKing(player);
  std::map<ChessPosition, ChessPiece *>::iterator iter = board.begin();
  while (iter != board.end()) {
    ChessPiece *piece = iter -> second;
    if (piece and (piece -> color != player) and
        piece -> canMakeMove(board, iter -> first, kingPosition)) {
      return true;
    }
    iter++;
  }
  return false;
}

bool ChessBoard::isInCheckMate(PieceColor player) {

}

ChessPosition ChessBoard::findKing(PieceColor player) {
  std::map<ChessPosition, ChessPiece *>::iterator iter = board.begin();
  while (iter != board.end()) {
    if ((iter -> second -> getPieceName() == "King") and
        (iter -> second -> color == player)) {
      break;
    }
    iter++;
  }
  return iter -> first;
}
