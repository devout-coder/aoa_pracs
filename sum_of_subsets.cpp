// Time Complexity: O(N * sum)
// Space Complexity: O(N * sum)

#include <iostream>
using namespace std;

void subsetSum(int set[], int subSet[], int n, int subSize, int total,
               int nodeCount, int sum) {
  if (total == sum) {

    for (int i = 0; i < subSize; i++) {
      cout << subSet[i] << "  ";
    }
    cout << endl;

    subsetSum(set, subSet, n, subSize - 1, total - set[nodeCount],
              nodeCount + 1, sum); // for other subsets
    return;
  } else {
    for (int i = nodeCount; i < n; i++) { // find node along breadth
      subSet[subSize] = set[i];
      subsetSum(set, subSet, n, subSize + 1, total + set[i], i + 1,
                sum); // do for next node in depth
    }
  }
}

int main() {
  int weights[] = {10, 7, 5, 18, 12, 20, 15};
  int size = 7;

  int *subSet =
      new int[size]; // create subset array to pass parameter of subsetSum
  subsetSum(weights, subSet, size, 0, 0, 0, 35);
  delete[] subSet;
}