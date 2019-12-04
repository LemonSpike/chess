# ifndef CHESSMOVE_H
# define CHESSMOVE_H

# include <iostream>
# include <string>

class ChessMove {
  std::string pos_one;
  std::string pos_two;

  bool checkPositionIsValid(std::string position);

 public:
  ChessMove(std::string pos_one, std::string pos_two):
  pos_one(pos_one), pos_two(pos_two) { };

  bool arePositionsValid();
};

#endif
