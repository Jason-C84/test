#include <iostream>

using namespace std;

void insert_sort(int a[], int len){
    int i = 0;
    int j = 0;
    for(i = 1; i < len; i++){
        int temp = a[i];
        int j = 0;
        for(j = i - 1; j >=0 && a[j] > temp; j--){
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }
}

void print(int a[], int len){
    for(int i = 0; i < len; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(int argc, char *argv[]){
    int num[] = {7,3,5,8,9,1,2,4,6};
    print(num, 9);
    insert_sort(num, 9);
    print(num, 9);
    return 0;
}
