#include "Tests.h"
#include <iostream>

/* Tests to verify that the filter is working as intended
 *
 */
void FilterTests(int PlayerNumber){
    using namespace std;
    Filter filt = Filter(PlayerNumber);

    vector<char> FilterTest1 ={1,3,2};
    cout << "************************Filter test 1: does not contain starting positions************************\n";
    FilterTestResults(filt, FilterTest1, false);

    cout << "********************************Filter test 2: allows non blocked*********************************\n";
    vector<char> FilterTest2 ={2,3,1};
    FilterTestResults(filt, FilterTest2, true);

    cout << "******************************Filter test 3: disallows after blocked******************************\n";
    vector<char> FilterTest3 ={2,3,1};
    filt.Block(FilterTest3);
    FilterTestResults(filt, FilterTest3, false);
    
    cout << "******************************Filter test 3: allows after unblocked*******************************\n";
    vector<char> FilterTest4 ={2,3,1};
    filt.Unblock(FilterTest4);
    FilterTestResults(filt, FilterTest4, true);

}

// output of results of the tests
void FilterTestResults(Filter filt, std::vector<char> val, bool expected){
    //PrintVec(val);
    if(filt.IsValid(val) == expected){
        std::cout << "passed\n";
    } else{
        std::cout << "FAILED\n";
    }
}

//dumps out vector if needed for debugging
void PrintVec(std::vector<char> val){
    using namespace std;
    vector<char>::iterator iter;
    cout << "vector: ";
    for(iter = val.begin(); iter < val.end(); iter++){
        int val = (int)*iter;
        cout << val << " ";
    }
    cout << "\n";
}

void StackTests(int PlayerNumber){
    using namespace std;
    PermStack Stack = PermStack(PlayerNumber);

    cout << "*****************************Stack test 1: output inital permutations*****************************\n";
    Stack.GenerateFirstPermutations();

    while(!Stack.IsEmpty()){
        PrintVec(*(Stack.Peek()));
        Stack.Pop();
    }

    cout << "**************************Stack test 2: generate subsiquent permutations**************************\n";
    PermStack Stack2 = PermStack(5);
    Stack2.GenerateFirstPermutations();

    vector<vector<char>> result =Stack2.GetValidOrder();
    while(!Stack2.IsEmpty()){
        PrintVec(*(Stack2.Peek()));
        Stack2.Pop();
    }
}