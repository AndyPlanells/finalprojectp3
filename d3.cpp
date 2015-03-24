#include "d3.h"
#include "games.h"
#include <string>
#include <sstream>
#include <vector>
#include "characters.h"
#include "wdchar.h"

using std::vector;
using std::string;
using std::stringstream;

d3::d3(bool ifbought,string name,bool ros):games(ifbought,name),ros(ros){

}

string d3::toString(){
    stringstream ss;
    bool ifgames = games::getIfbought();
    if(ifgames){
        ss<< games::toString() <<
             "Expansions:\nReaper of Souls:\n" << games::ActiveMessage(ros);
    }else{
        ss<< games::toString() << "This game hasn't been bought yet.";
    }
       return ss.str();
}

bool d3::getRos(){
    return ros;
}

void d3::setRos(bool ros){
    this->ros=ros;
}


vector<wdchar> d3::getMychars()const{
    return mychars;
}
