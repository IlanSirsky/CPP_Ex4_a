#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Game.hpp"

//int COIN_FOR_COUP = 7;
#define COIN_FOR_COUP 7

using namespace std;
namespace coup{
    class Player{
        protected:
            Game& game; // the game this player is in
            int money; //amount of coins the player has
            string name; //players' name
            Player(Game& game, const string& name); //abstract constructor
            string last_operation; //keeps the last operation the player performed for blocking purposes

        public:
            string getName();
            void income();
            void foreign_aid();
            virtual void coup(Player p);
            int coins() const;
            virtual string role();
            string getLastOperation();
            void addMoney(int money);
    };
}
