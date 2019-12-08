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

  cb.submitMove("E2", "E3");
  std::cout << '\n';

  cb.submitMove("A7", "A5");
  std::cout << '\n';

  cb.submitMove("D1", "H5");
  std::cout << '\n';

  cb.submitMove("A8", "A6");
  std::cout << '\n';

  cb.submitMove("H5", "A5");
  std::cout << '\n';

  cb.submitMove("H7", "H5");
  std::cout << '\n';

  cb.submitMove("H2", "H4");
  std::cout << '\n';

  cb.submitMove("A6", "H6");
  std::cout << '\n';

  cb.submitMove("A5", "C7");
  std::cout << '\n';

  cb.submitMove("F7", "F6");
  std::cout << '\n';

  cb.submitMove("C7", "D7");
  std::cout << '\n';

  cb.submitMove("E8", "F7");
  std::cout << '\n';

  cb.submitMove("D7", "B7");
  std::cout << '\n';

  cb.submitMove("D8", "D3");
  std::cout << '\n';

  cb.submitMove("B7", "B8");
  std::cout << '\n';

  cb.submitMove("D3", "H7");
  std::cout << '\n';

  cb.submitMove("B8", "C8");
  std::cout << '\n';

  cb.submitMove("F7", "G6");
  std::cout << '\n';

  cb.submitMove("C8", "E6");
  std::cout << '\n';

  return 0;
}
