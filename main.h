#include <vector>
#ifndef MAIN_FUNCTS
#define MAIN_FUNCTS
int main();
int GetNumPlayers();
std::vector<std::vector<char>> GeneratePerms(int numPlayers);
void DisplayResults(std::vector<std::vector<char>> results);
#endif