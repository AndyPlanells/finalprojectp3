#include "characters.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

characters::characters(string name,string game):name(name),game(game){

}

string characters::toString(){
    stringstream ss;
    ss << " - - - - " << game <<" - - - -\n"<< "Name: "<<name<<"\n";
    return ss.str();

}
string characters::getName(){
    return name;
}
void characters::setName(string name){
    this->name=name;
}

string characters::getGame(){
    return game;
}
