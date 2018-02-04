#include <iostream>
#include <thread>
#include <chrono>
#include "board.h"

void delay() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int main() {
    int width, height;
    std::cout << "enter board width: ";
    std::cin >> width;
    std::cout << "enter board height: ";
    std::cin >> height;
    board b(height, width);
    while (true) {
        system("clear");
        b.draw_board();
        b.calculate();
        delay();
    }
    return 0;
}