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

	return 0;
}
