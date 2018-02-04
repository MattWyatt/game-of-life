#ifndef CONWAY_S_GAME_OF_LIFE_CELL_H
#define CONWAY_S_GAME_OF_LIFE_CELL_H

class cell {
private:
    bool _state;
public:
    bool state();
    void kill();
    void revive();
    void set_random();
};


#endif //CONWAY_S_GAME_OF_LIFE_CELL_H
