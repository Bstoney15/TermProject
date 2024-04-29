#include "output.hpp"
#include <iostream>


void output(ProgramData& data) {
    if(data.ERR_Flag != 0)
    {
        int errorType = data.ERR_Flag / 10;
        int errorNum = data.ERR_Flag % 10;
        switch (errorType)
        {
            case 1:
                data.output = "Error: Operator misuse \n";
                switch(errorNum)
                {
                case 1:
                    data.output += "Error 11: Operator '!' cannot be used with another operator\n";
                    break;
                case 2:
                    data.output += "Error 12: Operator '&' cannot be used with another operator\n";
                    break;
                case 3:
                    data.output += "Error 13: Operator '@' cannot be used with another operator\n";
                    break;
                case 4:
                    data.output += "Error 14: Operator '|' cannot be used with another operator\n";
                    break;
                case 5:
                    data.output += "Error 15: Operator '$' cannot be used with another operator\n";
                    break;
                case 6:
                    data.output += "Error 16: Operator is the first or last character\n";
                    break;
                default:
                    data.output += "Error 10: Unknown operator error\n";
                    break;
                }
                break;
            case 2:
                data.output = "Error: variable error \n";
                switch (errorNum)
                {
                case 1:
                    data.output += "Error 21: Variable is not defined\n";
                    break;
                
                default:
                    data.output += "Error 20: Unknown variable error\n";
                    break;
                }
                break;
            case 3:
                data.output = "Error: Data Error \n";
                switch (errorNum)
                {
                case 1:
                    data.output += "Error 31: Back to Back Boolean values\n";
                    break;
                default:
                    data.output += "Error 30: Unknown Data error\n";
                    break;
                }
                break; 
            case 4:
                data.output = "Error: Parentheses Error \n";
                switch (errorNum)
                {
                case 1:
                    data.output += "Error 41: Parentheses closed before it was opened\n";
                    break;
                case 2:
                    data.output += "Error 42: Parentheses was never closed\n";
                    break;
                default:
                    data.output += "Error 40: Unknown Parentheses error\n";
                    break;
                }
                break;       
        }
    }


    else
    {
        data.output = "Expression = " + data.original_expr + "\n" + "Result = " + data.expression + "\n";
    }
    

}