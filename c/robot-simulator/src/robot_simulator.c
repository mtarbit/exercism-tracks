#include "robot_simulator.h"

robot_grid_status_t robot_init(void) {
    robot_grid_status_t robot = {
        .bearing = DEFAULT_BEARING,
        .grid = {
            .x_position = DEFAULT_X_COORDINATE,
            .y_position = DEFAULT_Y_COORDINATE,
        }
    };
    return robot;
}

robot_grid_status_t robot_init_with_position(int bearing, int x, int y) {
    robot_grid_status_t robot = robot_init();
    if (bearing >= 0 && bearing < HEADING_MAX) {
        robot.bearing = bearing;
    }
    robot.grid.x_position = x;
    robot.grid.y_position = y;
    return robot;
}

void robot_turn_right(robot_grid_status_t * robot) {
    if (robot->bearing == HEADING_WEST) {
        robot->bearing = HEADING_NORTH;
    } else {
        robot->bearing += 1;
    }
}

void robot_turn_left(robot_grid_status_t * robot) {
    if (robot->bearing == HEADING_NORTH) {
        robot->bearing = HEADING_WEST;
    } else {
        robot->bearing -= 1;
    }
}

void robot_advance(robot_grid_status_t * robot) {
    switch (robot->bearing) {
        case HEADING_NORTH: robot->grid.y_position += 1; break;
        case HEADING_EAST:  robot->grid.x_position += 1; break;
        case HEADING_SOUTH: robot->grid.y_position -= 1; break;
        case HEADING_WEST:  robot->grid.x_position -= 1; break;
        case HEADING_MAX:   break;
    }
}

void robot_simulator(robot_grid_status_t * robot, const char *commands) {
    char c;
    while ((c = *commands++) != '\0') {
        switch (c) {
            case 'R': robot_turn_right(robot); break;
            case 'L': robot_turn_left(robot); break;
            case 'A': robot_advance(robot); break;
        }
    }
}
