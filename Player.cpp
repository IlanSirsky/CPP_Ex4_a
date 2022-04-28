#include "Player.hpp"

using namespace std;
namespace coup{
    Player::Player(Game game, string name){
        this->name = name;
        this->game = game;
        this->money = 0;
    }
    string Player::getName(){
        return this->name;
    }
    void Player::income(){
        this->money += 1;
    }
    void Player::foreign_aid(){
        this->money += 2;
    }
    void Player::coup(Player p){
        this->money -= 7;
    }
    int Player::coins() const{
        return money;
    }
    string Player::role(){
        return "Player";
    }
}