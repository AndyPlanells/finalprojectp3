#include "wow.h"
#include "games.h"
#include <string>
#include <sstream>
#include "characters.h"
#include "wdchar.h"

using std::string;
using std::stringstream;
using std::vector;

wow::wow(bool ifbought,string name,int gametime,bool wowstat,bool tbc,bool wotlk,bool cata,bool mop,bool wod)
    :games(ifbought,name),gametime(gametime),wowstat(wowstat),tbc(tbc),wotlk(wotlk),cata(cata),mop(mop),wod(wod){

}

string wow::toString(){
    stringstream ss;
    bool ifgames = games::getIfbought();
    if(ifgames){
        ss<< games::toString() << "Gametime: "  << gametime <<
             "\n Account Status:\n" << games::ActiveMessage(this->getWowstat()) <<
             "\nExpansions:\nThe Burning Crusade:\n"<< games::ActiveMessage(this->getTbc()) <<
             "\nWrath of the Lich King:\n" << games::ActiveMessage(this->getWotlk()) <<
             "\nCataclysm:\n"<< games::ActiveMessage(this->getCata()) <<
             "\n Mists of Pandaria:\n" << games::ActiveMessage(this->getMop()) <<
             "\nWarlords of Draenor:\n"<< games::ActiveMessage(this->getWod());
    }else{
        ss<< games::toString() << "This game hasn't been bought yet.";
    }
       return ss.str();
}

int wow::getGametime()const{
    return gametime;
}
void wow::setGametime(int gametime){
    this->gametime=gametime;
}

bool wow::getWowstat()const{
    return wowstat;
}
void wow::setWowstat(bool wowstat){
    this->wowstat=wowstat;
}

bool wow::getTbc()const{
    return tbc;
}
void wow::setTbc(bool tbc){
    this->tbc=tbc;
}

bool wow::getWotlk()const{
    return wotlk;
}
void wow::setWotlk(bool wotlk){
    this->wotlk=wotlk;
}

bool wow::getCata()const{
    return cata;
}
void wow::setCata(bool cata){
    this->cata=cata;
}

bool wow::getMop()const{
    return mop;
}
void wow::setMop(bool mop){
    this->mop=mop;
}

bool wow::getWod()const{
    return wod;
}
void wow::setWod(bool wod){
    this->wod=wod;
}
