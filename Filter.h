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
        void Block(const std::vector<char> NewUsedNumbers);
        void Unblock(const std::vector<char> NewUnusedNumbers);
        bool IsValid(const std::vector<char> NumbersToBeTested);
};
#endif