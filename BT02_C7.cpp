#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin >> n;
    m = n;
    do {
        if (n != m) cout << m << " ";
        m = n;
        if (n < 0){
            cout << n;
            break;
        }
    } while (cin >> n);
    return 0;
}
