/****
* PSEUDOCODE:
*    // length needs to be added because the size of an array gets lost when
     // it is passed into a function when it becomes a pointer
*    ReverseArray(arr[], length) 
*/
#include <iostream>
#include <string>
#include "hw3.h"

void ReverseArray(int arr[], int length){
    int temp;
    for (int i = 0; i < length; i++){
        if (i < length - (i + 1)){
            temp = arr[i];
            arr[i] = arr[length - (i + 1)];
            arr[length - (i + 1)] = temp;
        }
    }
}

bool HasBalancedParentheses(std::string input){
    int countOpen = 0,
        countClose = 0;

    for (int i = 0; i < input.length(); i++){
        if (input[0] == ')' || input[input.length()] == '('){
            return false;
        }
        if (input[i] == '('){
            countOpen++;
        }
        if (input[i] == ')'){
            countClose++;
        }
    }
    if (countOpen == countClose){
        return true;
    }
    else{
        return false;
    }
}

// adding 'endLetter' variable to DogishHelper to know when to stop if
// it reaches 'g' when looking for 'o', it will return false.
bool DogishHelper(std::string word, char letter, char endLetter='0')
{
    if (word == ""){
        return false;
    }
    if(endLetter == word[0] && endLetter != '0'){
        return false;
    }

    if (word[0] == letter){
        return true;
    }
    else{
        return DogishHelper(word.substr(1, word.length()), letter, endLetter);
    }
}

bool InDogish(std::string word){
    std::string dog = "dog";
    bool found[] = {false, false, false};

    for (int i = 0; i < word.length(); i++){
        // if found 'd'
        if (DogishHelper(word, 'd', 'o') && found[0] == false){
            found[0] = true;
            // if found 'o'
            if (DogishHelper(word, 'o', 'g')){
                found[1] = true;
                // if found 'g'
                if (DogishHelper(word, 'g') && found[2] == false){
                    found[2] = true;
                }
            }
        }
    }
    if (isFound(found, 3)){
        return true;
    }
    return false;
}
// searches through input, using 'x' as to a measure
bool InXish(std::string input, std::string x){
    bool foundXish[x.length()];
    for (int i = 0; i < input.length(); i++){
        if (i < x.length()){
            if (DogishHelper(input, x[i], x[i + 1]) != true){
                return false;
            }
            else{
                foundXish[i] = true;
            }
        }
    }
    if (isFound(foundXish, x.length())){
        return true;
    }
    return false;
}

bool isFound(bool found[], int length){
    bool wasFound = true;
    for (int i = 0; i < length; i++){
        if (found[i] != true){
            wasFound = false;
        }
    }
    return wasFound;
} 