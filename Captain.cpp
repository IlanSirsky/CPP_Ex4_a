#include "Captain.hpp"

using namespace std;
namespace coup{

    //stealing 2 coins from another player, can be blocked by another Captain or an Ambassador
    void Captain::steal(Player& p){
        if (p.coins() < 1){ //checking if there is enough coins to steal
            throw invalid_argument("Not enough coins");
        }
        if (p.coins() == 1){ //stealing 1 coin if there is only 1 coin
            p.addMoney(-1);
            this->money += 1;
        }
        else{ //stealing 2 coins
            p.addMoney(-2);
            this->money += 2;
        }
        this->last_operation = "steal";
    }

    //blocking another Captain from stealing coins from another player
    void Captain::block(Player& p){
        if (p.role() != "Captain"){ //blocks only Captains
            throw invalid_argument("Can only block another Captain");
        }
        if (p.getLastOperation() != "steal"){ //blocking only after stealing
            throw invalid_argument("Can only block after stealing");
        } 
        this->last_operation = "block";
        //need to finish block
    }

    string Captain::role(){
        return "Captain";
    }
}