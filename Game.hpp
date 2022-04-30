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
            size_t player_turn = 0; // index of the player who's turn it is
            string last_died = ""; //name of the last player that died
            int last_dead_index = 0; //index of the last player that died

        public:
            Game();
            ~Game(){};
            string turn();
            vector<string> players();
            string winner();
            void addPlayer(const string& name);
            void revivePlayer(const string& name, int index);
            void removePlayer(const string& name); 
            string getLastDied() const; 
            int getLastDeadIndex() const; 
    };
}