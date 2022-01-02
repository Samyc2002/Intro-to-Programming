#include <iostream>
using namespace std;

int myFunction(int n) {
  if(n<=1) {
      return 1;
  }
  return myFunction(n-1)+myFunction(n-2);
}

int main() {
  int n;
  cout << "enter the index: ";
  cin >> n;
  cout << myFunction(n-1);
  return 0;
}
