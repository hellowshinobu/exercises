#include <stdio.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>


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

template<typename BidirectionalIterator>
void my_reverse(BidirectionalIterator first, BidirectionalIterator last) {
    while (true) {
        if (first == last || first == --last)
            return;
        else {
            swap(*first++, *last);
        }
    }
}

void test(int size)
{
    cout << "Size: " << size << endl;
    vector<int> v(size);
    generate(v.begin(), v.end(), RandNum());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    my_reverse(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    test(20);
    test(17);
    return 0;
}
