#include "check.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

check::check(string boughtitem, int nocheck):boughtitem(boughtitem),nocheck(nocheck){

}

string check::toString()const{
    stringstream ss;
    ss << "";
    return ss.str();
}

string check::getBoughtitem()const{
    return boughtitem;
}
void check::setBoughtitem(string boughtitem){
    this->boughtitem=boughtitem;
}

int check::getNocheck()const{
    return nocheck;
}
void check::setNocheck(int nocheck){
    this->nocheck=nocheck;
}
