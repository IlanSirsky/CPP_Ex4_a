#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Game.hpp"

using namespace std;
namespace coup{
    class Player{
        protected:
            Game game;
            int money;
            string name;
        public:
            Player(Game game, string name);
            ~Player(){};
            string getName();
            void income();
            void foreign_aid();
            virtual void coup(Player p);
            int coins() const;
            virtual string role();
    };
}
