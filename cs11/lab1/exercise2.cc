#include <stdio.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const char* alphabet = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWSYZ"};
struct RandStr
{
    RandStr()
    {
        alphabetLen_ = strlen(alphabet);
    }
    string operator() ()
    {
        string ret;
        int len = rand()%11 + 5;
        for (int i = 0; i < len; i++)
        {
            int pos = rand()%alphabetLen_;
            ret += alphabet[pos];
        }
        return ret;
    }

    int alphabetLen_;
};

struct ComStrLen
{
    bool operator()(const string& lhs, const string& rhs)
    {
        return lhs.size() < rhs.size();
    }
};

int main()
{
    vector<string> strVec(100);
    generate(strVec.begin(), strVec.end(), RandStr());
    sort(strVec.begin(), strVec.end());
    copy(strVec.begin(), strVec.end(), ostream_iterator<string>(cout, "\n"));
    sort(strVec.begin(), strVec.end(), ComStrLen());

    cout << "-----------------------------------" << endl;
    copy(strVec.begin(), strVec.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}
