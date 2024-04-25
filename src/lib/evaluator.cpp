#include "evaluator.hpp"
#include <iostream>


void evaluator(ProgramData& data) {
    //std::cout << "eval ran: " << data.expression << endl;
    int firstParenthesis;
    int lastParenthesis;
    ProgramData tmp;

    

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
        cout << data.expression << endl;
    };

    cout << data.expression << endl;
    data.expression.erase();
    data.expression.append("x");
    
}