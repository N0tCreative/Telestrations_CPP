#include <iostream>
#include "PermStack.h"
#include <vector>
#include "main.h"


/*  Main CPP telestrations organizer
 *   reads # of players from stdin
 *   outputs visual representation of who each person should send their book to
 */
int main(){
    int PlayerNumber = GetNumPlayers();
    std::vector<std::vector<char>> AllPermutations= GeneratePerms(PlayerNumber);

    PermStack Stack = PermStack(PlayerNumber);
    
    for(std::vector<char> & Round : AllPermutations){
        Stack.Push(&Round);
    }
    std::vector<std::vector<char>> result = Stack.GetValidOrder();
    DisplayResults(AllPermutations);

}

//prompts user to input the number of players
int GetNumPlayers(){return 1;}
//generates all valid first permutations for the given number of players
std::vector<std::vector<char>> GeneratePerms(int numPlayers){return std::vector<std::vector<char>>(0);}
//displays the resulting order
void DisplayResults(std::vector<std::vector<char>> results){std::cout<<"no results";}