#include <iostream>

using namespace std;

void bub_sort1(int *arr, int leng){
    for(int i = 0; i < leng; i++){
        for(int j = i+1; j < leng; j++) {
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void select_sort(int *arr, int leng){
    for(int i = 0; i < leng; i++){
        int index = i;
        for(int j = i + 1; j < leng; j++){
            if(arr[index] > arr[j]){
                index = j;
            }
        }
        if (index == i) {
            continue;
        }

        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

void insert_sort(int *arr, int leng){
    for(int i = 1; i < leng; i++){
        int temp = arr[i];
        int j = 0;
        for(j = i - 1; j >= 0 && temp < arr[j]; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
}

void shell_sort(int *arr, int leng){
    int h = leng / 3 + 1;

    while(h > 0) {
        for(int i = 0; i < leng; i++){
            //h = h/3 + 1;
            cout << "h = " << h << endl;
            cout << "i = " << i << endl;
            cout << "arr[ "<< i <<" ] = " << arr[i] << endl;
            int j = 0;
            int temp = arr[i];
            for(j = i + h; j < leng && temp > arr[j]; j = j + h){
                cout << "arr["<< j  << " - " << h <<"] = " << arr[j-h] <<endl;
                cout << "arr[" << j <<"]=" << arr[j] << endl;
                arr[j - h ] = arr[j];
                cout << "arr["<< j  << " - " << h <<"] = " << arr[j-h] <<endl;
                cout << "arr[" << j <<"]=" << arr[j] << endl;
                cout << "======================" << endl;
            }
            arr[j - h] = temp;

            for (int k = 0; k < leng; k ++){
                cout << arr[k] << " " ;
            }
            cout <<endl;
        }
        h--;
    }

}


void ShellSort(int arr[], int length)
{
	int increasement = length;
	int i, j, k;
	do
	{
		// 确定分组的增量
		increasement = increasement / 3 + 1;
		for (i = 0; i < increasement; i++)
		{
			for (j = i + increasement; j < length; j += increasement)
			{
				if (arr[j] < arr[j - increasement])
				{
					int temp = arr[j];
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement)
					{
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}
			}
		}
	} while (increasement > 1);

}

void quick_sort(int *arr, int aStart, int aEnd){
    if (aStart >= aEnd){
        return;
    }
    int i = aStart;
    int j = aEnd;
    int baseval = arr[aStart];
    while(i < j){
        while(i < j && arr[j] > baseval){
            j--;
        }
        if (i < j){
            arr[i] = arr[j];
            i++;
        }
        while(i < j && arr[i] < baseval){
            i++;
        }
        if (i < j){
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = baseval;
    quick_sort(arr, aStart, i-1);
    quick_sort(arr, i+ 1, aEnd);
}

void merge_sort(int *arr, int aStart, int aEnd, int *temp){
    cout << "merge_sort" << endl;
    cout << "start = " << aStart << endl;
    cout << "end = " << aEnd << endl;
    if (aStart >= aEnd){
        return;
    }
    int aMid = (aStart+aEnd)/2;
    merge_sort(arr, aStart, aMid, temp);
    merge_sort(arr, aMid + 1, aEnd, temp);

    int i_start = aStart;
    int i_end = aMid;
    int j_start = aMid + 1;
    int j_end = aEnd;

    int index = 0;
    cout << "===========" << endl;
    while(i_start <= i_end && j_start <= j_end){
        if(arr[i_start] < arr[j_start]){
            temp[index] = arr[i_start];
            index++;
            i_start++;
        } else {
            temp[index] = arr[j_start];
            index++;
            j_start++;
        }
    }
    while(i_start <= i_end){
        temp[index] = arr[i_start];
        index++;
        i_start++;
    }
    while(j_start <= j_end){
        temp[index] = arr[j_start];
        index++;
        j_start++;
    }

    for(int i = 0; i < index; i++){
        arr[aStart+i] = temp[i];
    }

}


int main(int argc, char * argv[]){

    int arr[] = {4,2,8,0,5,1};
    int arr1[] = {9,8,7,6,5,4,3,2,1};
    int temp[10] ;
    int leng = sizeof(arr)/sizeof(int);
    int leng1 = sizeof(arr1)/sizeof(int);

    for(int i = 0; i < leng; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "leng = " << leng << endl;

    //bub_sort1(arr, leng);
    //select_sort(arr, leng);
    //insert_sort(arr, leng);
    //shell_sort(arr, leng);
    //shell_sort(arr1, leng1);
    //quick_sort(arr1, 0, leng1-1);
    merge_sort(arr, 0, leng-1, temp);
    //shell_sort2(arr, leng);
    //ShellSort(arr, leng);
    /*
    for(int i = 0; i < leng; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    */
    for(int i = 0; i < leng; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
        for(int i = 0; i < leng; i++){
        cout << temp[i] << " ";
    }
    cout << endl;

    return 0;
}
