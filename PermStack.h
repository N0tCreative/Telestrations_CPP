
#ifndef PERM_STACK_CLASS
#define PERM_STACK_CLASS
#include <vector>
#include "Filter.h"
class PermStack{
    private:
        int NumberOfPlayers;
        std::vector<long> RoundLocationInStack;
        std::vector<std::vector<char>*> Permutations;
        Filter InvalidBookFilter;
        
    public:
        PermStack(int NumberOfPlayers);
        void Push(std::vector<char>* NewPermuatation);
        void Pop();
        bool IsEmpty();
        std::vector<char>* Peek();
        std::vector<std::vector<char>> GetValidOrder();
        void GenerateFirstPermutations();
};
#endif