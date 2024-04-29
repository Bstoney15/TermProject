#include "evaluator.hpp"
#include "ops.hpp"
#include <iostream>


void evaluator(ProgramData& data) {
    int firstParenthesis;
    int lastParenthesis;
    ProgramData tmp;

    if(data.ERR_Flag != 0)
    {
        return;
    }

    while(data.expression.find('(') != string::npos) // while there is still parenthesis in the program
    {
        for(int i = 0; i < data.expression.size(); i++)
        {
            if(data.expression[i] == '(')
            {
                firstParenthesis = i;
                int pSets = 0; // incase there is another set of parenthesis
                for(int j = i + 1; j < data.expression.size(); j++)
                {
                    if(data.expression[j] == '(')
                    {
                        pSets++;
                    }
                    else if(data.expression[j] == ')')
                    {
                        if(pSets == 0)
                        {
                            lastParenthesis = j;
                            break;
                        }
                        else
                        {
                            pSets--;
                        }
                    }
                        
                }
                break;

            }
        }
        tmp.expression = "";
        firstParenthesis;
        string nextChar;

        for(int index = firstParenthesis + 1; index < lastParenthesis; index++) // loads tmp expression with expression insides parenthesis
        {
            nextChar = data.expression[index];
            tmp.expression.append(nextChar);
        }
        
        evaluator(tmp);

        for(int index = firstParenthesis + 1; index <= lastParenthesis; index++) // erases equation within parenthesis
        {
            data.expression.erase(firstParenthesis + 1, 1);
        }


        data.expression[firstParenthesis] = tmp.expression[0];
    };

    while(data.expression.find('!') != string::npos)
    {
        int i = data.expression.find('!');
        if(data.expression[i + 1] == '!')
        {
            data.expression.erase(i, 1);
            data.expression.erase(i, 1);
            continue;
        }
        data.expression[i] = notC(data.expression[i + 1]);
        data.expression.erase(i + 1, 1);
    }

    while(data.expression.find('&') != string::npos)
    {
        int i = data.expression.find('&');
        data.expression[i - 1] = andC(data.expression[i - 1], data.expression[i + 1]);
        data.expression.erase(i + 1, 1);
        data.expression.erase(i, 1);
    }

    while(data.expression.find('@') != string::npos)
    {
        int i = data.expression.find('@');
        data.expression[i - 1] = nandC(data.expression[i - 1], data.expression[i + 1]);
        data.expression.erase(i + 1, 1);
        data.expression.erase(i, 1);
    }

    while(data.expression.find('|') != string::npos)
    {
        int i = data.expression.find('|');
        data.expression[i - 1] = orC(data.expression[i - 1], data.expression[i + 1]);
        data.expression.erase(i + 1, 1);
        data.expression.erase(i, 1);
    }

    while(data.expression.find('$') != string::npos)
    {
        int i = data.expression.find('$');
        data.expression[i - 1] = xorC(data.expression[i - 1], data.expression[i + 1]);
        data.expression.erase(i + 1, 1);
        data.expression.erase(i, 1);
    }
    
}