#include <bits/stdc++.h>
using namespace std;

struct Item {
    string name;
    double value, weight;
};

bool compare(Item a, Item b) {
    double r1 = a.value / a.weight;
    double r2 = b.value / b.weight;
    return r1 > r2;
}

void fractionalKnapsackForThieves(double W, vector<Item>& arr) {
    sort(arr.begin(), arr.end(), compare);

    int thief = 1;

    while (!arr.empty()) {
        double capacity = W;
        double totalValue = 0.0;

        cout << "Thief " << thief << " carries:\n";

        for (int i = 0; i < arr.size() && capacity > 0; ) {
            double take;

            if (capacity >= arr[i].weight) {
                take = arr[i].weight;
            } else {
                take = capacity;
            }

            double puv = arr[i].value / arr[i].weight;
            double profit = take * puv;

            cout << take << " kg of " << arr[i].name << endl;

            totalValue += profit;
            capacity -= take;

            arr[i].weight -= take;
            arr[i].value -= profit;

            if (arr[i].weight == 0) {
                arr.erase(arr.begin() + i);
            } else {
                i++;
            }
        }

        cout << "Profit: " << totalValue << " taka\n\n";
        thief++;
    }

    cout << "Total thieves needed: " << thief-1 << endl;
}

int main() {
    vector<Item> arr = {
        {"Rice", 840, 12},
        {"Salt", 870, 10},
        {"Saffron", 2000, 8},
        {"Sugar", 500, 5}
    };

    double W = 9;

    fractionalKnapsackForThieves(W, arr);

    return 0;
}
