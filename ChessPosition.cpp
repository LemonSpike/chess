# include "ChessPosition.h"

bool ChessPosition::isPositionValid() {
  if (pos.size() != 2)
    return false;


  for (int i = 0; i < 2; i++) {
    pos[i] = std::toupper(pos[i]);
  }
  if (pos[0] < 'A' or pos[0] > 'H')
    return false;
  if (pos[1] < '1' or pos[1] > '8')
    return false;

  return true;
}
