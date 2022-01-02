#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

int search(vector<int> v, int n) {
    for (int i=0; i<v.size(); i++) {
        if(v[i] == n) {
            return i;
        }
    }
    return -1;
}

int product(vector<int> v, int i) {
    long long int p=1;
    for(int k = 0; k<i; k++) {
        p *= v[k];
    }
    return p;
}

vector<int> primeFactors(int n) {
    vector<int> arr;
    while(n%2 == 0) {
        arr.push_back(2);
        n /= 2;
    }

    for(int i=3; i<=sqrt(n); i+=2) {
        while(n%i ==0 ) {
            arr.push_back(i);
            n /= i;
        }
    }
    
    if(n>2) {
        arr.push_back(n);
    }

    return arr;
}

void map(int a, int b, vector<int> u, vector<int> v) {
    int index = search(u, a);
    v[index] = b;
}

void solve(long long int n) {
    vector<int> primes = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
    vector<int> freq(13, 0);
    vector<int> track;
    for(int i=1; i<=n; i++) {
        if(i == 1) {
            track.push_back(1);
            freq[0]++;
        } else {
            vector<int> facts = primeFactors(i);
            sort(facts.begin(), facts.end());
            if(facts.size() == 1) {
                track.push_back(facts[0]);
                int index = search(primes, i);
                freq[index]++;
            } else {
                int c=1, k=0;
                for(int j=0; j<facts.size()-1; j++) {
                    if(facts[j] == facts[j+1]) {
                        c++;
                    } else {
                        if(c > freq[search(primes, facts[j])]) {
                            map(facts[j], c, primes, freq);
                            track.push_back(facts[j]);
                        }
                        c=1;
                    }
                    k=facts[j+1];
                }
                if(c > freq[search(primes, k)]) {
                    track.push_back(k);
                }
            }
        }
    }
    cout << product(track, track.size()) << endl;
}

int main() {
    long long int t;
    cin >> t;
    while(t--) {
        long long int n;
        cin >> n;
        solve(n);
    }
    return 0;
}