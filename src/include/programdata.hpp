#ifndef programdata_hpp
#define programdata_hpp
#include <string>
#include <list>
using namespace std;


struct ProgramData {
    string expression;
    int ERR_Flag;
    list<list<char>> vars;
    string output;
};





#endif