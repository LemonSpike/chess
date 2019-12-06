# ifndef CHESSMOVE_H
# define CHESSMOVE_H

# include <iostream>
# include <string>

class ChessPosition {

 public:
  std::string pos;

  ChessPosition(std::string pos): pos(pos) { };

  bool operator <(const ChessPosition& rhs) const { return pos < rhs.pos; }
  bool isPositionValid();
};

#endif
