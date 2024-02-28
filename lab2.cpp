#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
//Написать программу, сортирующую по убыванию одномерный массив случайных целых чисел, находящихся в интервале {0,100}. 
int main(){
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 101;
    }
    int min = a[0];
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            int temp = a[i];
            a[i] = a[maxIndex];
            a[maxIndex] = temp;
        }
    }
    for(auto i : a){
        printf("%d ", i);
    }

    return 0;
}