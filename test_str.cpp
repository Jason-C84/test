#include <iostream>

using namespace std;

/**
* strlen
*/
int mystrlen(char *str){
    int length = 0;
    while(*str != '\0'){
        length++;
        str++;
    }
    return length;
}

/**
* strcmp
*/
int mystrcmp(char *str, char* str1){
    int bigger  = 1;
    int smaller = -1;
    int equ = 0;
    int result = equ;
    while(*str != '\0' && *str1 != '\0'){
       if(*str == *str1){
            str++;
            str1++;
       } else{
            if (*str > *str1){
                result = bigger;
                return result;
            } else {
                result = smaller;
                return result;
            }
       }
    }
    if (*str != '\0') {
        result = bigger;
        return result;
    }
    if (*str1 != '\0') {
        result = smaller;
        return result;
    }

    return result;
}

/**
* strcmp
*/
int mystrcmp1(char *str, char *str1){
    while(*str == *str1){
        if(*str == '\0'){
            break;
        }
        str++;
        str1++;
    }
    return *str - *str1;
}

/**
* strcpy
*/
char* mystrcpy(char *src, char *dest){
    char *temp = dest;
    if(mystrlen(src) == 0){
        return 0;
    }
    if (temp == NULL){
        return NULL;
    }
    while(*src != '\0'){
        *temp = *src;
        temp++;
        src++;
    }
    *temp = '\0';
    return dest;
}

/**
* strncpy
*/
char *mystrncpy(const char *src, int length, char *dest){
    char *temp = dest;
    while((*src != '\0') && (length > 0)){
        *temp = *src;
        temp++;
        src++;
        length--;
    }
    *temp = '\0';
    return dest;
}

/**
* strcat
*/
char *mystrcat(char *str1, char *str2){
    char *temp = str1;
    while(*temp != '\0'){
        temp++;
    }
    while(*str2 != '\0'){
        *temp = *str2;
        temp++;
        str2++;
    }
    *temp = '\0';
    return str1;
}

/**
* Êý×Ö×ª×Ö·û´®
*/
char *myInt2Str(int src, char *dest){
    cout << "myInt2Str" << endl;
    char *rest = dest;
    int flag = 0;
    char *sTemp = (char *)malloc(sizeof(char)*21);
    if(sTemp == NULL){
        return NULL;
    }

    char *temp = sTemp;
    if (src < 0){
        src = -src;
        flag = 1;
        cout << "src < 0 = " << src << endl;
    }

    int iBase = src;
    while(iBase > 0){
        int iTemp = iBase%10;
        iBase = iBase/10;
        *temp = iTemp + '0';
        temp++;
    }

    char *t = sTemp;
    int length = 0;
    while(*t != '\0'){
        length++;
        t++;
    }
    char *tt = rest;
    if (flag > 0) {
        *tt = '-';
        tt++;
    }

    while(length > 0){
      t--;
      *tt = *t;
      length--;
      tt++;
    }

    *tt = '\0';

    free(sTemp);
    return dest;
}
/**
* ×Ö·û´®ÄæÐò
*/
char *mystrinv(char *src, char *dest){
    if((src == NULL) || (dest == NULL)) {
        return NULL;
    }
    char *srctmp = src;
    char *desttmp = dest;

    int length = 0;
    while(*srctmp != '\0'){
        srctmp++;
        length++;
    }
    while(length > 0){
        srctmp--;
        *desttmp = *srctmp;
        desttmp++;
        length--;
    }
    return dest;

}

void printStr(char *msg, char *str, char token){
    if(str == NULL){
        return ;
    }
    char *tmp = str;
    cout << msg << endl;
    while(*tmp != '\0'){
        cout << *tmp << token;
        tmp++;
    }
    cout << endl;
}

int main(int argc, char* argv[]){
    char str[] = "987654321abcdefh";
    char str1[] = "987654321abcdefg";
    char *str2 = (char*)malloc(sizeof(char)*30);
    if (str2 == NULL){
        return -1;
    }
    char *str3 = (char*)malloc(sizeof(char)*30);
    if (str3 == NULL){
        return -1;
    }
    char *str4 = (char*)malloc(sizeof(char)*40);
    if (str4 == NULL){
        return -1;
    }
    char str5[20] = "123456";
    char str6[] = "abcde";

    char *str7 = (char*)malloc(sizeof(char)*20);
    if(str7 == NULL){
        return -1;
    }

    int length = mystrlen(str);
    int cmpres = mystrcmp(str, str1);
    int cmpres1 = mystrcmp1(str, str1);
    char *temp = mystrcpy(str, str2);
    char *temp1 = mystrncpy(str, 5, str3);
    char *temp2 = mystrcat(str5, str6);

    int testInt = -1234567;
    char *temp3 = myInt2Str(testInt, str4);
    char *temp4 = mystrinv(str5, str7);


    cout << "length = " << length << endl;
    cout << "cmpres = " << cmpres << endl;
    cout << "cmpres1 = " << cmpres1 << endl;

    printStr("mystrcpy", temp, '|');
    printStr("mystrncpy", temp1, '|');
    printStr("mystrcat", temp2, ' ');
    printStr("myInt2Str", temp3, ' ');
    printStr("mystrinv", temp4, ' ');

    free(str2);
    free(str3);
    free(str4);
    free(str7);

    return 0;
}
