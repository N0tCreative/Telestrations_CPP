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

void PermStack::GenerateFirstPermutations(){

}

void PermStack::Push(std::vector<char>*NewPermuatation){
    Permutations.push_back(NewPermuatation);
};
std::vector<std::vector<char>> PermStack::GetValidOrder(){
    std::vector<std::vector<char>> empty;
    return empty;
    };