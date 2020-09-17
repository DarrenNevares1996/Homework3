#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>

void ReverseArray(int arr[], int length);
bool HasBalancedParentheses(std::string);
bool DogishHelper(std::string word, char letter, char endLetter);
bool InDogish(std::string);
bool isFound(bool found[], int length);
bool InXish(std::string myText, std::string myWord);
#endif