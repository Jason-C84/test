#include <iostream>

using namespace std;

void SelectSort(int a[], int len){
    int minVal = 0;
    int minIndex = 0;
    int i = 0;
    int j = 0;
    for(i = 0; i < len; i++){
        minVal = a[i];
        minIndex = i;
        for(j = i; j < len; j++){
            if(a[j] < minVal){
                minVal = a[j];
                minIndex = j;
            }
        }
        a[minIndex] = a[i]; //此处很关键
        a[i] = minVal;
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
    SelectSort(num, 9);
    print(num, 9);
    return 0;
}
