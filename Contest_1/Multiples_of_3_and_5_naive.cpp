#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int sum = 0;
        int p;
        cin >> p;
        int i=3;
        while(i < p) {
            if(i%3==0 || i%5==0) {
                sum += i;
            }
            i++;
        }
        cout << sum << endl;
    }
    return 0;
}