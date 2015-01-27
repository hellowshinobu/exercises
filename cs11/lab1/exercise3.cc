#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <functional>

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

struct CountOddEven : public unary_function<int, void>
{
    int count_odd_;
    int count_even_;

    void operator() (int x)
    {
        x%2 == 0 ? count_even_++ : count_odd_++;
    }
};

int main()
{
    vector<int> vInt(100);
    generate(vInt.begin(), vInt.end(), RandNum());

    CountOddEven countOp = for_each(vInt.begin(), vInt.end(), CountOddEven());
    copy(vInt.begin(), vInt.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    cout << "count odd = " << countOp.count_odd_ << endl;
    cout << "count even = " << countOp.count_even_ << endl;
    return 0;
}
