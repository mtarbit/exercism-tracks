#include <stdlib.h>
#include "queen_attack.h"

#define BOARD_SIZE 8

uint8_t is_off_board(position_t p) {
    return (p.row >= BOARD_SIZE || p.column >= BOARD_SIZE);
}

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    if (is_off_board(queen_1) || is_off_board(queen_2)) {
        return INVALID_POSITION;
    }

    uint8_t dr = abs(queen_1.row - queen_2.row);
    uint8_t dc = abs(queen_1.column - queen_2.column);

    if (dr == 0 && dc == 0) {
        return INVALID_POSITION;
    } else if (dr == 0 || dc == 0 || dr == dc) {
        return CAN_ATTACK;
    } else {
        return CAN_NOT_ATTACK;
    }
}
