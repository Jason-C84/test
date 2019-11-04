#include <iostream>

using namespace std;

void InsertSort(int num[], int len){
    int i = 0;
    int j = 0;
    int temp = 0;
    for(i = 1; i < len; i++){
        temp = num[i];
        for(j = i - 1; j >= 0 && temp < num[j]; j-- ){
            num[j+1] = num[j];
        }
        num[j+1] = temp;
    }
}

void ShellSort(int num[], int len){
    int i = 0;
    int j = 0;
    int h = 0;
    int temp = 0;
    for(h = len/2; h > 0; h = h/2){
        for(i = h; i < len; i++){
            temp = num[i];
            for(j = i - h; j >= 0 && temp < num[j]; j = j - h){
                num[j+h] = num[j];
            }
            num[j+h] = temp;
        }
    }
}

void QuickSort(int num[], int low, int high){
    if(low < high){
        int temp = num[low];
        int i = low;
        int j = high;
        while(i < j){
            while(i < j && temp < num[j]){
                j--;
            }
            if(i < j){
                num[i] = num[j];
                i++;
            }
            while(i < j && temp > num[i]){
                i++;
            }
            if(i < j){
                num[j] = num[i];
                j--;
            }
        }
        num[i] = temp;
        QuickSort(num, low, i-1);
        QuickSort(num, i+1, high);
    }
}

void BubbleSort(int num[], int len){
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(num[i] < num[j]){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
}

void SelectSort(int num[], int len){
    int i = 0;
    int j = 0;
    int minVal = 0;
    int minInd = 0;
    for(i = 0; i < len; i++){
        minVal = num[i];
        minInd = i;
        for(j = i; j < len; j++){
            if(num[j] < minVal){
                minVal = num[j];
                minInd = j;
            }
        }
        num[minInd] = num[i];
        num[i] = minVal;
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
    //BubbleSort(num, 9);
    //QuickSort(num, 0, 8);
    //InsertSort(num, 9);
    //ShellSort(num, 9);
    SelectSort(num, 9);
    print(num, 9);
    return 0;
}
