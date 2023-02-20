#include <vector>
#ifndef MAIN_FUNCTS
#define MAIN_FUNCTS
int main();
int GetNumPlayers();
std::vector<std::vector<char>> GeneratePerms(int numPlayers);
void DisplayResults(std::vector<std::vector<char>> results);
void FilterTestResults(Filter filt, std::vector<int> val, bool expected);
void PrintVec(std::vector<int> val);
#endif