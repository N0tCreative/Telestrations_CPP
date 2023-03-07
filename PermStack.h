
#ifndef PERM_STACK_CLASS
#define PERM_STACK_CLASS
#include <vector>
#include "Filter.h"

class PermStack{
    private:
        int NumberOfPlayers;
        std::vector<long> RoundLocationInStack;
        std::vector<std::vector<char>> RoundsCurrentlyBeingTested;
        std::vector<std::vector<char>*>* Permutations;
        Filter InvalidBookFilter;
        bool SetRound(long Round);
        bool PushValidPermutations(long Round);
        bool isOptimal();
        
    public:
        PermStack(int NumberOfPlayers);
        ~PermStack();
        void Push(std::vector<char>* NewPermuatation);
        void Pop();
        bool IsEmpty();
        std::vector<char>* Peek();
        std::vector<std::vector<char>> GetValidOrder();
        void GenerateFirstPermutations();
        void ClearStack();
};
#endif