#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string s;
    vector<string> a(n);

    srand(time(0));

    for (int i = 0; i < n; i++) {
        a[i] = to_string(rand() % 100) + "-" + to_string(rand() % 100) + "-" + to_string(rand() % 100);
        cout << a[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].compare(a[min]) < 0) {
                min = j;
            }
        }
        if (min != i) {
            s = a[i];
            a[i] = a[min];
            a[min] = s;
        }
    }

    for (auto i : a) {
        cout << i << endl;
    }

    return 0;
}

