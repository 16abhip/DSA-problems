#include <iostream>
using namespace std;

int lcs(string str1, string str2)
{
    if(str1.size() == 0 || str2.size() == 0)
    {
        return 0;
    }
    if(str1[0] == str2[0])
    {
        return 1 + lcs(str1.substr(1), str2.substr(1));
    }
    int x = lcs(str1, str2.substr(1));
    int y = lcs(str1.substr(1), str2);
    int z = lcs(str1.substr(1), str2.substr(1));
    return min(x, min(y,z));
}

int main()
{

}