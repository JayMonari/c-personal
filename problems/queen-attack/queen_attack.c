#include "queen_attack.h"

bool is_invalid_position(position_t q1, position_t q2) {
  return ((q1.row == q2.row && q1.column == q2.column) ||
          (q1.row > 7 || q2.row > 7 || q1.column > 7 || q2.column > 7));
}

attack_status_t can_attack(position_t q1, position_t q2) {
  if (is_invalid_position(q1, q2))
    return INVALID_POSITION;

  if (q1.row == q2.row || q1.column == q2.column ||
      abs(q1.column - q2.column) == abs(q1.row - q2.row))
    return CAN_ATTACK;

  return CAN_NOT_ATTACK;
}
