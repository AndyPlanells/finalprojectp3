#include "gamecheck.h"
#include "check.h"
#include <sstream>

using std::stringstream;

gamecheck::gamecheck(string boughtitem, int nocheck,double balance):check(boughtitem,nocheck),balance(balance){

}

string gamecheck::toString()const{
    stringstream ss;
    ss << "";
    return ss.str();
}
double gamecheck::getTax(){
    if(balance==15){
        return 0.06;
    }else if(balance==20){
        return 0.07;
    }else if(balance==30){
        return 0.08;
    }else if(balance==40){
        return 0.09;
    }else if(balance==60){
        return 0.10;
    }
    return 0;
}

double gamecheck::getDiscount(int timesclicked){
    if(timesclicked<2){
        return 0;
    }else{
        return 0.2;
    }
    return 0;
}
