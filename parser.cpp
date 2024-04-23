/*parser
#include <string>
#include <iostream>
#include <list>
using namespace std;
*/

void emptyCheck(ProgramData& data, int b){
    if (b == 0){
        data.ERR_Flag = 4;
    }
}

void parenthesesCheck(ProgramData& data, int b){
    int left = 0;
    int right = 0;
    for (int i = 0; i < b; i++){
        if (data.expression[i] == '('){
                left++;
            }
        if (data.expression[i] == ')'){
            right++;
        }
    }
    if (left > right){
        data.ERR_Flag = 31;
    }
    if (right > left){
        data.ERR_Flag = 32;
    }
}

void opCheck(ProgramData& data, int b){
    for (int i = 0; i < b; i++){
        char op1 = data.expression[i];
        char op2 = data.expression[i+1];
        //cout << op1 << "," << op2 << endl;
        if (op1 != '&' && op1 != '|' && op1 != '!' && op1 != '@' && op1 != '$' && op1 != 'T' && op1 != 'F' && op1 != '(' && op1 != ')'){
            data.ERR_Flag = 2;
            return;
        }
        if (op1 == '!' && (op2 != 'T' && op2 != 'F')){
            data.ERR_Flag = 11;
            return;
        }
        if (op2 == '!' && (op1 == 'T' || op1 == 'F')){
            data.ERR_Flag = 12;
            return;
        }
        if (op1 == op2){
            data.ERR_Flag = 5;
            return;
        }
    }
}

void errorCheck(ProgramData& data){
    int bound = data.expression.length();
    emptyCheck(data, bound);
    if (data.ERR_Flag != 0){
            return;
    }
    //cout << "Passed flag check" << endl;
    parenthesesCheck(data, bound);
    if (data.ERR_Flag != 0){
            return;
    }
    //cout << "Passed flag check" << endl;
    opCheck(data, bound);
    if (data.ERR_Flag != 0){
            return;
    }
    //cout << "Passed flag check" << endl;
}

void addVariables(ProgramData& data){
    char tempvars[data.vars.size()];
    int it = 0;
    for (auto i : data.vars){
        tempvars[it] = i;
        it++;
    }
    for (int s = 0; s < data.expression.length(); s++){
        char op = data.expression[s];
        if (op != '&' && op != '|' && op != '!' && op != '@' && op != '$' && op != 'T' && op != 'F' && op != '(' && op != ')'){
            for (int i = 0; i < data.vars.size(); i++){
                if (op == tempvars[i]){
                    data.expression[s] = tempvars[i+1];
                }
            }
        }
    }
}

void remove(ProgramData& data, int s){
    for (;s < data.expression.length(); s++){
        data.expression[s] = data.expression[s+1];
    }
}

void strip(ProgramData& data){
    int counter = 0;
    for (int i = 0; i < data.expression.length(); i++){
        if (data.expression[i] == ' '){
            remove(data, i);
            i--;
            counter++;
        }
    }
    int target = data.expression.length()-counter;
    for (int i = 1; i < counter; i++){
        data.expression.erase(target);
    }
}

void parser(ProgramData& data) {
    cout << "parser ran" << endl;
    data.ERR_Flag = 0;
    data.original_expr = data.expression;
    strip(data);
    addVariables(data);
    errorCheck(data);
    if (data.ERR_Flag != 0){
        return;
    }
}