#include <iostream>

using namespace std;

void shellSort(int a[], int len){
    int h = 0;
    for(h = len/2; h > 0; h = h/2){
        int i = 0;
        int j = 0;
        for(i = h; i < len; i++){
            int temp = a[i];
            for(j = i - h; j >=0 && a[j] > temp; j = j - h){
                a[j + h] = a[j];
            }
            a[j + h] = temp;
        }
    }
}

void print(int a[], int len){
    for(int i = 0; i < len; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(int argc, char *argv[]){
    int num[] = {7,3,5,8,9,1,2,4,6,0};
    print(num, 10);
    shellSort(num, 10);
    print(num, 10);
    return 0;
}
