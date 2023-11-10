#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Activity {
    int start;
    int finish;
};

bool compareActivities(const Activity& a1, const Activity& a2) {
    return a1.finish < a2.finish;
}


void selectActivities(vector<Activity>& activities) {
    int n = activities.size();

    
    sort(activities.begin(), activities.end(), compareActivities);

    cout << "Selected Activities: ";
    int prevFinish = activities[0].finish;
    cout << "(" << activities[0].start << ", " << activities[0].finish << ") ";


    for (int i = 1; i < n; i++) {

        if (activities[i].start >= prevFinish) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ") ";
            prevFinish = activities[i].finish;
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    cout << "Enter the start and finish times for each activity:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Activity " << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].finish;
    }

    selectActivities(activities);

    return 0;
}
