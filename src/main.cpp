#include "programdata.hpp"
#include "ui.hpp"
#include "parser.hpp"
#include "evaluator.hpp"
#include "output.hpp"
#include <iostream>
using namespace std;



int main(){
    ProgramData e;
    ui(e);
    parser(e);
    evaluator(e);
    output(e);
}

