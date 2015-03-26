#include "sc2.h"
#include "games.h"
#include <string>
#include <sstream>
#include <vector>
#include "characters.h"
#include "shochar.h"

using std::vector;

using std::stringstream;
using std::string;


sc2::sc2(bool ifbought,string name,bool wol,bool hts):games(ifbought,name),wol(wol),hts(hts){

}

string sc2::toString(){
    stringstream ss;
    bool ifgames = games::getIfbought();
    if(ifgames){
        ss<< games::toString() << "\nExpansions:\nWings of liberty:\n"<< games::ActiveMessage(this->getWol()) <<
             "\nHeart of the swarm:\n" << games::ActiveMessage(this->getHts());
    }else{
        ss<< games::toString() << "This game hasn't been bought yet.";
    }
       return ss.str();
}

bool sc2::getWol()const{
    return wol;
}
void sc2::setWol(bool wol){
    this->wol=wol;
}

bool sc2::getHts()const{
    return hts;
}
void sc2::setHts(bool hts){
    this->hts=hts;
}

vector<shochar> sc2::getMychars()const{
    return mychars;
}
void sc2::setMchars(vector<shochar> mychars){
    this->mychars=mychars;
}
