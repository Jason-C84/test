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

void Swap(int a[], int from, int to){
    int temp = a[from];
    a[from] = a[to];
    a[to] = temp;
}

void HeapAdjust(int a[], int from, int to){
    int i = 0;
    int temp = a[from];
    for(i = 2*from+1; i <= to; i = 2*i+1){
        if(i < to && a[i] < a[i+1]){
            i++;
        }
        if(temp > a[i]){
            break;
        }
        a[from] = a[i];
        from = i;
    }
    a[from] = temp;
}

void HeapSort(int a[], int len){
    for(int i = len/2-1; i >= 0; i--){
        HeapAdjust(a, i, len-1);
    }
    for(int i = len-1; i >= 0; i--){
        Swap(a, 0, i);
        HeapAdjust(a, 0, i-1);
    }
}

void Merge(int a[], int *temp, int aStart, int mid, int aEnd){
    int iStart = aStart;
    int iEnd = mid - 1;
    int jStart = mid;
    int jEnd = aEnd;

    int index = iStart;
    int arrlen = jEnd - iStart + 1;

    while(iStart <= iEnd && jStart <= jEnd){
        if(a[iStart] < a[jStart]){
            temp[index] = a[iStart];
            index++;
            iStart++;
        }else{
            temp[index] = a[jStart];
            index++;
            jStart++;
        }
    }

    while(iStart <= iEnd){
        temp[index] = a[iStart];
        index++;
        iStart++;
    }

    while(jStart <= jEnd){
        temp[index] = a[jStart];
        index++;
        jStart++;
    }

    for(int i = 0; i < arrlen; i++,jEnd--){
        a[jEnd] = temp[jEnd];
    }
}

void mSort(int a[], int *temp, int low, int high){

    if(low >= high){
        return;
    }
    int mid = (low+high)/2;

    mSort(a, temp, low, mid);
    mSort(a, temp, mid+1, high);
    Merge(a, temp, low, mid+1, high);

}

void MergeSort(int a[], int len){
    int *temp = new int[len];
    if(temp != NULL){
        mSort(a, temp, 0, len-1);
        delete []temp;
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
    //SelectSort(num, 9);
    //HeapSort(num, 9);
    MergeSort(num, 9);
    print(num, 9);
    return 0;
}
