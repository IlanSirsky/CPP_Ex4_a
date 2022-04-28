#include "Game.hpp"

using namespace std;
namespace coup{
    Game::Game(){}
    string Game::turn(){
        return player_turn;
    }
    vector<string> Game::players(){
        return playing;
    }
    string Game::winner(){
        return playing.at(0);
    }
}