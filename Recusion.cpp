#include <iostream>
#include <vector>
using namespace std;

// 保存你选择的i
vector<int> vec;

int n, minsum = 1000000,total=0;;
int arr[20];

// 面临i的时候，选不选
void search(int i) {
  // 递归终止条件
  if (i == n) {
    // 打印一下子集
    int sum = 0;
    for (int i = 0; i < vec.size(); ++i) {
      sum += arr[vec[i]];
    }
    if (abs(total -2 * sum)  <= minsum)
      minsum = abs(total -2 * sum);

    // cout << endl;
    return;
  }
  // 1、不选i，继续i+1
  search(i + 1);

  // 2、选i，继续i+1
  vec.push_back(i);
  search(i + 1);
  // 还原现场
  vec.pop_back();
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    total+=arr[i];
  }
  // cout << fac(5);
  search(0);
  cout << minsum;
}
