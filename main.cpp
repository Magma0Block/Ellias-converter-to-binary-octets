#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

unsigned BinToDec(unsigned Value) {
  unsigned result = 0;
  for (unsigned i = 1; Value; Value /= 10, i *= 2) {
    result += i * (Value % 10);
  }
  return result;
}

int main() {
  int t, r = 0;
  string s;
  getline(cin, s);
  vector<int> arr(0);
  vector<int> res(0);
  int l = s.length();
  for (int i = 0; i < l; ++i) {
    if (s.find(" ") != string::npos) {
      s.erase(s.find(" "), 1);
    }
  }
  l = s.length();
  if (s[0] == '1')
    t = 1;
  else
    t = 0;
  s.erase(0, 1);
  int f = 0;
  while (s.size() > 0) {
    if (s[f] == '0') {
      r++;
    }
    else {
      s.erase(0, r);
      int x = 0;
      for (int j = 0; j < r + 1; ++j) {
        if (s[j] == '1') {
          x += 1 * pow(10, r - j);
        }
      }
      arr.push_back(x);
      s.erase(0, r + 1);
      f = -1;
      r = 0;
    }
    f++;
  }

  for (int i = 0; i < arr.size(); ++i) {
    arr[i] = BinToDec(arr[i]);
  }

  if (t == 1) {
    for (int i = 0; i < arr.size(); ++i) {
      if (i % 2 == 0) {
        for (int j = 0; j < arr[i]; ++j) res.push_back(1);
      } else {
        for (int j = 0; j < arr[i]; ++j) res.push_back(0);
      }
    }
  }
  else {
    for (int i = 0; i < arr.size(); ++i) {
      if (i % 2 == 0) {
        for (int j = 0; j < arr[i]; ++j) res.push_back(0);
      } else {
        for (int j = 0; j < arr[i]; ++j) res.push_back(1);
      }
    }
  }
  
  cout << endl;
  for (int i = 0; i < res.size(); ++i) {
    if (i % 8 == 0) cout << " ";
    cout << res[i];
  }
  return 0;
}
