#include "Ambassador.hpp"

using namespace std;
namespace coup{

    //blocking a Captain from stealing coins from another player
    void Ambassador::block(Player& p){ 
        if (p.role() != "Captain"){ //blocks only Captains
            throw invalid_argument("Can only block Captain");
        }
        if (p.getLastOperation() != "steal"){ //blocking only after stealing
            throw invalid_argument("Can only block after stealing");
        }
        this->last_operation = "block";
        //need to finish block
    }

    //transferring 1 coin from one player to another, can't be blocked
    void Ambassador::transfer(Player& from_player, Player & to_player){
        if (from_player.coins() < 1){ //transferring only if there is at least 1 coin
            throw invalid_argument("Not enough coins");
        }
        from_player.addMoney(-1);
        to_player.addMoney(1);
        this->last_operation = "transfer";
    }
    
    string Ambassador::role(){
        return "Ambassador";
    }
}