#include <iostream>
#include <cstring>

using namespace std;


int StrToInt(char *str){
    static const int MAX_INT = (int)(((unsigned)~0)>>1);
    static const int MIN_INT = -(int)(((unsigned)~0)>>1)-1;
    unsigned int n = 0;

    if(str == NULL){
        return 0;
    }
    while(isspace(*str)){
        str++;
    }
    bool flag = true;
    if((*str == '+') || (*str == '-')){
        if(*str == '-'){
            flag = false;
        }
        str++;
    }
    while(isdigit(*str)){
        int c = *str - '0';
        if(flag && (n > MAX_INT/10 || (n == MAX_INT/10 && c > MAX_INT%10))){
            n = MAX_INT;
            break;
        }else if(!flag && (n > (unsigned)MIN_INT/10 || (n == (unsigned)MIN_INT/10 && c > (unsigned)MIN_INT%10))){
            n = MIN_INT;
            break;
        }

        n = n*10 + c;
        str++;
    }

    return flag ? n : -n;

}

int main(int argc, char *argv[]){

    char str[] = "-2147483649";
    int iStr = StrToInt(str);
    cout << iStr << endl;
    return 0;
}
