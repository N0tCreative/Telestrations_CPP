#include "Filter.h"
#include <vector>


Filter::Filter(){
    NumberOfPlayers = 0;
}
void Filter::SetNumberOfPlayers(int NumOfPlayers){
    NumberOfPlayers = NumOfPlayers;
    UsedNumbers = std::vector<long>(0,NumOfPlayers);
}
void Block(std::vector<int> NewUsedNumbers){}
void Unblock(std::vector<int> NewUnusedNumbers){}
bool IsValid(std::vector<int> NumbersToBeTested){return true;}