// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


/* Task 1: Write a function that accepts as parameters an array of characters
and a single search character. The function to return a pointer that points to
the element of the first occurrence of this one symbol in the array,
and if the symbol is not found - the pointer has a value of NULL. */

const char* SearchCharacter(const char* s, char c) {
    unsigned i = 0;
    while (s[i] != '\0') {
        if (s[i] == c)
            return &s[i];
        i++;
    }
    return NULL;
}

int main()
{
    const char* pCh = SearchCharacter("abcdefg", 'c');
    if (pCh != NULL) {
        cout << "Found character at address: " << (void*)pCh << endl;
        cout << "Character itself: " << *pCh << endl;
    }
    else {
        cout << "Character not found" << endl;
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

