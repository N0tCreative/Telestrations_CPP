#include "Tests.h"
#include <iostream>

/* Tests to verify that the filter is working as intended
 *
 */
void FilterTests(int PlayerNumber){
    using namespace std;
    Filter filt = Filter(PlayerNumber);

    vector<int> FilterTest1 ={1,3,2};
    cout << "************************Filter test 1: does not contain starting positions************************\n";
    FilterTestResults(filt, FilterTest1, false);

    cout << "********************************Filter test 2: allows non blocked*********************************\n";
    vector<int> FilterTest2 ={2,3,1};
    FilterTestResults(filt, FilterTest2, true);

    cout << "******************************Filter test 3: disallows after blocked******************************\n";
    vector<int> FilterTest3 ={2,3,1};
    filt.Block(FilterTest3);
    FilterTestResults(filt, FilterTest3, false);
    
    cout << "******************************Filter test 3: allows after unblocked*******************************\n";
    vector<int> FilterTest4 ={2,3,1};
    filt.Unblock(FilterTest4);
    FilterTestResults(filt, FilterTest4, true);

}

// output of results of the tests
void FilterTestResults(Filter filt, std::vector<int> val, bool expected){
    //PrintVec(val);
    if(filt.IsValid(val) == expected){
        std::cout << "passed\n";
    } else{
        std::cout << "FAILED\n";
    }
}

//dumps out vector if needed for debugging
void PrintVec(std::vector<int> val){
    using namespace std;
    vector<int>::iterator iter;
    cout << "vector: ";
    for(iter= val.begin(); iter < val.end(); iter++){
        cout << *iter + " ";
    }
    cout << "\n";
}