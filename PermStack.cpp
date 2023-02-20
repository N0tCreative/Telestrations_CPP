#include "PermStack.h"
#include "Filter.h"
#include <vector>

/* this stack is used to store the permutations that will be tested
 * 
 */
PermStack::PermStack(int NumberOfPlayers){
    InvalidBookFilter.SetNumberOfPlayers(NumberOfPlayers);
    Permutations = std::vector<std::vector<char>*>();
    RoundLocationInStack = std::vector<long>(NumberOfPlayers,0);
}

//Generates first round of permutations
void PermStack::GenerateFirstPermutations(){
}

//pushes new permutations onto the stack if valid
void PermStack::Push(std::vector<char>*NewPermuatation){
    Permutations.push_back(NewPermuatation);
};

/* main function used to get a sending order for the books that has each person with a unique book each round
 * no person gets the same book twice, no person sends to the same person twice
 */
std::vector<std::vector<char>> PermStack::GetValidOrder(){
    std::vector<std::vector<char>> empty;
    return empty;
};