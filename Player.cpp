#include "Player.hpp"

using namespace std;
namespace coup{
    Player::Player(Game& game, const string& name) : game(game){
        this->name = name;
        this->money = 0;
        this->game.addPlayer(name);
    }

    string Player::getName(){
        return this->name;
    }

    //adding 1 coin to the player, can't be blocked
    void Player::income(){
        if (!this->game.checkIfTurn(this->name)){
            throw invalid_argument("It is not your turn");
        }
        this->last_operation = "income";
        this->money += 1;
        this->game.turn_counter++;
    }

    //adding 2 coins to the player, may be blocked by Duke
    void Player::foreign_aid(){
        if (!this->game.checkIfTurn(this->name)){
            throw invalid_argument("It is not your turn");
        }
        this->last_operation = "foreign_aid";
        this->money += 2;
        this->game.turn_counter++;
    }

    //killing a player, can't be blocked
    void Player::coup(Player p){
        if (!this->game.checkIfTurn(this->name)){
            throw invalid_argument("It is not your turn");
        }
        if (this->money < COIN_FOR_COUP){
            throw invalid_argument("Not enough coins");
        }
        this->last_operation = "coup";
        this->game.removePlayer(p.getName());
        this->money -= COIN_FOR_COUP;
        this->game.turn_counter++;
    }

    //returns the amount of coins the player has
    int Player::coins() const{
        return money;
    }

    //returns the role of the player
    string Player::role(){
        return "Player";
    }

    //returns the last operation the player performed
    string Player::getLastOperation(){
        return this->last_operation;
    }

    //adding or removing coins from the player
    void Player::addMoney(int money){
        this->money += money;
    }
}