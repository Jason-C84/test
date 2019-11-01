#include<iostream>

using namespace std;

void quick_sort(int a[], int low, int high){
    if(low < high){
        int val = a[low];
        int i = low;
        int j = high;
        while(i < j){
            while(i < j && a[j] >= val){
                j--;
            }
            if (i < j){
                a[i] = a[j];
                i++;
            }
            while(i < j && a[i] <= val){
                i++;
            }
            if(i < j){
                a[j] = a[i];
                j--;
            }
        }
        a[i] = val;
        quick_sort(a, low, i-1);
        quick_sort(a, i+1, high);
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
    quick_sort(num, 0, 8);
    print(num, 9);
    return 0;
}
