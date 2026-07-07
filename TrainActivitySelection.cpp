#include <bits/stdc++.h>
using namespace std;

struct Train {
    int arrival, departure;
};

bool compare(Train a, Train b) {
    return a.departure < b.departure;
}

void selectTrains(vector<Train>& trains) {
    sort(trains.begin(), trains.end(), compare);

    cout << "Selected trains:\n";

    int count = 1;
    int lastDeparture = trains[0].departure;

    cout << "[" << trains[0].arrival << ", "
         << trains[0].departure << ")\n";

    for (int i = 1; i < trains.size(); i++) {
        if (trains[i].arrival >= lastDeparture + 1) {
            cout << "[" << trains[i].arrival << ", "
                 << trains[i].departure << ")\n";

            lastDeparture = trains[i].departure;
            count++;
        }
    }

    cout << "Maximum number of trains = " << count << endl;
}

int main() {
    vector<Train> trains = {
       {8,12}, {6,9}, {11,14}, {2,7},
        {7,11}, {12,20}, {7,12}, {13,19}
    };

    selectTrains(trains);

    return 0;
}
