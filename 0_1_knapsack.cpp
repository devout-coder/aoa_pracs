// Time Complexity : O(N *W)
// Auxiliary Space : O(N *W)

#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n) {
  vector<vector<int>> K(n + 1, vector<int>(W + 1));

  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      if (i == 0 || w == 0) {
        K[i][w] = 0;
      } else if (wt[i - 1] <= w) {
        K[i][w] = max(K[i - 1][w], val[i - 1] + K[i - 1][w - wt[i - 1]]);
      } else {
        K[i][w] = K[i - 1][w];
      }
    }
  }
  return K[n][W];
}

int main() {
  int profit[] = {60, 100, 120};
  int weight[] = {10, 20, 30};
  int W = 50;
  int n = sizeof(profit) / sizeof(profit[0]);

  cout << knapSack(W, weight, profit, n);

  return 0;
}
