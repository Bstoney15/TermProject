#include "parser.hpp"
#include <iostream>

void emptyCheck(ProgramData& data, int b){
    if (b == 0){
        data.ERR_Flag = 4;
    }
}

void parenthesesCheck(ProgramData& data, int b){
    int openParenthesis = 0;
    for(int i = 0; i < b; i++){
        if(data.expression[i] == '(')
        {
            openParenthesis++;
        }
        if(data.expression[i] == ')')
        { 
            openParenthesis--;
        }
        if(openParenthesis < 0)
        {
            data.ERR_Flag = 41;
            return;
        }
    }
    if (openParenthesis != 0){
        data.ERR_Flag = 42;
        return;
    }
}

void opCheck(ProgramData& data, int b){
    string ops = "&@|$";
    string ps = "()";

    cout << "b: " << b << endl;

    if(ops.find(data.expression[0]) != string::npos || ops.find(data.expression[b-1]) != string::npos)
    {
        data.ERR_Flag = 16;
    }


    if(data.expression.size() > 2)
    {
        for (int i = 1; i < b-1; i++){
            switch (data.expression[i])
            {
                case('!'):
                    if(data.expression[i+1] != '!' || data.expression[i+1] != 'T' || data.expression[i+1] != 'F')
                    {
                        data.ERR_Flag = 11;
                        return;
                    }
                    break;
                case('&'):
                    if(ops.find(data.expression[i+1]) != string::npos || ops.find(data.expression[i-1]) != string::npos || data.expression[i-1] == '(' || data.expression[i+1] == ')')
                    {
                        data.ERR_Flag = 12;
                        return;
                    }
                    break;
                case('@'):
                    if(ops.find(data.expression[i+1]) != string::npos || ops.find(data.expression[i-1]) != string::npos || data.expression[i-1] == '(' || data.expression[i+1] == ')')
                    {
                        data.ERR_Flag = 13;
                        return;
                    }
                    break;
                case('|'):
                    if(ops.find(data.expression[i+1]) != string::npos || ops.find(data.expression[i-1]) != string::npos || data.expression[i-1] == '(' || data.expression[i+1] == ')')
                    {
                        data.ERR_Flag = 14;
                        return;
                    }
                    break;
                case('$'):
                    if(ops.find(data.expression[i+1]) != string::npos || ops.find(data.expression[i-1]) != string::npos || data.expression[i-1] == '(' || data.expression[i+1] == ')')
                    {
                        data.ERR_Flag = 15;
                        return;
                    }
                    break;
                case('F'):
                    if(data.expression[i+1] == 'T' || data.expression[i+1] == 'F')
                    {
                        data.ERR_Flag = 31;
                        return;
                    }
                    break;
                case('T'):
                    if(data.expression[i+1] == 'T' || data.expression[i+1] == 'F')
                    {
                        data.ERR_Flag = 31;
                        return;
                    }
                    break;
                default:
                    if(ps.find(data.expression[i]) == string::npos)
                    {
                        data.ERR_Flag = 21;
                        return;
                        }
                    break;
            }
        }
    }
    else if(data.expression.length() == 2)
    {
        if(data.expression[0] == '!' && (data.expression[1] != 'T' || data.expression[1] != 'F'))
        {
            data.ERR_Flag = 11;
            return;
        }
        else if(data.expression[0] == 'T' || data.expression[0] == 'F')
        {
            data.ERR_Flag = 31;
            return;
        }
    }
    else
    {
        if(data.expression[0] != 'T' && data.expression[0] != 'F')
        {
            data.ERR_Flag = 10;
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
    size_t pos = string::npos;
    for(int j = 0; j < data.vars.size(); j++)
    {  
        pos = data.expression.find(data.vars[j][0]);
        while (pos != string::npos)
        {
            data.expression[pos] = data.vars[j][1];
            pos = data.expression.find(data.vars[j][0]);
        }
        
    }
}


void strip(ProgramData& data){
    size_t pos = data.expression.find(" ");
    while (pos != string::npos){
        data.expression.erase(pos, 1);
        pos = data.expression.find(" ");
    }
}


void parser(ProgramData& data) {
    data.ERR_Flag = 0;
    strip(data);
    addVariables(data);
    errorCheck(data);
}

