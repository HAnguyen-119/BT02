#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n][2];
    for (int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    int min_x  = arr[0][0], min_y = arr[0][1];
    for (int i = 0; i < n; i++){
        if (arr[i][0] < min_x) min_x = arr[i][0];
        if (arr[i][1] < min_y) min_y = arr[i][1];
    }
    cout << min_x * min_y;
    return 0;

}
