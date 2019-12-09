# include "ChessBoard.h"
# include <iostream>

int main() {

  std::cout << "========================\n";
  std::cout << "Testing the Chess Engine\n";
  std::cout << "========================\n\n";

  ChessBoard cb;
  std::cout << '\n';

  cb.submitMove("D7", "D6");
  std::cout << '\n';

  cb.submitMove("D4", "H6");
  std::cout << '\n';

  cb.submitMove("D2", "D4");
  std::cout << '\n';

  cb.submitMove("F8", "B4");
  std::cout << '\n';

  std::cout << "=========================\n";
  std::cout << "Alekhine vs. Vasic (1931)\n";
  std::cout << "=========================\n\n";

  cb.resetBoard();
  std::cout << '\n';

  cb.submitMove("E2", "E4");
  cb.submitMove("E7", "E6");
  std::cout << '\n';

  cb.submitMove("D2", "D4");
  cb.submitMove("D7", "D5");
  std::cout << '\n';

  cb.submitMove("B1", "C3");
  cb.submitMove("F8", "B4");
  std::cout << '\n';

  cb.submitMove("F1", "D3");
  cb.submitMove("B4", "C3");
  std::cout << '\n';

  cb.submitMove("B2", "C3");
  cb.submitMove("H7", "H6");
  std::cout << '\n';

  cb.submitMove("C1", "A3");
  cb.submitMove("B8", "D7");
  std::cout << '\n';

  cb.submitMove("D1", "E2");
  cb.submitMove("D5", "E4");
  std::cout << '\n';

  cb.submitMove("D3", "E4");
  cb.submitMove("G8", "F6");
  std::cout << '\n';

  cb.submitMove("E4", "D3");
  cb.submitMove("B7", "B6");
  std::cout << '\n';

  cb.submitMove("E2", "E6");
  cb.submitMove("F7", "E6");
  std::cout << '\n';

  cb.submitMove("D3", "G6");
  std::cout << '\n';

  std::cout << "=========================\n";
  std::cout << "Stalemate Example\n";
  std::cout << "=========================\n\n";
  cb.resetBoard();
  std::cout << '\n';

  cb.submitMove("E2", "E3");
  cb.submitMove("A7", "A5");
  std::cout << '\n';

  cb.submitMove("D1", "H5");
  cb.submitMove("A8", "A6");
  std::cout << '\n';

  cb.submitMove("H5", "A5");
  cb.submitMove("H7", "H5");
  std::cout << '\n';

  cb.submitMove("H2", "H4");
  cb.submitMove("A6", "H6");
  std::cout << '\n';

  cb.submitMove("A5", "C7");
  cb.submitMove("F7", "F6");
  std::cout << '\n';

  cb.submitMove("C7", "D7");
  cb.submitMove("E8", "F7");
  std::cout << '\n';

  cb.submitMove("D7", "B7");
  cb.submitMove("D8", "D3");
  std::cout << '\n';

  cb.submitMove("B7", "B8");
  cb.submitMove("D3", "H7");
  std::cout << '\n';

  cb.submitMove("B8", "C8");
  cb.submitMove("F7", "G6");
  std::cout << '\n';

  cb.submitMove("C8", "E6");
  std::cout << '\n';

  std::cout << "=========================\n";
  std::cout << "Checkmate Example 1\n";
  std::cout << "=========================\n\n";
  cb.resetBoard();
  std::cout << '\n';

  cb.submitMove("F2", "F3");
  cb.submitMove("E7", "E5");
  std::cout << '\n';

  cb.submitMove("G2", "g4");
  cb.submitMove("d8", "h4");
  std::cout << '\n';

  std::cout << "=========================\n";
  std::cout << "Checkmate Example 2\n";
  std::cout << "=========================\n\n";
  cb.resetBoard();
  std::cout << '\n';

  cb.submitMove("H2", "H4");
  cb.submitMove("E7", "E5");
  std::cout << '\n';

  cb.submitMove("G2", "g4");
  cb.submitMove("b8", "c6");
  std::cout << '\n';

  cb.submitMove("F2", "F4");
  cb.submitMove("E5", "f4");
  std::cout << '\n';

  cb.submitMove("E2", "E4");
  cb.submitMove("d7", "d5");
  std::cout << '\n';

  cb.submitMove("e4", "d5");
  cb.submitMove("d8", "d5");
  std::cout << '\n';

  cb.submitMove("B1", "c3");
  cb.submitMove("d5", "h1");
  std::cout << '\n';

  cb.submitMove("g1", "e2");
  cb.submitMove("h1", "h4");
  std::cout << '\n';

  cb.submitMove("e2", "g3");
  cb.submitMove("h4", "g3");
  std::cout << '\n';

  cb.submitMove("e1", "e2");
  cb.submitMove("c8", "g4");
  std::cout << '\n';

  std::cout << "=========================\n";
  std::cout << "Checkmate Example 3\n";
  std::cout << "=========================\n\n";
  cb.resetBoard();
  std::cout << '\n';

  cb.submitMove("e2", "e4");
  cb.submitMove("e7", "e5");
  std::cout << '\n';

  cb.submitMove("d1", "h5");
  cb.submitMove("b8", "c6");
  std::cout << '\n';

  cb.submitMove("f1", "c4");
  cb.submitMove("g8", "f6");
  std::cout << '\n';

  cb.submitMove("h5", "f7");
  std::cout << '\n';

  // Test invalid move after game over.
  cb.submitMove("e7", "e6");
  return 0;
}
