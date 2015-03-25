#include "player.h"
#include <string>
#include <sstream>
#include "games.h"
#include "wow.h"
#include "hs.h"
#include "d3.h"
#include "sc2.h"
#include <vector>

using std::string;
using std::stringstream;

player::player(string name,string lastname,string username,string password,string email,int VisaCard,int VisaCode,double balance,wow mywow,d3 myd3,sc2 mysc2, Hs myhs,int timesgames, int timesbalance)
    :name(name),lastname(lastname),username(username),password(password),email(email),VisaCard(VisaCard),VisaCode(VisaCode),balance(balance),mywow(mywow),myd3(myd3),mysc2(mysc2),myhs(myhs),timesgames(timesgames),timesbalance(timesbalance){
}

string player::toString()const{
    stringstream ss;
    ss << "Name: " << name + " " + lastname << "\nUsername: " << username << "\nPassword: " << password <<
          "\n Email: "<< email << "\n Visa Card No. :" << VisaCard <<"\n Visa Code: " << VisaCode <<"\n";
    return ss.str();
}
string player::getName()const{
    return name;

}
void player::setName(string name){
    this->name=name;

}

string player::getLastname()const{
    return lastname;

}
void player::setLastname(string lastname){
    this->lastname=lastname;
}

string player::getUsername()const{
    return username;
}
void player::setUsername(string username){
    this->username=username;
}

string player::getPassword()const{
    return password;
}
void player::setPassword(string password){
    this->password=password;
}

string player::getEmail()const{
    return email;
}
void player::setEmail(string email){
    this->email=email;
}

int player::getVisaCard()const{
    return VisaCard;
}
void player::setVisaCard(int VisaCard){
    this->VisaCard=VisaCard;
}

int player::getVisaCode()const{
    return VisaCode;
}
void player::setVisaCode(int VisaCode){
    this->VisaCode=VisaCode;
}


double player::getBalance()const{
    return balance;
}
void player::setBalance(double balance){
    this->balance=balance;
}
wow player::getMyWoW()const{
    return mywow;
}
void player::setMyWoW(wow mywow){
    this->mywow=mywow;
}

d3 player::getMyd3()const{
    return myd3;
}
void player::setMyd3(d3 myd3){
    this->myd3=myd3;
}

sc2 player::getMySc2()const{
    return mysc2;
}
void player::setMySc2(sc2 mysc2){
    this->mysc2=mysc2;
}

Hs player::getMyHs()const{
    return myhs;
}
void player::setMyHs(Hs myhs){
    this->myhs=myhs;
}

vector<wdchar> player::getMywowchars()const{
    return mywowchars;
}
vector<wdchar> player::getMyd3chars()const{
    return myd3chars;
}
vector<shochar> player::getMySc2chars()const{
    return mysc2chars;
}
vector<hschar> player::getMyhschars()const{
    return myhschars;
}
void player::setwowchar(wdchar w){
    this->mywowchars.push_back(w);
}

void player::setd3char(wdchar d){
    this->myd3chars.push_back(d);
}

void player::setsc2char(shochar s){
    this->mysc2chars.push_back(s);
}

void player::sethschar(hschar h){
    this->myhschars.push_back(h);
}

vector<balancecheck> player::getMybcheck()const{
    return mybchecks;
}
vector<gamecheck> player::getMygcheck()const{
    return mygchecks;
}
void player::setbcheck(balancecheck bc){
    this->mybchecks.push_back(bc);
}

void player::setgcheck(gamecheck gc){
    this->mygchecks.push_back(gc);
}


int player::getTimesgames()const{
    return timesgames;
}
int player::getTimesbalance()const{
    return timesbalance;
}

void player::setTimesgames(int timesgames){
    this->timesgames=timesgames;
}

void player::setTimesbalance (int timesbalance){
    this->timesbalance = timesbalance;
}

int player::getMychecks()const{
    return mychecks;
}
void player::setMychecks(int mychecks){
    this->mychecks=mychecks;
}
