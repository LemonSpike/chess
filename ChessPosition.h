# ifndef CHESSMOVE_H
# define CHESSMOVE_H

# include <iostream>
# include <string>

class ChessPosition {

 public:
  // Stores the string representation of the position.
  std::string pos;

  ChessPosition(std::string pos): pos(pos) { };

  // Used for checking if two positions are equal.
  bool operator ==(const ChessPosition& rhs) const { return pos == rhs.pos; }
  // Needed for keying in the board map.
  bool operator <(const ChessPosition& rhs) const { return pos < rhs.pos; }

  // Helper function which returns true if a position exists
  // on the traditional chess board. Otherwise it returns false.
  bool isPositionValid();
};

#endif
