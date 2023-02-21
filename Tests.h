#ifndef TEST_FUNCTS
#define TEST_FUNCTS
#include "PermStack.h"

void PrintVec(std::vector<char> val);

void FilterTests(int PlayerNumber);
void FilterTestResults(Filter filt, std::vector<char> val, bool expected);

void StackTests(int PlayerNumber);

#endif