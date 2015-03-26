#include "shochar.h"
#include "characters.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

shochar::shochar(string name,string game,string story)
    :characters(name,game),story(story){

}

string shochar::toString(){
    stringstream ss;
    ss << characters::toString() << "Story:\n" << story;
    return ss.str();
}

string shochar::getStory()const{
    return story;
}
void shochar::setStory(string story){
    this->story=story;
}
