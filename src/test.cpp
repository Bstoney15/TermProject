#include "ops.hpp"
#include <iostream>
using namespace std;


int main(){
    cout << nandC('T', 'T') << endl;
    cout << nandC('T', 'F') << endl;
    cout << nandC('F', 'T') << endl;
    cout << nandC('F', 'F') << endl;
}