#include "ops.hpp"
#include <iostream>
#include "programdata.hpp"
#include "evaluator.hpp"
#include "parser.hpp"
using namespace std;

void evaltest(){
    ProgramData e;

    e.expression = "F|((T&F)|F)";
    evaluator(e);
    cout << "output 1: " << e.expression << endl;

        // Test case 1
    e.expression = "F|(T&F)";
    evaluator(e);
    std::cout << "output 2: " << e.expression << std::endl;

    // Test case 2
    e.expression = "!(T@F)&T";
    evaluator(e);
    std::cout << "output 3: " << e.expression << std::endl;

    // Test case 3
    e.expression = "T$F";
    evaluator(e);
    std::cout << "output 4: " << e.expression << std::endl;

    // Test case 4
    e.expression = "T|(!F&T)";
    evaluator(e);
    std::cout << "output 5: " << e.expression << std::endl;

    // Test case 5
    e.expression = "((T@F)@T)|F";
    evaluator(e);
    std::cout << "output 6: " << e.expression << std::endl;

    // Test case 6
    e.expression = "T&F@!T";
    evaluator(e);
    std::cout << "output 7: " << e.expression << std::endl;

    // Test case 7
    e.expression = "!T$T";
    evaluator(e);
    std::cout << "output 8: " << e.expression << std::endl;

    // Test case 8
    e.expression = "!!(T|F)&(T@F)";
    evaluator(e);
    std::cout << "output 9: " << e.expression << std::endl;

    // Test case 9
    e.expression = "F@(T$F)&T";
    evaluator(e);
    std::cout << "output 10: " << e.expression << std::endl;

    // Test case 10
    e.expression = "T&(F@(!T|F))";
    evaluator(e);
    std::cout << "output 11: " << e.expression << std::endl;
}

void parsetest()
{
    ProgramData e;
    e.expression = "(((((T|F)&F)|(T&(T|F)))@(T@T))$(!(T|F)))";
    parser(e);
    cout << "errors:" << e.ERR_Flag << endl;
    cout << "output: " << e.expression << endl;

}

int main(){
    parsetest();
}