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

}
