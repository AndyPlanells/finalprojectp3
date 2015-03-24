#include "hschar.h"
#include "characters.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

hschar::hschar(string name,string game,string type,string info,int manacost)
    :characters(name,game),type(type),info(info),manacost(manacost){

}

string hschar::toString(){
    stringstream ss;
    ss << characters::toString() << "Story:\n" << info;
    return ss.str();
}
string hschar::getType()const{
    return type;
}
void hschar::setType(string type){
    this->type=type;
}

string hschar::getInfo()const{
    return info;
}
void hschar::setinfo(string info){
    this->info=info;
}

int hschar::getManacost()const{
    return manacost;
}
void hschar::setManacost(int manacost){
    this->manacost=manacost;
}
