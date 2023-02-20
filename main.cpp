#include <iostream>
#include "PermStack.h"
#include "Tests.h"
#include <vector>
#include "main.h"


/*  Main CPP telestrations organizer (driver for the permutation stack)
 *  reads # of players from stdin
 *  outputs visual representation of who each person should send their book to
 */
int main(){
    #ifdef FILTER_TEST
        int PlayerNumber =3;
        FilterTests(PlayerNumber);
        return 0;
    #endif
    
    int PlayerNumber = GetNumPlayers();
    std::vector<std::vector<char>> AllPermutations= GeneratePerms(PlayerNumber);

    PermStack Stack = PermStack(PlayerNumber);
    
    for(std::vector<char> & Round : AllPermutations){
        Stack.Push(&Round);
    }
    std::vector<std::vector<char>> result = Stack.GetValidOrder();
    DisplayResults(AllPermutations);

    
    return 0;
}

//prompts user to input the number of players
int GetNumPlayers(){
    int PlayerNumber =-1;
    while(PlayerNumber <1 || PlayerNumber >32){
        std::cout<<"Enter the number of people playing telestrations (1-32):";
        std::cin>> PlayerNumber;
    }
    return PlayerNumber;
}

//generates all valid first permutations for the given number of players
std::vector<std::vector<char>> GeneratePerms(int numPlayers){return std::vector<std::vector<char>>(0);}

//displays the resulting order
void DisplayResults(std::vector<std::vector<char>> results){std::cout<<"no results\n";}

