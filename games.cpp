#include "games.h"
#include <sstream>
#include <string>

using std::string;
using std::stringstream;

games::games(bool ifbought, string name)
    :ifbought(ifbought),name(name){

}

string games::toString()const{
    stringstream ss;
    ss << ""<< name << "\n";
    return ss.str();
}

bool games::getIfbought()const{
    return ifbought;
}

void games::setIfbought(bool ifbought){
    this->ifbought=ifbought;
}

string games::getName()const{
    return name;

}

void games::setName(string name){
    this->name=name;
}


string games::ActiveMessage(bool Received){
    if(Received){
        return "Active";
    }else{
        return "Not Active";
    }
}
