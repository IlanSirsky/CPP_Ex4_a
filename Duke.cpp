#include "Duke.hpp"

using namespace std;
namespace coup{

    //taking 3 coins from the bank, can't be blocked
    void Duke::tax(){
        this->money += 3;
        this->last_operation = "tax";
    }
    
    //blocking other players from using foreign aid
    void Duke::block(Player& p){
        if (p.getLastOperation() != "foreign_aid"){
            throw invalid_argument("Can only block foreign aid");
        }
        p.addMoney(-2); //blocked player returns the 2 coins to the bank
        this->last_operation = "block";
    }  

    string Duke::role(){
        return "Duke";
    }
}