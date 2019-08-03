#include <iostream>
#include <bitset>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

string convertIntegerToBinary(int n)
{
    string s = "";
    for (; n > 0; n = n / 2)
    {
        s += to_string(n % 2);
    }
    reverse(s.begin(), s.end());
    return s;
}

string convertFractionToBinary(float f)
{
    string s = "";
    for (int i = 0; i < 23 && abs(f) > .00001; i++)
    {
        f *= 2;
        s += to_string(int(f));
        f = f >= 1 ? f - 1 : f;
    }
    return s;
}

string convertDecimalToBinary(float f)
{
    string s = convertIntegerToBinary(int(f));
    s += ".";
    s += convertFractionToBinary(f - int(f));
    return s;
}

void floatBits(float f, char *buf)
{
    memcpy(buf, &f, 4);
}

void floatBits2(float f, char *buf)
{
    int signbit = f >= 0 ? 0 : 1;
    bitset<23> matissan;
    string floatStr = convertDecimalToBinary(f);
}

const void print(const char *buf)
{
    for (int i = 0; i < 4; i++)
    {
        cout << bitset<8>(buf[i]) << endl;
    }
}

int main()
{
    cout << convertDecimalToBinary(97.148) << endl;
    cout << convertDecimalToBinary(12.375) << endl;
    /* 
    char buf[4];
    floatBits(97.148, buf);
    print(buf);
    floatBits2(97.148, buf);
    print(buf);
    */
}
