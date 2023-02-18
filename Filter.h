#include <vector>
#ifndef FILTER_CLASS
#define FILTER_CLASS
class Filter{
    private:
        std::vector<long> UsedNumbers;
        int NumberOfPlayers;
    public:
        Filter();
        void SetNumberOfPlayers(int NumberOfPlayers);
        void Block(std::vector<int> NewUsedNumbers);
        void Unblock(std::vector<int> NewUnusedNumbers);
        bool IsValid(std::vector<int> NumbersToBeTested);
};
#endif