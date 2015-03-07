#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char *cstr;
    int len;
public:
    //ͨ��char����ָ������ʼ��String������ƣ��㶮��

    String();

    String(const char* str);

    //�������캯��
    String(const String& s);

    ~String();

    //�ַ���ƴ�ӣ����磺"abc" + "def" �����"abcdef"
    String operator+ (const String& s);

    //=�Ÿ�ֵ���ǵÿ������캯����=�Ų��~
    String& operator= (const String& s);

    //���������ǱȽϲ����������ڱȽ��ַ������ֵ���
    bool operator== (const String& s);
    bool operator< (const String& s);
    bool operator> (const String& s);

    //ȡ���ַ����ĵ�nλ
    //String str("abc");str[0]Ϊa��str[1]Ϊb��
    //�мǴ˻���ע�⵱�ϱߵ�str�����¸�ֵ��str[1] = '\0'ʱ��strʵ�������ַ���"a"������Ϊ1����Ϊ�ַ�������\0������
    char& operator[] (const int& n);

    //��ȡ�ַ����ĳ���
    int size();

    //������� �ǵ�ĩβ�ǲ���Ҫ���еģ�
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