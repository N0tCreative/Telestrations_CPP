#include "PermStack.h"
#include "Filter.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

/* this stack is used to store the permutations that will be tested
 * 
 */
PermStack::PermStack(int NumOfPlayers){
    NumberOfPlayers= NumOfPlayers;
    InvalidBookFilter.SetNumberOfPlayers(NumberOfPlayers);
    Permutations = new std::vector<std::vector<char>*>();
    RoundLocationInStack = std::vector<long>(NumberOfPlayers-1);
    RoundsCurrentlyBeingTested = std::vector<std::vector<char>>(NumberOfPlayers-1, std::vector<char>(NumberOfPlayers-1));
}

//destructor
PermStack::~PermStack(){
    ClearStack();
}

//swaps two elements
inline void Swap(char* ele1Ptr, char* ele2Ptr){
    char temp = *ele1Ptr;
    *ele1Ptr= *ele2Ptr;
    *ele2Ptr=temp;
}

//Generates first round of permutations
void PermStack::GenerateFirstPermutations(){
    auto rng = std::default_random_engine{};
    //non recursive heap's algorithm based on implimentation by Sedgewick, Robert in "a talk on Permutation Generation Algorithms" 
    //link: https://sedgewick.io/wp-content/uploads/2022/03/2002PermGeneration.pdf
    std::vector<char> StackState =std::vector<char>(NumberOfPlayers);
    std::vector<char> PeopleWithBook;
    for(int i=0; i<NumberOfPlayers; i++){
        PeopleWithBook.push_back(i+1);
    }

    int StackPtr=1;
    while (StackPtr<NumberOfPlayers){
        if(StackState[StackPtr] < StackPtr){
            if(!(StackPtr%2)){
                Swap(&PeopleWithBook[0], &PeopleWithBook[StackPtr]);
            } else{
                Swap(&PeopleWithBook[StackState[StackPtr]], &PeopleWithBook[StackPtr]);
            }
            StackState[StackPtr]++; //swap complete so simulate incriment the for loop counter
            StackPtr =1; //simulate recursive call reaching the base case by bringing pointer to base case analog
            //if this permutation works then add it to the stack
            if(InvalidBookFilter.IsValid(PeopleWithBook)){
                std::vector<char>* permutation = new std::vector<char>(PeopleWithBook);
                Permutations->push_back(permutation);
            }
        } else{
            //calling generate(i+1, PeopleWithBook) has ended as the for loop terminated. reset the state and simulate popping the stack by incrimenting pointer
            StackState[StackPtr]=0;
            StackPtr++;
        }
    }

    //the algorithm tends to find the solution (if one exists) faster if the list of possible permutations is randomized
    std::shuffle(Permutations->begin(), Permutations->end(), rng);

    //set the second round pointer
    RoundLocationInStack[0] = Permutations->size();
}

//pushes new permutations onto the stack if valid
void PermStack::Push(std::vector<char>*NewPermuatation){
    Permutations->push_back(NewPermuatation);
};

//returns the last permutation
std::vector<char>* PermStack::Peek(){
    return Permutations->back();
    
};

//frees the permutation that is at the end of the stack and removes it
void PermStack::Pop(){
    if(!IsEmpty()){
        delete(Permutations->back());
        Permutations->erase(Permutations->end() -1);
    }
};

//tests if stack is empty
bool PermStack::IsEmpty(){
    return Permutations->size() <= 0;
};

//empties the stack and deletes everything on it
void PermStack::ClearStack(){
    while(! IsEmpty()){
        Pop();
    }
    delete Permutations;
}

/* main function used to get a sending order for the books that has each person with a unique book each round
 * no person gets the same book twice, no person sends to the same person twice
 */
std::vector<std::vector<char>> PermStack::GetValidOrder(){
    std::vector<std::vector<char>> empty;
    return empty;
};