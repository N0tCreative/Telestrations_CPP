#include "Filter.h"
#include <vector>


Filter::Filter(){
    NumberOfPlayers = 0;
}
Filter::Filter(int NumOfPlayers){
    Filter::SetNumberOfPlayers(NumOfPlayers);
}

/* since default initialization is used this function is used to set the number of players and
 * set up the vector that is used to track what numbers should and should not be blocked
 */
void Filter::SetNumberOfPlayers(int NumOfPlayers){
    NumberOfPlayers = NumOfPlayers;
    UsedNumbers = std::vector<long>(NumOfPlayers, 0);
    //set default filter(book 1 starts at position 0, book 2 at position 1 etc)
    for(int i=0; i < UsedNumbers.size(); i++){
        /* blocked numbers are stored in bits as part of a long since permutations grow so exponentially its unlikely
         * that you will ever find a computer powerful enough to compute all permutations of a group of 32 people
         * !32 ~= 2.631084*e^35 for reference the number of grains of sand on earth is 7.5*e^18
         * also storing in bits lets me filter in O(n) time instead of O(n^2)
         */
        UsedNumbers[i] = 1<<(i); 
    }
}

//adds new list of new numbers to be blocked for that position
void Filter::Block(const std::vector<char> NewUsedNumbers){
    for(int i=0; i< UsedNumbers.size(); i++){
        UsedNumbers[i] = UsedNumbers[i] | 1<<(NewUsedNumbers[i] -1);
    }
}

//removes block for that number
void Filter::Unblock(const std::vector<char> NewUnusedNumbers){
    for(int i=0; i< UsedNumbers.size(); i++){
        UsedNumbers[i] = UsedNumbers[i] & ~(1<<(NewUnusedNumbers[i] -1));
    }
}

//checks if the vector to be tested is valid
bool Filter::IsValid(const std::vector<char> NumbersToBeTested){
    bool valid =true;
    //check if each number passes the filter
    for(int i=0; i< UsedNumbers.size(); i++){
        long NumberToTest = (1<<(NumbersToBeTested[i]-1));
        //if UsedNumbers[i] contains the NumberToBeTested[i]
        if(UsedNumbers[i] & NumberToTest){
            valid = false;
            return valid;
        }
    }
    return valid;
}