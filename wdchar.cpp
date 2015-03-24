#include "wdchar.h"
#include "characters.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

wdchar::wdchar(string name,string game,int level,string type,string race,string gender)
    :characters(name,game),level(level),type(type),race(race),gender(gender){

}

string wdchar::toString(){
    stringstream ss;
    ss << characters::toString() << "Level: "<<level<<"\nClass: "<<type<<"\nRace: "<<race<<"\nGender: "<<gender;
    return ss.str();
}


int wdchar::getLevel()const{
    return level;
}
void wdchar::setLevel(int level){
    this->level=level;
}

string wdchar::getType()const{
    return type;
}
void wdchar::setType(string type){
    this->type=type;
}

string wdchar::getRace()const{
    return race;
}
void wdchar::setRace(string race){
    this->race=race;
}

string wdchar::getGender()const{
    return gender;
}
void wdchar::setGender(string gender){
    this->gender=gender;
}
