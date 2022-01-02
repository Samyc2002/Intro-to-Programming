#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

int main() {
    long long int t;
    cin >> t;
    while(t--) {
        long long int n;
        cin >> n;
        long long int sum = 0;
        for(int i=1; i<=n; i++) {
            sum += (i*i*i) - (i*i);
        }
        cout << sum << endl;
    }
    return 0;
}