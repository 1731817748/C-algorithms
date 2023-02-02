#include <algorithm>
#include <iostream>
using namespace std;
int arr[1001];
void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
  baseIO("diamond");
  int n, k, maxt = 0;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    int temp = 0;
    int idx = upper_bound(arr, arr + n, arr[i] + k) - arr - 1;
    // case是从i开始的，到idx结束
    temp = idx - i + 1;
    if (temp > maxt)
      maxt = temp;
  }
  cout << maxt;
  return 0;
}
