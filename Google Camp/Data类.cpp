#include <string>
#include <iostream>
using namespace std;
class Date {
private:
    int year, month, day, i, flag;
    bool pass;
    //检查是否为yyyy:mm:dd格式，yyyy一定是四位数字，mm和dd一定为两位数字，:为英文的冒号
    bool checkFormat(const string & dataStr) {
        for (i = 0; i < 4; i++)
            if (dataStr[i] > '9' || dataStr[i] < '0') return false;
        if (dataStr[4] != ':') return false;
        for (i = 5; i < 7; i++)
            if (dataStr[i] > '9' || dataStr[i] < '0') return false;
        if (dataStr[7] != ':') return false;
        for (i = 8; i < 10; i++) 
            if (dataStr[i] > '9' || dataStr[i] < '0') return false;
        return true;
    }
    //检验日期是否合法，并设置pass的值
    //不合法日期：2011:02:29；2001:00:00；2001:13:30；2012:12:40
    //合法日期：2012:12:04；2001:09:01
    void validate() {
        pass = true;
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) flag = 1;
        else flag = 0;
        if (month > 12 || month < 1) pass = false;
        if (day < 1) pass = false;
        switch(month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day > 31) pass = false;
            break;
        case 2:
            if (flag && day > 29) pass = false;
            if (!flag && day > 28) pass = false;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30) pass = false;
            break;
        }
        return;
    }
public:
    Date();
    Date(int y, int m = 2, int d = 29);
    Date(const Date& otherDate);
    Date(const string& dataStr);
    //如果日期格式为yyyy:mm:dd正确，则设置日期并验证其是否为合法的日期
    //否则不做任何事情
    void setDate(const string & dataStr);
    //如果日期合法，输出year年month月day日，这里无需前面补零，例如：2012年1月13日
    //不合法，输出：Illegal date
    //有换行！
    void printData();
};

int main() {
    Date d1("2012:03:27"), d2("abcd:dd:ss"), d3, d4(2012);
    Date d5(d1);
	d1.printData();
	d2.printData();
	d3.printData();
	d4.printData();
}

Date::Date() {
    year = 2006;
    month = 1;
    day = 1;
}

Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
    validate();
}

Date::Date(const Date& otherDate) {
    year = otherDate.year;
    month = otherDate.month;
    day = otherDate.day;
    validate();
}

Date::Date(const string& dataStr) {
    if (checkFormat(dataStr)) {
        Date::setDate(dataStr);
        Date::validate();
    } else pass = false;
}

void Date::setDate(const string& dataStr) {
    year = 1000 * (dataStr[0] - '0') + 100 * (dataStr[1] - '0') + 10 * (dataStr[2] - '0') + (dataStr[3] - '0');
    month = 10 * (dataStr[5] - '0') + (dataStr[6] - '0');
    day = 10 * (dataStr[8] - '0') + (dataStr[9] - '0');
    return;
}

void Date::printData() {
    if (pass) {
        cout << year << "年" << month << "月" << day << "日";
    } else {
        cout << "Illegal date";
    }
    cout << endl;
}
