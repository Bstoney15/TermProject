#include "programdata.hpp"
#include "parser.hpp"
#include "evaluator.hpp"
#include "output.hpp"
#include "ui.hpp"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}

void printMenu(const ProgramData data) {
    clearScreen();
    cout << " - Boolean Expression Evaluator Menu - \n";
    cout << "enter a letter to select an option\n" << endl;

    if(!data.original_expr.empty())
    {
        cout << "Current Expression: " << data.original_expr << endl << endl; 
    }

    cout << "N. New Expression\n";
    cout << "E. Evaluate Expression \n";
    cout << "D. Define a variable\n";
    cout << "S. Show current variables\n";
    cout << "R. Remove an existing variable\n\n";

    cout << "Enter anything else to exit\n";
    cout << " - Enter selection letter: \n";
}

int newExpression(ProgramData& data) {
    clearScreen();
    
    

    string input_expr;
    string tmp;
    char doEvaluate;

    cout << "Enter a new expression: ";
    getline(cin, input_expr);
    data.expression = input_expr;
    data.original_expr  = input_expr;
    
    cout << "Evaluate the expression? (Y/N): ";
    doEvaluate = toupper(cin.get());
    cin.ignore(1000, '\n');
    

    return (int)(doEvaluate == 'Y');
}

void showVariables(const ProgramData data)
{
    string tmp;
    clearScreen();
    cout << "Current Variables: \n\n";

    for(int i = 0; i < data.vars.size(); i++)
    {
        cout << data.vars[i][0] << " = " << data.vars[i][1] << endl;
    }

    cout << "\npress any key to continue..." << endl;

    cin.ignore(1000, '\n');
    
    return;

}

void deleteVariable(ProgramData& data) {
    clearScreen();


    cout << "current Variables: \n\n";

    for(int i = 0; i < data.vars.size(); i++)
    {
        cout << data.vars[i][0] << " = " << data.vars[i][1] << endl;
    }

    cout <<  "\n";

    char variable;
    cout << "Enter the variable character: \n";
    variable = cin.get();
    cin.ignore(1000, '\n');
    

    for(int i = 0; i < data.vars.size(); i++)
    {
        if(data.vars[i][0] == variable)
        {
            data.vars.erase(data.vars.begin() + i);
            cout << "Variable deleted\n";
            cout << "Press any key to continue...";
            cin.ignore(1000, '\n');
            
            return;
        }
    }

    cout << "Variable not found\n";
    cout << "Press any key to continue...";

    cin.ignore(1000, '\n');

    

}

void makeVariable(ProgramData& data) {
    clearScreen();


    char variable;
    char value;

    cout << "Enter the variable character: \n";
    variable = cin.get();
    cin.ignore(1000, '\n');

    

    cout << "Enter the variable value: \n";
    value = cin.get();
    cin.ignore(1000, '\n');

    
    

    data.vars.push_back({variable, value});
    
}

void ui(ProgramData& data) {
    string input_expr;
    char selection;
    string variable;
    string value;
    int doesR;

        
    if(!data.output.empty()){
        clearScreen();

        cout << data.output << endl;
        cout << "Press any key to continue...";


        cin.ignore(1000, '\n');
        
        

        data.output = "";
        data.ERR_Flag = 0;
    }
    
    do {

        printMenu(data);
        selection = toupper(cin.get());
        if(selection != '\n') cin.ignore(1000, '\n');
        
        
    

        // Define program behavior for selection cases
        switch (selection) {

            // Selection for entering a new expression
            case('N'):
                doesR =  newExpression(data);
                if(doesR == 1)
                {
                    return;
                }else
                {
                    clearScreen();
                }
            break;
            // Selection for using the last expression
            case('E'):
                if(data.expression.empty())
                {
                    clearScreen();
                    cout << "No expression to evaluate\n";
                    cout << "Press any key to continue...";
                    cin.ignore(1000, '\n');
                    break;
                }
                else{
                    return;
                }
            // Selection for defining a new variable
            case ('D'): 
                makeVariable(data);
                break;

            // Selection for current variables request
            case ('S'): 
                showVariables(data);
                break;

            // Selection for deleting a variable
            case ('R'):
                deleteVariable(data);
                break;

            // Behavior for invalid menu selections
            default:
                selection = '\n';
                data.expression = "exit";
                cout << "Exiting program...\n";
                break;
        }

    } while (selection != '\n'); // Assuming 4 is the exit option

    return;
}