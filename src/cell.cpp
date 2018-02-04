//
// Created by matt on 12/19/17.
//

#include <cstdlib>
#include "cell.h"

bool cell::state() {
    return _state;
}

void cell::kill() {
    if (_state) {
        _state = false;
    }
}

void cell::revive() {
    if (!_state) {
        _state = true;
    }
}

void cell::set_random() {
    _state = rand() % 2;
}