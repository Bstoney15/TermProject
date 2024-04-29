#ifndef programdata_hpp
#define programdata_hpp
#include <string>
#include <vector>
using namespace std;


struct ProgramData {
    string expression;
    string original_expr;
    int ERR_Flag;
    vector<vector<char>> vars;
    string output;
};





#endif