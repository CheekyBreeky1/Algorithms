#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>

#define TASKS_COUNT 50
#define TASKS_VALUES_LIMIT 100

using namespace std;

void fillRandomTasks(vector<pair<int,int>> &tasks) {
    srand(time(NULL));
    for (int i = 0; i < TASKS_COUNT; i++) {
        tasks.push_back({ 1+rand()% TASKS_VALUES_LIMIT, 1+rand()% TASKS_VALUES_LIMIT });
    }
}

void printTasks(vector<pair<int, int>> &tasks) {
    cout << "========\n";
    for (auto item : tasks) {
        cout << to_string(item.first) + " " + to_string(item.second) + "\n";
    }
    cout << "========\n";
}

void makeSceduleByDiv(vector<pair<int, int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first / a.second > b.first / b.second;
        });
}

void makeSceduleBySub(vector<pair<int, int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first - a.second > b.first - b.second;
        });
}

int main()
{
    //first element in pair - priority
    //second element in pair - length
    vector<pair<int, int>> tasksForDiv;
    vector<pair<int, int>> tasksForSub;

    cout << "Sort with division\n";
    cout << "priority - length\n";
    
    fillRandomTasks(tasksForDiv);
    cout << "Before\n";
    printTasks(tasksForDiv);
    makeSceduleByDiv(tasksForDiv);
    cout << "After\n";
    printTasks(tasksForDiv);

    cout << "Sort with substraction\n";
    
    fillRandomTasks(tasksForSub);
    cout << "Before\n";
    printTasks(tasksForSub);
    makeSceduleBySub(tasksForSub);
    cout << "After\n";
    printTasks(tasksForSub);
}
