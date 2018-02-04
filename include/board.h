#ifndef CONWAY_S_GAME_OF_LIFE_BOARD_H
#define CONWAY_S_GAME_OF_LIFE_BOARD_H

#include "cell.h"
#include <utility>
#include <vector>

typedef std::pair<signed int, signed int> direction;

class board {
private:
    unsigned int _height;
    unsigned int _width;
    const static std::vector<direction> _directions;
    std::vector<std::vector<cell>> _board;
    std::vector<std::vector<cell>> _board2;

public:
    board(unsigned int height, unsigned int width);
    void draw_board();
    int get_living(unsigned int height, unsigned int width);
    void calculate();
};


#endif //CONWAY_S_GAME_OF_LIFE_BOARD_H
