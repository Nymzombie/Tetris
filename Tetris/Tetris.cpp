#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <chrono>
#include <thread>
#include <memory>




#include "Squares.h"
#include "Drawing.h"
#include "Generate_figure.h"
#include "square_drop.h"
#include "Square_move.h"
#include "Calculations.h"


#include "keyboard_handler.h"
#include "game_main.h"

using namespace std;

int main() {

    sf::RenderWindow window(sf::VideoMode(1040, 1039), "TETRIS!", sf::Style::None);

    game_main().start_The_game(window);

    return 0;

}