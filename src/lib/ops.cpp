#include "ops.hpp"

char andC(char a, char b) {
    bool aBool = a == 'T';
    bool bBool = b == 'T';

    return (aBool && bBool) ? 'T' : 'F';
}
char orC(char a, char b) {
    bool aBool = a == 'T';
    bool bBool = b == 'T';
    
    return (aBool || bBool) ? 'T' : 'F';
}

char notC(char a) {
    bool aBool = a == 'T';

    return (!aBool) ? 'T' : 'F';
}

char xorC(char a, char b) {
    bool aBool = a == 'T';
    bool bBool = b == 'T';

    return (aBool != bBool) ? 'T' : 'F';
}

char nandC(char a, char b) {
    char andResult = andC(a, b);
    
    return (andResult == 'T') ? 'F' : 'T';
}
