#include <iostream>
#include <cstring>

using namespace std;

class MyString{
public:
    MyString(char *str = NULL);
    MyString(const MyString &other);
    ~MyString();
    MyString &operator=(const MyString &other);
private:
    char *m_string;
};

MyString::MyString(char *str){
    cout << "constructor" << endl;
    if(str == NULL){
        m_string = new char[1];
        *m_string = '\0';
    }else{
        m_string = new char[strlen(str)+1];
        strcpy(m_string, str);
    }
}

MyString::~MyString(){
    cout << "destructor" << endl;
    if (m_string != NULL){
        delete[] m_string;
        m_string = NULL;
    }
}

MyString::MyString(const MyString &other){
    cout << "copy constuctor" << endl;
    m_string = new char[strlen(other.m_string)+1];
    strcpy(m_string, other.m_string);
}

MyString &MyString::operator=(const MyString &other){
    cout << "operator = " << endl;
    if(this == &other){
        return *this;
    }else{
        delete[] m_string;
        m_string = new char[strlen(other.m_string)+1];
        strcpy(m_string, other.m_string);
        return *this;
    }
}


class String{
public:
    String(char *str = NULL);
    String(const String &other);
    ~String();
    String &operator=(const String &other);
private:
    char *m_string;
};

String::~String(){
    cout << "destructing String" << endl;
    if(m_string != NULL){
        delete[] m_string;
        m_string = NULL;
    }
}

String::String(char *str){
    cout << "constructing String" << endl;
    if(str == NULL){
        m_string = new char[1];
        *m_string = '\0';
    }else{
        m_string = new char[strlen(str)+1];
        strcpy(m_string, str);
    }
}



String::String(const String &other){
    cout << "copy constructing String" << endl;
    m_string = new char[strlen(other.m_string)+1];
    strcpy(m_string, other.m_string);
}

String & String::operator=(const String &other){
    cout << "opertor = String" << endl;
    if (this == &other){
        return *this;
    }else{
        delete[] m_string;
        m_string = new char[strlen(other.m_string)+1];
        strcpy(m_string, other.m_string);
        return *this;
    }
}

int main(int argc, char *argv[]){
    MyString a("hello");
    MyString b("world");
    MyString c(a);
    c = b;
    cout << "-----------------------" << endl;
    String aa("hello");
    String ba("world");
    String ca(aa);
    ca = ba;

    return 0;
}
