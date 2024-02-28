#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
//Написать программу, сортирующую по возрастанию одномерный массив случайных целых чисел, находящихся в интервале {2,103}. Использовать сортировку выбором. 
int main(){
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = 2 + rand() % 103 - 1;
    }
    int min = a[0];
    int t;
    for (int i = 0; i < n- 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for(auto i : a){
        printf("%d ", i);
    }

    return 0;
}