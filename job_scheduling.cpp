// Time Complexity: O(N log N)
// Auxiliary Space: O(N)

#include <bits/stdc++.h>

using namespace std;
// A structure to represent a job
struct Job {
  int id;     // Job Id
  int dead;   // Deadline of job
  int profit; // Profit if job is over before or on deadline
};

bool comparison(Job a, Job b) { return (a.profit > b.profit); }

pair<int, int> jobScheduling(Job arr[], int n) {

  sort(arr, arr + n, comparison);
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++) {
    maxi = max(maxi, arr[i].dead);
  }

  int slot[maxi + 1];

  for (int i = 0; i <= maxi; i++)
    slot[i] = -1;

  int countJobs = 0, jobProfit = 0;

  for (int i = 0; i < n; i++) {
    for (int j = arr[i].dead; j > 0; j--) {
      if (slot[j] == -1) {
        slot[j] = i;
        countJobs++;
        jobProfit += arr[i].profit;
        break;
      }
    }
  }

  return make_pair(countJobs, jobProfit);
}

int main() {
  int n = 4;
  Job arr[n] = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};

  pair<int, int> ans = jobScheduling(arr, n);
  cout << ans.first << " " << ans.second << endl;

  return 0;
}
