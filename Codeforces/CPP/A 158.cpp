#include <iostream>

using namespace std;

int inputList[50];
int n,k,m;
int cnt=0;

int main(){

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> inputList[i];
        if(i+1==k)
            m=inputList[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(inputList[i]>=m && inputList[i] > 0)

            cnt++;
    }
    cout << cnt ;

    return 0;
}
