# include "ChessBoard.h"

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

  if (!board[pos_one] -> canMakeMove(board, pos_one, pos_two))
    return;

  // TODO: Check for discovered check.
  // board[pos_one] -> makeMove(board, pos_two);
}

void ChessBoard::resetBoard() {

  auto iter = board.begin();
  while (iter != board.end()) {
    delete iter -> second;
  }
  board.clear();

  // Setup white pieces.
  board[ChessPosition("A1")] = new Rook(white);
  board[ChessPosition("H1")] = new Rook(white);
  board[ChessPosition("B1")] = new Knight(white);
  board[ChessPosition("G1")] = new Knight(white);
  board[ChessPosition("C1")] = new Bishop(white);
  board[ChessPosition("F1")] = new Bishop(white);
  board[ChessPosition("D1")] = new Queen(white);
  board[ChessPosition("E1")] = new King(white);

  std::string coord;
  for(coord = "A2"; coord[0] <= 'H'; ++coord[0])
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

  for(coord = "A7"; coord[0] <= 'H'; ++coord[0])
    board[ChessPosition(coord)] = new Pawn(black);
}
