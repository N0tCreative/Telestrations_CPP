#include <vector>
#include "Filter.h"
#ifndef PERM_STACK_CLASS
#define PERM_STACK_CLASS
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