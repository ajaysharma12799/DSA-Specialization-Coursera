#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> v)
{
  cout << "Printing array:\n";
  for (auto x : v)
  {
    for (auto y : x)
    {
        cout << y << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}
int optimal_weight(int W, const vector<int> &weights)
{
  vector<vector<int>> value(weights.size() + 1, vector<int>(W + 1, 0));

  for (size_t i = 1; i <= weights.size(); i++)
  {
    for (int w = 1; w <= W; w++)
    {
      value[i][w] = value[i - 1][w];
      if (weights[i - 1] <= w)
      {
        int val = value[i - 1][w - weights[i - 1]] + weights[i - 1];
        if (value[i][w] < val)
        {
          value[i][w] = val;
        }
      }
    }
  }
  return value[weights.size()][W];
}

int main()
{
  int n, W;
  cin >> W >> n;
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> weights[i];
  }
  cout << optimal_weight(W, weights) << '\n';
}