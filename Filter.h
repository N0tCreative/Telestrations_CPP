#ifndef FILTER_CLASS
#define FILTER_CLASS
#include <vector>
class Filter{
    private:
        std::vector<long> UsedNumbers;
        int NumberOfPlayers;
    public:
        Filter();
        Filter(int NumbOfPlayers);
        void SetNumberOfPlayers(int NumOfPlayers);
        void Block(std::vector<char> NewUsedNumbers);
        void Unblock(std::vector<char> NewUnusedNumbers);
        bool IsValid(std::vector<char> NumbersToBeTested);
};
#endif