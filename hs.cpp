#include "hs.h"
#include "games.h"
#include "characters.h"
#include "hschar.h"
#include <string>
#include <sstream>
#include <vector>

using std::string;
using std::stringstream;
using std::vector;

Hs::Hs(bool ifbought,string name,bool founderpack):games(ifbought,name),founderpack(founderpack){

}

string Hs::toString(){
    stringstream ss;
    bool ifgames = games::getIfbought();
    if(ifgames){
        ss<< games::toString() << "\nExpansions:\nFounder's Pack:\n"<< games::ActiveMessage(this->getFounderpack()) <<"\n";
    }else{
        ss<< games::toString() << "This game hasn't been bought yet.";
    }
    return ss.str();
}

bool Hs::getFounderpack()const{
    return founderpack;
}
void Hs::setFounderpack(bool founderpack){
    this->founderpack=founderpack;
}

vector<hschar> Hs::getMychars()const{
    return mychars;
}
