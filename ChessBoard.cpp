# include "ChessBoard.h"

void ChessBoard::submitMove(std::string positionOne, std::string positionTwo) {
  ChessMove move(positionOne, positionTwo);
  if (!move.arePositionsValid())
    return;
  
}

void ChessBoard::resetBoard() {

}
