#include <bits/stdc++.h>
using namespace std;

int n = 4;
int dist[10][10] = {
    {0, 20, 42, 25}, {20, 0, 30, 34}, {42, 30, 0, 10}, {25, 34, 10, 0}};
int visited_all = (1 << n) - 1;

int tsp(int mask, int pos) {
  if (mask == visited_all) {
    return dist[pos][0];
  } else {
    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
      if ((mask & (1 << city)) == 0) {
        // unvisited
        int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
        ans = min(ans, newAns);
      }
    }
    return ans;
  }
}

int main() {
  cout << tsp(15, 0) << endl;
  return 0;
}