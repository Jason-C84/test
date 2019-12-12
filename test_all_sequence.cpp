#include <iostream>

using namespace std;

void CalcAllSequence(char *perm, int from, int to){
    if(to <= 1){
        return;
    }
    if(from == to){
        for(int i = 0; i <= to; i++){
            cout << perm[i];
        }
        cout << endl;
    }
    for(int j = from; j <= to; j++){
        char temp = perm[j];
        perm[j] = perm[from];
        perm[from] = temp;

        CalcAllSequence(perm, from+1, to);

        temp = perm[j];
        perm[j] = perm[from];
        perm[from] = temp;
    }
}

int main(int argc, char *argv[]){
    char perm[] = "1234";
    CalcAllSequence(perm, 0, 3);
    return 0;
}
