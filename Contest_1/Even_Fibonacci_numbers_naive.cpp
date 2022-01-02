#include<iostream>
using namespace std;

int fib(int n) {
    if(n<=1) {
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int p;
        cin >> p;
        int i=1, sum=0;
        while(fib(i)<p) {
            if(fib(i)%2==0) {
                sum += fib(i);
            }
            i++;
        }
        cout << sum << endl;
    }
    return 0;
}