#include "Filter.h"
#include <vector>


Filter::Filter(){
    NumberOfPlayers = 0;
}
void Filter::SetNumberOfPlayers(int NumOfPlayers){
    NumberOfPlayers = NumOfPlayers;
    UsedNumbers = std::vector<long>(0,NumOfPlayers);
    //set default filter(book 1 starts at position 0, book 2 at position 1 etc)
    for(int i=0; i < UsedNumbers.size(); i++){
        UsedNumbers[i] = 1<<(i); 
    }
}
void Filter::Block(std::vector<int> NewUsedNumbers){
    for(int i=0; i< UsedNumbers.size(); i++){
        UsedNumbers[i] = UsedNumbers[i] | 1<<(NewUsedNumbers[i] -1);
    }
}
void Filter::Unblock(std::vector<int> NewUnusedNumbers){
    for(int i=0; i< UsedNumbers.size(); i++){
        UsedNumbers[i] = UsedNumbers[i] & ~(1<<(NewUnusedNumbers[i] -1));
    }
}
bool Filter::IsValid(std::vector<int> NumbersToBeTested){
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