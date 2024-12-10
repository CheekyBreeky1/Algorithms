#include <iostream>
#include <vector>
#include <random>
#define COUNT_ITEMS 5000
#define PARAM_SIZE_LIMIT 10000
#define KNAPSACK_SIZE 10000
using namespace std;

void createItems(vector<pair<int, int>> &items) {
    srand(time(NULL));
    for (int i = 0; i < COUNT_ITEMS; i++) {
        items.push_back({ 1 + rand() % PARAM_SIZE_LIMIT,1 + rand() % PARAM_SIZE_LIMIT });
    }
}

void printItems(vector<pair<int, int>> &items) {
    cout << "ITEMS\n";
    cout << "VALUE SIZE\n";
    cout << "--------\n";
    for (int i = 0; i < items.size(); i++) {
        cout << items[i].first << " " << items[i].second;
        cout << "\n";
    }
    cout << "--------\n";
}

int knapsackSolution(vector<pair<int, int>>& items) {
    vector<vector<int>> table(COUNT_ITEMS + 1, vector<int>(KNAPSACK_SIZE + 1, 0));
    for (int i = 1; i <= COUNT_ITEMS; i++) {
        for (int j = 0; j <= KNAPSACK_SIZE; j++) {
            if (items[i - 1].second > j) {
                table[i][j] = table[i - 1][j];
            }
            else {
                table[i][j] = max(table[i - 1][j], table[i - 1][j - items[i - 1].second] + items[i - 1].first);
            }
        }
    }
    return table[COUNT_ITEMS][KNAPSACK_SIZE];
}

void testKnapsackSolution() {
    //value, size
    vector<pair<int, int>> items;
    createItems(items);
    printItems(items);
    cout << "MAX VALUE: " << knapsackSolution(items);
}

int main()
{
    testKnapsackSolution();
}