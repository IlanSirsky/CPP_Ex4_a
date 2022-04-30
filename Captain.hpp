#pragma once

#include "Player.hpp"

using namespace std;
namespace coup{
    class Captain : public Player{
        public:
            Captain(Game& game, const string& name) : Player(game, name){};
            ~Captain(){};
            void steal(Player& p);
            void block(Player& p); 
            virtual string role();
    };
}