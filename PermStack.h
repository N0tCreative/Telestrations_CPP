
#ifndef PERM_STACK_CLASS
#define PERM_STACK_CLASS
#include <vector>
#include "Filter.h"
class PermStack{
    private:
        std::vector<long> RoundLocationInStack;
        std::vector<std::vector<char>*> Permutations;
        Filter InvalidBookFilter;
    public:
        PermStack(int NumberOfPlayers);
        void Push(std::vector<char>* NewPermuatation);
        std::vector<std::vector<char>> GetValidOrder();
        void GenerateFirstPermutations();
};
#endif