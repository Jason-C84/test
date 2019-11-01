#include <iostream>

using namespace std;

void bubble_sort(int a[], int len){
    for(int i = 0; i < len; i++){
            for(int j = i+1; j < len; j++){
                if(a[i]>a[j]){
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
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
    int num[] = {7,3,5,8,9,1,2,4,6};
    print(num, 9);
    bubble_sort(num,9);
    print(num, 9);
    return 0;
}
