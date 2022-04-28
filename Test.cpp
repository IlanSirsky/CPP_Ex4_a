#include "doctest.h"
#include "Player.hpp"
#include "Game.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Assassin.hpp"
#include "Duke.hpp"
#include "Contessa.hpp"

using namespace coup;
using namespace std;


TEST_CASE("Player functions"){
    Game g1{};
    Captain cap = Captain(g1, "Jack Sparrow");
    Captain cap2 = Captain(g1, "Captain Hook");
    CHECK(cap.coins() == 0);
    cap.income();
    CHECK(cap.coins() == 1);
    cap.foreign_aid();
    CHECK(cap.coins() == 3);
    cap.foreign_aid();
    cap.foreign_aid();
    CHECK_NOTHROW(cap.coup(cap2));
    CHECK(cap.coins() == 0);
    CHECK(cap.role()=="Captain");
    CHECK(cap.getName()=="Jack Sparrow");
}

TEST_CASE("Ambassador"){
    Game g1{};
    Ambassador amb = Ambassador(g1, "Ameba");
    Captain cap = Captain(g1, "Jack Sparrow");
    Assassin ass = Assassin(g1, "Assassin");
    amb.income();
    cap.income();
    ass.income();
    CHECK_NOTHROW(amb.transfer(cap, ass));
    CHECK_THROWS(amb.transfer(cap, ass));
    CHECK_THROWS(amb.block(ass));
    CHECK_NOTHROW(amb.block(cap));
    CHECK(amb.role()=="Ambassador");
}

TEST_CASE("Assassin"){
    Game g1{};
    Assassin ass = Assassin(g1, "Assassin");
    Captain cap = Captain(g1, "Jack Sparrow");
    Contessa con = Contessa(g1, "Contessa");
    ass.income();
    ass.foreign_aid();
    CHECK_NOTHROW(ass.coup(cap));
    CHECK(g1.players().size()==2);
    con.block(ass);
    CHECK(g1.players().size()==3);
    CHECK(ass.coins()==0);
    CHECK(ass.role()=="Assassin");
}

TEST_CASE("Captain"){
    Game g1{};
    Captain cap = Captain(g1, "Jack Sparrow");
    Captain cap2 = Captain(g1, "Captain Hook");
    Assassin ass = Assassin(g1, "Assassin");
    cap2.foreign_aid();
    CHECK_NOTHROW(cap.steal(cap2));
    CHECK(cap.coins()==2);
    cap2.block(cap);
    CHECK(cap.coins()==0);
    CHECK(cap2.coins()==2);
    CHECK_THROWS(cap.steal(ass));
    CHECK(cap.role()=="Captain");
}

TEST_CASE("Contessa"){
    Game g1{};
    Contessa con = Contessa(g1, "Contessa");
    Assassin ass = Assassin(g1, "Assassin");
    Captain cap = Captain(g1, "Jack Sparrow");
    ass.income();
    ass.foreign_aid();
    ass.coup(cap);
    CHECK(g1.players().size()==2);
    CHECK_NOTHROW(con.block(ass));
    CHECK(g1.players().size()==3);
    CHECK_THROWS(con.block(cap));
    CHECK(con.role()=="Contessa");
}

TEST_CASE("Duke"){
    Game g1{};
    Duke duke = Duke(g1, "Duke");
    Captain cap = Captain(g1, "Jack Sparrow");
    
    duke.tax();
    CHECK(duke.coins()==3);
    cap.foreign_aid();
    CHECK(cap.coins()==2);
    CHECK_NOTHROW(duke.block(cap));
    CHECK(duke.coins()==0);
    CHECK(duke.role()=="Duke");
}