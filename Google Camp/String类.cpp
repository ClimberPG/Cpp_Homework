#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char *cstr;
    int len;
public:
    //通过char数组指针来初始化String对象，深复制！你懂的

    String();

    String(const char* str);

    //拷贝构造函数
    String(const String& s);

    ~String();

    //字符串拼接，例如："abc" + "def" 结果是"abcdef"
    String operator+ (const String& s);

    //=号赋值，记得拷贝构造函数跟=号差别~
    String& operator= (const String& s);

    //以下三个是比较操作符，用于比较字符串的字典序
    bool operator== (const String& s);
    bool operator< (const String& s);
    bool operator> (const String& s);

    //取出字符串的第n位
    //String str("abc");str[0]为a，str[1]为b；
    //切记此话：注意当上边的str做以下赋值：str[1] = '\0'时，str实际上是字符串"a"，长度为1，因为字符串是以\0结束的
    char& operator[] (const int& n);

    //获取字符串的长度
    int size();

    //输出重载 记得末尾是不需要空行的！
    friend ostream& operator<< (ostream& out, const String& s);
};

String::String() {
    cstr = NULL;
    len = 0;
}

String::String(const char* str) {
    len = 0;
    if (str == NULL) {
        cstr = NULL;
    } else {
        cstr = new char[strlen(str) + 1];
        strcpy(cstr, str);
    }
}

String::String(const String& s) {
    len = 0;
    if (s.cstr == NULL) {
        cstr = NULL;
    } else {
        cstr = new char[strlen(s.cstr) + 1];
        strcpy(cstr, s.cstr);
    }
}

String::~String() {
    delete [] cstr;
    cstr = NULL;
    len = 0;
}

String String::operator+ (const String& s) {
    String newString;
    if(!s.cstr)
        newString = *this;
    else if (!cstr)
        newString = s;
    else {
        newString.cstr = new char[strlen(cstr)+strlen(s.cstr)+1];
        strcpy(newString.cstr, cstr);
        strcat(newString.cstr, s.cstr);
    }
    return newString;
}

String& String::operator= (const String& s) {
    if (this != &s) {
        delete[] cstr;
        if(!s.cstr) cstr = NULL;
        else {
            cstr = new char[strlen(s.cstr)+1];
            strcpy(cstr, s.cstr);
        }
    }
    return *this;
}

bool String::operator== (const String& s) {
    if (cstr == NULL && s.cstr == NULL) return true;
    else if (cstr == NULL || s.cstr == NULL) return false;
    if (strlen(cstr) != strlen(s.cstr)) return false;
    if (strcmp(cstr, s.cstr) == 0) return true;
    else return false;
}

bool String::operator< (const String& s) {
    if (cstr == NULL) {
        if (s.cstr != NULL) return true;
    }
    if (s.cstr == NULL) {
        return false;
    }
    if (strcmp(cstr, s.cstr) < 0) return true;
    else return false;
}

bool String::operator> (const String& s) {
    if (cstr == NULL) {
        return false;
    }
    if (s.cstr == NULL) {
        if (cstr != NULL) return true;
    }
    if (strcmp(cstr, s.cstr) > 0) return true;
    else return false;
}

char& String::operator[] (const int& n) {
    if (n >= 0 && n <= strlen(cstr)) return cstr[n];
}

int String::size() {
    if (cstr == NULL) return 0;
    while (this->cstr[len] != '\0') len++;
    return len;
}

ostream& operator<< (ostream& out, const String& s) {
    out << s.cstr;
    return out;
}