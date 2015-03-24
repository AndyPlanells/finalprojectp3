#ifndef D3_H
#define D3_H

#include "games.h"
#include "characters.h"
#include "wdchar.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

class d3 : public games
{
    vector<wdchar>mychars;
    bool ros;
public:
    d3(bool=false,string="Diablo III",bool=false);
    string toString();
    bool getRos();
    void setRos(bool);
    vector<wdchar> getMychars()const;
    void setMychars(vector<wdchar>);
};

#endif // D3_H
