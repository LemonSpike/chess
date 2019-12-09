# include "ChessBoard.h"

void ChessBoard::switchPlayer() {
  if (currentPlayer == white)
    currentPlayer = black;
  else
    currentPlayer = white;
}

void ChessBoard::submitMove(std::string positionOne, std::string positionTwo) {

  // Check if the game is already over.
  if (gameOver) {
    std::cout << "The game is already over, so no more moves can be made!";
    std::cout << std::endl << std::endl;
    return;
  }

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
    std::cout << "It is not " << ((board[pos_one] -> color == white) ?
				  "White's " : "Black's ");
    std::cout << "turn to move!" << std::endl;
    return;
  }

  if (!(board[pos_one] -> canMakeMove(board, pos_one, pos_two)))
    return;

  ChessPiece *startPiece = board[pos_one];
  ChessPiece *endPiece = board[pos_two];
  board[pos_one] -> makeMove(board, pos_one, pos_two);

  // Check for discovered check.
  if (isInCheck(currentPlayer)) {
    // Undo move.
    board[pos_one] = startPiece;
    board[pos_two] = endPiece;
    std::cout << ((currentPlayer == white) ? "White's " : "Black's ");
    std::cout << *startPiece << " cannot move to " << pos_two.pos << "!";
    std::cout << std::endl;
  } else {
    board[pos_one] -> printMove(startPiece, endPiece, pos_one, pos_two);
  }

  if (endPiece != nullptr)
    delete endPiece;

  switchPlayer();

  if (isInCheckMate(currentPlayer)) {
    std::cout << ((currentPlayer == white) ? "White " : "Black ");
    std::cout << "is in checkmate" << std::endl;
    gameOver = true;
  } else if (isInCheck(currentPlayer)) {
    std::cout << ((currentPlayer == white) ? "White " : "Black ");
    std::cout << "is in check" << std::endl;
  } else if (isStaleMate(currentPlayer)) {
    std::cout << ((currentPlayer == white) ? "White " : "Black ");
    std::cout << "is in stalemate!" << std::endl;
    gameOver = true;
  }
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
  gameOver = false;

  std::cout << "A new chess game is started!" << std::endl;
}

bool ChessBoard::isInCheck(PieceColor player) {
  ChessPosition kingPosition = findKing(board, player);
  return !findThreats(board, kingPosition).empty();
}

bool ChessBoard::isInCheckMate(PieceColor player) {
  return isInCheck(player) and isStaleMate(player);
}

bool ChessBoard::isStaleMate(PieceColor player) {

  // Iterate across all player pieces to check if they can move.
  std::map<ChessPosition, ChessPiece *>::iterator iter = board.begin();
  while (iter != board.end()) {

    // Check if piece exists at current position.
    if (!(iter -> second)) {
      iter++;
      continue;
    }

    // Check if piece belongs to current player.
    if (iter -> second -> color != player) {
      iter++;
      continue;
    }

    // Check if moves without getting check can be made.
    if (!evaluateThreats(board, iter -> first, player))
      return false;

    iter++;
  }
  return true;
}

bool ChessBoard::evaluateThreats(std::map<ChessPosition,
                                 ChessPiece *> boardCopy,
                                 ChessPosition current,
                                 PieceColor player) {

  ChessPiece *mover = boardCopy[current];
  mover -> getAllMoves(boardCopy, current);
  std::vector<ChessPosition> moves = mover -> allMoves;
  ChessPiece *captured = nullptr;

  for (unsigned int i = 0; i < moves.size(); ++i) {
    // Make move.
    if (boardCopy.find(moves[i]) != boardCopy.end())
      captured = boardCopy[moves[i]];
    boardCopy[moves[i]] = boardCopy[current];
    boardCopy.erase(current);

    // Find all threats to current players' King.
    std::vector<ChessPosition> threats = findThreats(boardCopy,
                                                     findKing(boardCopy,
                                                              player));

    // Redact move.
    boardCopy[current] = mover;
    if (captured)
      boardCopy[moves[i]] = captured;
    else
      boardCopy.erase(moves[i]);
    captured = nullptr;

    // If threats can be neutralised, return false.
    if (threats.empty())
      return false;
  }
  return true;
}

std::vector<ChessPosition> ChessBoard::findThreats(std::map<ChessPosition,
                                                   ChessPiece *> boardCopy,
                                                   ChessPosition kingPosition) {

  // Iterate across all pieces to check if they can attack the king.
  std::map<ChessPosition, ChessPiece *>::iterator iter = boardCopy.begin();
  std::vector<ChessPosition> threats;
  while (iter != boardCopy.end()) {
    ChessPiece *piece = iter -> second;
    if (piece and (piece -> color != currentPlayer) and
        piece -> isSquareReachable(boardCopy, iter -> first, kingPosition))
          threats.push_back(iter -> first);
    iter++;
  }
  return threats;
}

ChessPosition ChessBoard::findKing(std::map<ChessPosition,
                                   ChessPiece *> boardCopy,
                                   PieceColor player) {
  std::map<ChessPosition, ChessPiece *>::iterator iter = boardCopy.begin();
  while (iter != boardCopy.end()) {
    if ((iter -> second) and (iter -> second -> getPieceName() == "King")
        and (iter -> second -> color == player)) {
      break;
    }
    iter++;
  }
  return iter -> first;
}
