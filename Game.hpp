#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Game.hpp"

using namespace std;
namespace coup{
    class Game{
        private:
            vector<string> playing;
            string player_turn;
        public:
            Game();
            ~Game(){};
            string turn();
            vector<string> players();
            string winner();
    };
}