#ifndef programdata_hpp
#define programdata_hpp
#include <string>
#include <list>
using namespace std;


struct ProgramData {
    string expression;
    string original_expr;
    int ERR_Flag;
    list<list<char>> vars;
    string output;
};





#endif