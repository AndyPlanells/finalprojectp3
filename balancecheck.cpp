#include "balancecheck.h"
#include "check.h"
#include <sstream>
#include <string>

using std::string;

using std::stringstream;

balancecheck::balancecheck(string boughtitem, int nocheck, double money):check(boughtitem, nocheck),money(money){

}

string balancecheck::toString()const{
    stringstream ss;
    ss << "";
    return ss.str();
}
double balancecheck::getTax(){
    if(money<=100){
        return 0.15;
    }else if(money>100 && money <=200){
        return 0.18;
    }else{
        return 0.2;
    }
}

double balancecheck::getDiscount(int timesclicked){
    if(timesclicked<=3){
        return 0;
    }else{
        return 0.15;
    }
}

double balancecheck::getMoney()const{
    return money;
}
