# include "ChessMove.h"

bool ChessMove::arePositionsValid() {
  if (!checkPositionIsValid(pos_one)) {
    std::cout << "Position " << pos_one << " does not exist!" << std::endl;
    return false;
  } else if (!checkPositionIsValid(pos_two)) {
    std::cout << "Position " << pos_two << " does not exist!" << std::endl;
    return false;
  }
  return true;
}

bool ChessMove::checkPositionIsValid(std::string position) {

  if (position.size() != 2)
    return false;

  for(unsigned int i = 0; i < position.size(); i++){
    position[i] = std::toupper(position[i]);
  }

  if (position[0] < 'A' or position[0] > 'H')
    return false;
  if (position[1] < '1' or position[1] > '8')
    return false;

  return true;
}
