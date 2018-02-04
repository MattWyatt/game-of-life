//
// Created by matt on 12/19/17.
//
#include <iostream>
#include <ctime>
#include "board.h"

const std::vector<direction> board::_directions = {
        direction(1, -1),
        direction(1, 0),
        direction(1, 1),
        direction(0, 1),
        direction(-1, 1),
        direction(-1, 0),
        direction(-1, -1),
        direction(0, -1)
};

board::board(unsigned int height, unsigned int width) {
    _height = height;
    _width = width;

    srand((int)time(0));
    for (int h = 0; h < _height; h++) {
        _board.push_back(std::vector<cell>());
        _board2.push_back(std::vector<cell>());
        for (int w = 0; w < _width; w++) {
            _board.at(h).push_back(cell());
            _board2.at(h).push_back(cell());
            _board.at(h).at(w).set_random();
            _board2.at(h).at(w).kill();
        }
    }
}

void board::draw_board() {
    _board2 = _board;
    for (int h = 0; h < _height; h++) {
        for (int w = 0; w < _width; w++) {
            if (_board.at(h).at(w).state()) {
                if (get_living(h, w) < 2 || get_living(h, w) > 3) {
                    std::cout << "\033[1;31mO\033[0m";
                }
                else {
                    std::cout << "\033[1;32mO\033[0m";
                }
            }
            else {
                if (get_living(h, w) == 3) {
                    std::cout << "\033[1;33m#\033[0m";
                }
                else {
                    std::cout << "#";
                }
            }
        }
        std::cout << std::endl;
    }
}

int board::get_living(unsigned int height, unsigned int width) {
    int sum = 0;
    for (auto iterator : _directions) {
        try {
            sum += (_board2.at(height + iterator.first).at(width + iterator.second).state());
        }
        catch (std::out_of_range) {

        }
    }
    return sum;
}

void board::calculate() {
    _board2 = _board;

    for (int h = 0; h < _height; h++) {
        for (int w = 0; w < _width; w++) {
            int sum = get_living(h, w);
            if (sum < 2) {
                _board.at(h).at(w).kill();
            }
            else if (sum > 3) {
                _board.at(h).at(w).kill();
            }
            else if (sum == 3) {
                _board.at(h).at(w).revive();
            }
        }
    }
}