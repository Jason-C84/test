#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char* loopStr(char *str, int step){
    int len = strlen(str);
    int temp[len];

    for (int i = 0; i < len; i++){
        int index = (i + len + step) % len;
        temp[i] = index;
    }

    char *tempstr = (char*)malloc(sizeof(char)*(len+1));
    tempstr[len] = '\0';
    for(int i = 0; i < len; i++){
        cout << temp[i] << "  ";
        tempstr[i] = str[temp[i]];
    }
    cout << endl;
    return tempstr;

}

void loopStr1(char *str, int step){
    int len = strlen(str);
    int temp[len];

    for (int i = 0; i < len; i++){
        int index = (i + len + step) % len;
        temp[i] = index;
    }

    char *tempstr = (char*)malloc(sizeof(char)*(len+1));
    tempstr[len] = '\0';
    for(int i = 0; i < len; i++){
        cout << temp[i] << "  ";
        tempstr[i] = str[temp[i]];
    }
    cout << endl;
    strcpy(str, tempstr);
    free(tempstr);

}

int main(int argc, char *argv[]){

    char str[] = "abcdefgh";
    int step = 0;
    cout << "Enter loop step: ";
    cin >> step;

    char *res = loopStr(str, step);

    cout << "str = " << str << endl;
    cout << "res = " << res << endl;

    loopStr1(str, step);
    cout << "str = " << str << endl;

    return 0;
}
