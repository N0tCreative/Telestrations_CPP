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
    RoundsCurrentlyBeingTested = std::vector<std::vector<char>>(NumberOfPlayers-1, std::vector<char>(NumberOfPlayers));
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
    RoundLocationInStack[0] = Permutations->size() -1;
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
        //only delete if this is the last instance of the permutation so that deeper rounds can use a pointer to the same permutation
        if(Permutations->size() == RoundLocationInStack[0])
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

//pushes all valid permutations given the current deepest round
bool PermStack::PushValidPermutations(long Round){
    bool PushedSomething = false;
    //this logic means that permutations already excluded due to younger rounds are automatically excluded with this new branch
    int i;
    if(Round <1) i=0;//start at beginning
    else i =RoundLocationInStack[Round -1];//start at 2nd youngest round

    //check if every value between youngest and 2nd youngest are valid
    for(; i<=RoundLocationInStack[Round]; i++){
        std::vector<char> *perm = (Permutations->at(i));
        if(InvalidBookFilter.IsValid(*perm)){
            PushedSomething =true;
            Permutations->push_back(perm);
        }
    }
    if(PushedSomething){
        RoundLocationInStack[Round+1] = Permutations->size() -1;
    }

    return PushedSomething;
}

//sets the current round being tested
bool PermStack::SetRound(long Round){
    bool PermutationsAdded;
    RoundsCurrentlyBeingTested[Round] = *(Permutations->back());
    Pop();
    RoundLocationInStack[Round] -=1;
    InvalidBookFilter.Block(RoundsCurrentlyBeingTested[Round]);
    PermutationsAdded =PushValidPermutations(Round);
    //if the current selected permutation doesnt add any new permutations then it will be unblocked and removed
    if(!PermutationsAdded){
        InvalidBookFilter.Unblock(RoundsCurrentlyBeingTested[Round]);
        std::fill(RoundsCurrentlyBeingTested[Round].begin(), RoundsCurrentlyBeingTested[Round].end(),0);//once the algorithm is confirmed to work this should be removed
    }
    return PermutationsAdded;

}

//checks if current round order has each person send to another only once
bool PermStack::isOptimal(){
    return false;
}

/* main function used to get a sending order for the books that has each person with a unique book each round
 * no person gets the same book twice, no person sends to the same person twice
 * TODO: finish this, logic is almost complete but needs a bit more thought and work
 */
std::vector<std::vector<char>> PermStack::GetValidOrder(){
    bool isValid = false;
    long DeepestRound =0;
    while(!isValid && !IsEmpty()){
        if(SetRound(DeepestRound)){
            DeepestRound++;
        }else{
            //if the deepest round has been fully exausted then set it to 0 and go up one level to the 2nd deepest
            if(DeepestRound >0 && RoundLocationInStack[DeepestRound-1] >=RoundLocationInStack[DeepestRound]){
                InvalidBookFilter.Unblock(RoundsCurrentlyBeingTested[DeepestRound -1]);
                RoundLocationInStack[DeepestRound] =0;
                DeepestRound--;
            }
        }
        //temp check to see if it reaches deepest level
        if(DeepestRound == NumberOfPlayers -2){
            RoundsCurrentlyBeingTested[DeepestRound] = *(Permutations->back());
            Pop();
            RoundLocationInStack[DeepestRound] -=1;

            isValid=isOptimal();

            if(!isValid){
                RoundsCurrentlyBeingTested[DeepestRound]= {0};
                InvalidBookFilter.Unblock(RoundsCurrentlyBeingTested[DeepestRound -1]);
                RoundLocationInStack[DeepestRound] =0;
                DeepestRound--;

            }
        }

    }

    
    return RoundsCurrentlyBeingTested;
};