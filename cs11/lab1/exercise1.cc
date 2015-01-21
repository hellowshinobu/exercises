#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

struct RandNum
{
    RandNum()
    {
        srand(time(NULL));
    }
    int operator() ()
    {
        return rand()%100;
    }
};


int main()
{
    vector<int> vInt(100);
    generate(vInt.begin(), vInt.end(), RandNum());

    copy(vInt.begin(), vInt.end(), ostream_iterator<int>(cout, ", "));

    return 0;
}
