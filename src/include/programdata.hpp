#ifndef programdata_hpp
#define programdata_hpp
#include <string>
#include <list>
using namespace std;


struct ProgramData {
    string expression;
    int ERR_Falg;
    list<list<char>> vars;
    string output;
};





#endif