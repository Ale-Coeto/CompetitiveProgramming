// Rbrgs.cpp
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>

#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define aFor(i, a) for (auto &i : a)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ll> vll;

int main()
{
    sync;
    string str;
    cin >> str;

    int high = 1;
    long ans = 1;
    long cur = 1;
    char prev = str[0];

    while (high <= str.length())
    {
        if (prev == str[high])
        {
            cur++;
            high++;
        }
        else
        {
            prev = str[high];
            high++;
            ans = max(cur, ans);
            cur = 1;
        }
    }

    cout << ans << endl;
    return 0;
}