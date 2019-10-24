#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char *bigAdd(char *str1, char *str2){
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);
    int lenRes = (lenStr1>=lenStr2) ? (lenStr1 + 1) : (lenStr2 + 1);
    int c = 0;
    char *result = (char *)malloc(sizeof(char)*(lenRes+1));
    if(result == NULL) {
        cout << "malloc failed" << endl;
        return NULL;
    }
    result[lenRes] = '\0';
    int i = lenStr1 - 1;
    int j = lenStr2 - 1;
    int k = lenRes - 1;
    while(i >= 0 && j >= 0){
        result[k] = ((str1[i] - '0') + (str2[j] - '0') + c) % 10 + '0';
        c = ((str1[i] - '0') + (str2[j] - '0') + c) / 10;
        i--;
        j--;
        k--;
    }

    while(i >= 0){
        result[k] = ((str1[i] - '0') + c) % 10 + '0';
        c = ((str1[i] - '0') + c) / 10;
        i--;
        k--;
    }

    while(j >= 0){
        result[k] = ((str2[j] - '0') + c) % 10 + '0';
        c = ((str2[j] - '0') + c) / 10;
        j--;
        k--;
    }

    result[k] = c + '0';

    if(result[0] != '0'){
        return result;
    }

    return result+1;

}

int main(int argc, char *argv[]){

    char str1[] = "123456789323";
    char str2[] = "45671254563123";

    char *result = NULL;
    result = bigAdd(str1, str2);
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;
    cout << "result = " << result << endl;

    return 0;
}
