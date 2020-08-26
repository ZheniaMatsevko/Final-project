#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <Windows.h>
using namespace std;
void CheckNumber(string temp, bool& check);
class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date() :day(0), month(0), year(0) {}
    Date(int day, int month, int year) :day(day), month(month), year(year) {}
    void comeToDate(int day, int month, int year);
    bool IsItAPreveiousDate(int day, int month, int year);
    int countTimeOfUse(Date& date);
    friend ostream& operator <<(ostream& os, const Date& p);
    friend istream& operator >>(istream& is, Date& p);
    bool operator==(const Date& other);
    void NextDay();
    void PreviosDate();
    bool IsItALeapYear();
    void MakeDate(string buffer);
    bool CheckMonth(Date& other);
    bool CheckDate();
    ~Date() {}
};

class CreditCard
{
private:
    string number;
    string Bank;
    float allcreditSum;
    float currentSum;
    float bankYearInterest;
    float bankYearInterestSum;
    Date startDate;
    Date currentDate;
    int timeOfUse;
public:
    CreditCard() : number(""), Bank(""), allcreditSum(0), currentSum(0), bankYearInterest(0), bankYearInterestSum(0), timeOfUse(0) {}
    CreditCard(Date& day) : number(""), Bank(""), allcreditSum(0), currentSum(0), bankYearInterest(0), bankYearInterestSum(0), currentDate(day), timeOfUse(0) {}
    ~CreditCard() {}
    CreditCard(const CreditCard& object);
    CreditCard& operator =(const CreditCard& object)
    {
        this->currentDate = object.currentDate;
        this->number = object.number;
        this->Bank = object.Bank;
        this->allcreditSum = object.allcreditSum;
        this->currentSum = object.currentSum;
        this->bankYearInterest = object.bankYearInterest;
        this->bankYearInterestSum = object.bankYearInterestSum;
        this->startDate = object.startDate;
        this->timeOfUse = object.timeOfUse;
        return *this;
    }
    void set_info();
    void getAllInfo();
    bool Cost(float sum);
    string getNumber();
    string getBank();
    void getLeftOver();
    void getLeftCreditSum();
    void returnCreditSum();
    friend ofstream& operator<<(ofstream& of, CreditCard& object);
    void SetInfo(ifstream& fin, string path, int& check, int& check1);
};

class DebetCard
{
private:
    string number;
    string Bank;
    float currentSum;
public:
    DebetCard() :number(""), Bank(""), currentSum(0) {}
    void set_info();
    DebetCard(const DebetCard& object);
    DebetCard& operator =(const DebetCard& object)
    {
        this->number = object.number;
        this->Bank = object.Bank;
        this->currentSum = object.currentSum;
        return *this;
    }
    void getAllInfo();
    bool Cost(float sum);
    void Profit(float sum);
    string getNumber();
    string getBank();
    void getLeftOver();
    friend ofstream& operator<<(ofstream& of, DebetCard& object);
    void SetInfo(ifstream& fin, string path, int& check, int& check1);
};

class Cash
{
private:
    float balance;
public:
    Cash() : balance(0) {}
    void setInfo();
    void getInfo();
    bool Cost(float sum);
    void Profit(float sum);
    void getLeftOver();
    Cash(const Cash& object)
    {
        this->balance = object.balance;
    }
    Cash& operator =(const Cash& object)
    {
        this->balance = object.balance;
        return *this;
    }
};

class CostCategories
{
private:
    int numberOfCategories;
    vector<string> categories;
public:
    CostCategories();
    string getInfo();
    int getNumber();
    string operator[](int index)
    {
        return this->categories[index];
    }
    ~CostCategories();
};

class Costs
{
private:
    CostCategories ctCategories;
    string category;
    string typeOfPaymentInstrument;
    float sum;
    Date currentDate;
public:
    Costs() : sum(0), category(""), typeOfPaymentInstrument("") {}
    bool AddCreditCard(CreditCard& cc, Date day);
    void writeSum();
    bool AddDebetCard(DebetCard& dc, Date day);
    bool AddCash(Cash& cash, Date day);
    bool Find(const Date& other);
    void Show();
    Costs(const Costs& object);
    Costs& operator =(const Costs& object)
    {
        this->sum = object.sum;
        this->category = object.category;
        this->typeOfPaymentInstrument = object.typeOfPaymentInstrument;
        this->currentDate = object.currentDate;
        this->ctCategories = object.ctCategories;
        return *this;
    }
    friend ofstream& operator<<(ofstream& of, Costs& object);
    void SetInfo(ifstream& fin, string path, int& check, int& check1);
    float getSum();
    string getCategory();
    int getNumberOfCategories();
    string getTypeOfPaymentInst();
    CostCategories getCategories();
};

class ProfitCategories
{
private:
    int numberOfCategories;
    vector<string> categories;
public:
    ProfitCategories();
    string getInfo();
    ~ProfitCategories();
};

class Profit
{
private:
    ProfitCategories prCategories;
    string category;
    float sum;
    Date currentDate;
    string profitInstrument;
public:
    Profit() :sum(0), profitInstrument(""), category("") {}
    void writeSum();
    void AddDebetCard(DebetCard& dc, Date day);
    void AddCash(Cash& cash, Date day);
    void Show() const;
    bool Find(const Date& day);
    Profit(const Profit& object);
    Profit& operator =(const Profit& object)
    {
        this->sum = object.sum;
        this->category = object.category;
        this->profitInstrument = object.profitInstrument;
        this->currentDate = object.currentDate;
        this->prCategories = object.prCategories;
        return *this;
    }
    friend ofstream& operator<<(ofstream& of, Profit& object);
    void SetInfo(ifstream& fin, string path, int& check, int& check1);
};

class FinanceApp
{
private:
    vector<Profit> myProfit;
    vector<Costs> myCosts;
    vector<CreditCard> myCreditCards;
    vector<DebetCard> myDebetCards;
    Cash myCash;
    Date currentDate;
public:
    FinanceApp() {}
    FinanceApp(Date& day) : currentDate(day) {}
    void UserStart();
    void MainMenu();
    void Raiting();
    void Statistics();
    void StatisticForDay(Date& day);
    void StatisticForWeek();
    void StatisticForMonth();
    void DebetCardsMenu();
    void CreditCardsMenu();
    void getLeftOver();
    void CostMenu();
    void StatisticProfitForDay(Date& day);
    void ProfitMenu();
    void SaveStatistic(string path);
    void MaxElementFile(ofstream& fout, vector<Costs>& temp);
    void MaxElement(vector<Costs>& temp);
    void MaxCategoryFile(ofstream& fout, vector<int>& statistics, CostCategories& ct);
    void MaxCategory(vector<int>& statistics, CostCategories& ct);
    void SaveRaitings(string path);
    void SaveCreditCards(string path);
    void ReadCreditCards(string path, int& check);
    void SaveDebetCards(string path);
    void ReadDebetCards(string path, int& check);
    void SaveCash(string path);
    void ReadCash(string path, int& check);
    void SaveCosts(string path);
    void ReadCosts(string path, int& check);
    void SaveProfits(string path);
    void ReadProfits(string path, int& check);
    void TopCostsForMonth();
    void TopCostsForWeek();
    void TopCostsCategoriesForWeek();
    void TopCostsCategoriesForMonth();
};

int main()
{
    setlocale(LC_CTYPE, "ukr");
    system("color 3F");
    FinanceApp myApp;
    myApp.MainMenu();
}

void CheckNumber(string temp, bool& check)
{
    string numbers = "1234567890.";
    for (int i = 0; i < temp.size(); i++)
    {
        check = false;
        for (int j = 0; j < numbers.size(); j++)
        {
            if (temp[i] == numbers[j])
            {
                check = true;
                break;
            }
        }
        if (!check)
        {
            cout << "�������.� ������ ���i ����� ���� �i���� �����\n";
            break;
        }
    }
}

ostream& operator<<(ostream& os, const Date& p)
{
    os << p.day << "." << p.month << "." << p.year << "\n";
    return os;
}

istream& operator>>(istream& is, Date& p)
{
    bool checkNumber = false;
    string buffer;
    do
    {
        cout << "����i�� ����\n";
        is >> buffer;
        CheckNumber(buffer, checkNumber);
    } while (!checkNumber);
    p.day = atoi(buffer.c_str());
    do
    {
        cout << "����i�� �i����\n";
        is >> buffer;
        CheckNumber(buffer, checkNumber);
    } while (!checkNumber);
    p.month = atoi(buffer.c_str());
    do
    {
        cout << "����i�� �i�\n";
        is >> buffer;
        CheckNumber(buffer, checkNumber);
    } while (!checkNumber);
    p.year = atoi(buffer.c_str());
    return is;
}

ofstream& operator<<(ofstream& of, CreditCard& object)
{
    of << "\n" << object.number << "\n" << object.Bank << "\n" << to_string(object.allcreditSum) << "\n" << to_string(object.currentSum) << "\n" << to_string(object.bankYearInterest) << "\n" <<
        to_string(object.bankYearInterestSum) << "\n" << object.startDate << object.currentDate << to_string(object.timeOfUse);
    return of;
}

ofstream& operator<<(ofstream& of, DebetCard& object)
{
    of << "\n" << object.number << "\n" << object.Bank << "\n" << to_string(object.currentSum);
    return of;
}

ofstream& operator<<(ofstream& of, Costs& object)
{
    of << "\n" << object.category << "\n" << object.currentDate << to_string(object.sum) << "\n" << object.typeOfPaymentInstrument;
    return of;
}

ofstream& operator<<(ofstream& of, Profit& object)
{
    of << "\n" << object.category << "\n" << object.currentDate << to_string(object.sum) << "\n" << object.profitInstrument;
    return of;
}

void Date::comeToDate(int day, int month, int year)
{
    if ((this->day == day && this->month == month && this->year == year) || IsItAPreveiousDate(day, month, year))  return;
    else
    {
        do
        {
            NextDay();
        } while (this->day != day || this->month != month || this->year != year);
    }
}

bool Date::IsItAPreveiousDate(int day, int month, int year)
{
    if (year < this->year || (month < this->month && year <= this->year) || (day < this->day && month <= this->month && year <= this->year))
    {
        cout << "�� ������ ����. �� �� ������ ��i���� i�������i� �� ��� ����\n";
        return true;
    }
    return false;
}

int Date::countTimeOfUse(Date& date)
{
    if (this->year == date.year && date.month <= this->month)  return this->month - date.month;
    if (this->year > date.year)  return 12 - date.month + 12 * (this->year - date.year - 1) + this->month;
    if (date.year > this->year || (date.month > this->month && date.year >= this->year) || (date.day > this->day && date.month >= this->month && date.year >= this->year))
    {
        cout << "�������. ������� �������� ����\n";
        return -1;
    }
}

bool Date::operator==(const Date& other)
{
    return (this->day == other.day) && (this->month == other.month) && (this->year == other.year);
}

void Date::NextDay()
{
    if (this->day < 28) this->day++;
    else
    {
        switch (this->month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (this->day < 31) this->day++;
            else
            {
                this->day = 1;
                this->month++;
            }
            break;
        case 2:
            if (IsItALeapYear() && this->day < 29) this->day++;
            else
            {
                this->day = 1;
                this->month += 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (this->day < 30) this->day++;
            else
            {
                this->day = 1;
                this->month++;
            }
            break;
        }
        if (this->month > 12)
        {
            this->month = 1;
            this->year++;
        }
    }
}

void Date::PreviosDate()
{
    if (this->day > 1) this->day--;
    else
    {
        switch (this->month)
        {
        case 1:
        case 2:
        case 4:
        case 6:
        case 9:
        case 10:
        case 12:
            this->day = 31;
            this->month--;
            break;
        case 3:
            if (IsItALeapYear()) this->day = 29;
            else this->day = 28;
            this->month--;
            break;
        case 5:
        case 7:
        case 8:
        case 11:
            this->day = 30;
            this->month--;
            break;
        }
        if (this->month < 1)
        {
            this->month = 12;
            this->year--;
        }
    }
}

bool Date::IsItALeapYear()
{
    if ((this->year % 4 == 0 && this->year % 100 != 0) || (this->year % 4 == 0 && this->year % 100 == 0 && this->year % 400 == 0)) return true;
    return false;
}

void Date::MakeDate(string buffer)
{
    this->day = atoi(buffer.c_str());
    string temp;
    temp = to_string(this->day);
    buffer.erase(0, temp.size() + 1);
    this->month = atoi(buffer.c_str());;
    temp = to_string(this->month);
    buffer.erase(0, temp.size() + 1);
    this->year = atoi(buffer.c_str());;
    temp = to_string(this->year);
}

bool Date::CheckMonth(Date& other)
{
    return this->month == other.month;
}

bool Date::CheckDate()
{
    if (this->day < 0 || this->month < 0 || this->month > 12 || this->year < 0) return false;
    switch (this->month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (this->day > 31) return false;
        break;
    case 2:
        if (IsItALeapYear() && this->day > 29) return false;
        else if (this->day > 28) return false;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (this->day > 30) return false;
        break;
    }
    return true;
}

CreditCard::CreditCard(const CreditCard& object)
{
    this->currentDate = object.currentDate;
    this->number = object.number;
    this->Bank = object.Bank;
    this->allcreditSum = object.allcreditSum;
    this->currentSum = object.currentSum;
    this->bankYearInterest = object.bankYearInterest;
    this->bankYearInterestSum = object.bankYearInterestSum;
    this->startDate = object.startDate;
    this->timeOfUse = object.timeOfUse;
}

void CreditCard::set_info()
{
    char check;
    bool DO = false, checkNumber = false;
    string tempBuf;
    do
    {
        do
        {
            cout << "����i�� ����� �������� ��������: ";
            cin >> this->number;
            CheckNumber(this->number, checkNumber);
        } while (!checkNumber);
        if (this->number.size() != 16) cout << "�������.� �����i �������� �������� �� ���� 16 ����\n";
    } while (this->number.size() != 16);
    cout << "����i�� ����� �����, ���� ��������� ���� ��������(����i������)\n";
    cin >> this->Bank;
    do
    {
        cout << "����i�� �i�� �������� ����: ";
        cin >> tempBuf;
        CheckNumber(tempBuf, checkNumber);
    } while (!checkNumber);
    this->allcreditSum = stof(tempBuf);
    do
    {
        cout << "����i�� �������� ������ ��������: ";
        cin >> tempBuf;
        CheckNumber(tempBuf, checkNumber);
    } while (!checkNumber);
    this->currentSum = stof(tempBuf);
    do
    {
        cout << "����i�� �i���� �i������, �i� ���� ����� ������: ";
        cin >> tempBuf;
        CheckNumber(tempBuf, checkNumber);
    } while (!checkNumber);
    this->bankYearInterest = stof(tempBuf);
    do
    {
        do
        {
            cout << "����i�� ���� ������ �������\n";
            cin >> this->startDate;
            system("cls");
            if (!this->startDate.CheckDate()) cout << "���� ���� �� i���.����i�� i��� ����\n\n";
        } while (!this->startDate.CheckDate());
        this->timeOfUse = this->currentDate.countTimeOfUse(this->startDate);
    } while (this->timeOfUse < 0);
    int temp5 = this->timeOfUse;
    int temp6 = 0;
    if (this->timeOfUse > 0)
    {
        do
        {
            cout << "�� ���������� �i������� �� �����i �i���i?\n1 - ���\n2 - �i\n";
            cin >> check;
            switch (check)
            {
            case '1':
                do
                {
                    do
                    {
                        cout << "�� ��i���� �i���i� �� �������� �i������?\n";
                        cin >> tempBuf;
                        CheckNumber(tempBuf, checkNumber);
                    } while (!checkNumber);
                    temp6 = atoi(tempBuf.c_str());
                    if (temp6 <= this->timeOfUse)
                    {
                        this->timeOfUse -= temp6;
                        this->bankYearInterestSum = this->bankYearInterest / 12 / 100 * this->allcreditSum * this->timeOfUse;
                    }
                    else cout << "�i���i��� ��������� �i���i� �� �i����i�� �i������i �i���i� � ������� ������ �������\n";
                } while (temp6 > temp5);
                DO = false;
                break;
            case '2':
                this->bankYearInterestSum = (this->bankYearInterest / 12 * this->timeOfUse) / 100 * this->allcreditSum;
                DO = false;
                break;
            default:
                DO = true;
                cout << "���� �����i� ����. �����i�� i���\n";
                break;
            }
        } while (DO);
    }
}

void CreditCard::getAllInfo()
{
    cout << "����� �������� ��������: " << this->number << "\n����� �����: " << this->Bank << "\n�i�� �������� ����: " << this->allcreditSum <<
        "\n�i���� �i������: " << this->bankYearInterest << "\n������� ���� �� �������: " << this->currentSum <<
        "\n�����i��� ��������� �����: " << this->allcreditSum + this->bankYearInterestSum << "\n";
}

bool CreditCard::Cost(float sum)
{
    if (this->currentSum >= sum)
    {
        this->currentSum -= sum;
        return true;
    }
    else
    {
        cout << "��������� ��i������ ������i�.�� �������i ����������� ������\n";
        return false;
    }
}

string CreditCard::getNumber()
{
    return this->number;
}

string CreditCard::getBank()
{
    return this->Bank;
}

void CreditCard::getLeftOver()
{
    cout << "�� �������i� �������i " << this->Bank << " " << this->number << " � ��� ����������: " << this->currentSum << " ���\n";
}

void CreditCard::getLeftCreditSum()
{
    cout << "��� �����i��� ��������� �����: " << this->bankYearInterestSum + this->allcreditSum << " ���\n";
}

void CreditCard::returnCreditSum()
{
    string tempBuf;
    float sum;
    char opt;
    bool checkNumber = false;
    do
    {
        cout << "�� ������ ��������� �i������ �� ������� �������� ����?\n1 - �i������\n2 - ������� �������� ����\n";
        cin >> opt;
        if (opt == '1')
        {
            do
            {
                cout << "��� ���� �� ������ ���������?\n";
                cin >> tempBuf;
                CheckNumber(tempBuf, checkNumber);
            } while (!checkNumber);
            sum = stof(tempBuf);
            if (sum <= this->bankYearInterestSum)
            {
                this->bankYearInterestSum -= sum;
                cout << "������\n";
            }
            else
            {
                do
                {
                    cout << "���� ��������. ������ �������� i ������� ������� �������� ����?\n1 - ���\n2 - �i\n";
                    cin >> opt;
                    if (opt == '1')
                    {
                        if (sum > this->allcreditSum + this->bankYearInterestSum)
                        {
                            this->bankYearInterestSum = 0;
                            this->allcreditSum = 0;
                            cout << "��������. ��� ���� ���� ��������. � ��� ���������� " << sum - this->allcreditSum - this->bankYearInterestSum << "\n";
                        }
                        else
                        {
                            this->bankYearInterestSum = 0;
                            this->allcreditSum -= (sum - this->bankYearInterestSum);
                            cout << "������\n";
                        }
                    }
                    else if (opt == '2')
                    {
                        this->bankYearInterestSum = 0;
                        cout << "��������. � ��� ���������� " << sum - this->bankYearInterestSum << "\n";
                    }
                    else cout << "���� �����i� ����. �����i�� i���\n";
                } while (opt != '1' && opt != '2');
            }
        }
        else if (opt == '2')
        {
            do
            {
                cout << "��� ���� �� ������ ���������?\n";
                cin >> tempBuf;
                CheckNumber(tempBuf, checkNumber);
            } while (!checkNumber);
            sum = stof(tempBuf);
            if (sum <= this->allcreditSum)
            {
                this->allcreditSum -= sum;
                cout << "������\n";
            }
            else
            {
                do
                {
                    cout << "���� ��������. ������ �������� i ������� �i�����i�?\n1 - ���\n2 - �i\n";
                    cin >> opt;
                    if (opt == '1')
                    {
                        if (sum > this->allcreditSum + this->bankYearInterestSum)
                        {
                            this->bankYearInterestSum = 0;
                            this->allcreditSum = 0;
                            cout << "��������. ��� ���� ���� ��������. � ��� ���������� " << sum - this->allcreditSum - this->bankYearInterestSum << "\n";
                        }
                        else
                        {
                            this->allcreditSum = 0;
                            this->bankYearInterestSum -= (sum - this->allcreditSum);
                            cout << "������\n";
                        }
                    }
                    else if (opt == '2')
                    {
                        this->allcreditSum = 0;
                        cout << "��������. � ��� ���������� " << sum - this->bankYearInterestSum << "\n";
                    }
                    else cout << "���� �����i� ����. �����i�� i���\n";
                } while (opt != '1' && opt != '2');
            }
        }
        else cout << "���� �����i� ����. �����i�� i���\n";
    } while (opt != '1' && opt != '2');
}

void CreditCard::SetInfo(ifstream& fin, string path, int& check, int& check1)
{
    string buffer;
    fin.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        if (!check1)
        {
            getline(fin, buffer);
            check1++;
        }
        getline(fin, this->number);
        getline(fin, this->Bank);
        getline(fin, buffer);
        this->allcreditSum = stof(buffer);
        getline(fin, buffer);
        this->currentSum = stof(buffer);
        getline(fin, buffer);
        this->bankYearInterest = stof(buffer);
        getline(fin, buffer);
        this->bankYearInterestSum = stof(buffer);
        getline(fin, buffer);
        this->startDate.MakeDate(buffer);
        getline(fin, buffer);
        this->currentDate.MakeDate(buffer);
        getline(fin, buffer);
        this->timeOfUse = atoi(buffer.c_str());
        check++;
    }
    catch (const exception& ex)
    {
        return;
    }
    catch (...)
    {
        fin.close();
    }
}

void DebetCard::set_info()
{
    bool checkNumber = false;
    string tempBuf;
    do
    {
        do
        {
            cout << "����i�� ����� �������� ��������: ";
            cin >> this->number;
            CheckNumber(this->number, checkNumber);
        } while (!checkNumber);
        if (this->number.size() != 16) cout << "�������.� �����i �������� �������� �� ���� 16 ����\n";
    } while (this->number.size() != 16);
    cout << "����i�� ����� �����, ���� ��������� ���� ��������(����i������)\n";
    cin >> this->Bank;
    do
    {
        cout << "����i�� �������� ������ ��������: ";
        cin >> tempBuf;
        CheckNumber(tempBuf, checkNumber);
    } while (!checkNumber);
    this->currentSum = stof(tempBuf);
}

DebetCard::DebetCard(const DebetCard& object)
{
    this->number = object.number;
    this->Bank = object.Bank;
    this->currentSum = object.currentSum;
}

void DebetCard::getAllInfo()
{
    cout << "����� ��������: " << this->number << "\n����� �����: " << this->Bank << "\n������� ���� �� �������: " << this->currentSum << "\n";
}

bool DebetCard::Cost(float sum)
{
    if (this->currentSum >= sum)
    {
        this->currentSum -= sum;
        return true;
    }
    else
    {
        cout << "��������� ��i������ ������i�.�� �������i ����������� ������\n";
        return false;
    }
}

void DebetCard::Profit(float sum)
{
    this->currentSum += sum;
}

string DebetCard::getNumber()
{
    return this->number;
}

string DebetCard::getBank()
{
    return this->Bank;
}

void DebetCard::getLeftOver()
{
    cout << "�� �������i� �������i " << this->Bank << " " << this->number << " � ��� ����������: " << this->currentSum << " ���\n";
}

void DebetCard::SetInfo(ifstream& fin, string path, int& check, int& check1)
{
    string buffer;
    fin.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        if (!check1)
        {
            getline(fin, buffer);
            check1++;
        }
        getline(fin, this->number);
        getline(fin, this->Bank);
        getline(fin, buffer);
        this->currentSum = stof(buffer);;
        check++;
    }
    catch (const exception& ex)
    {
        return;
    }
    catch (...)
    {
        fin.close();
    }
}

void Cash::setInfo()
{
    string tempBuf;
    bool checkNumber = false;
    do
    {
        cout << "����i�� ��������� ����, ��� � ��� � ���i����(���.���): ";
        cin >> tempBuf;
        CheckNumber(tempBuf, checkNumber);
    } while (!checkNumber);
    this->balance = stof(tempBuf);
}

void Cash::getInfo()
{
    cout << "������� ����: " << this->balance << "\n";
}

bool Cash::Cost(float sum)
{
    if (this->balance >= sum) this->balance -= sum;
    else
    {
        cout << "��������� ��i������ ������i�. ����������� ������\n";
        return false;
    }
}

void Cash::Profit(float sum)
{
    this->balance += sum;
}

void Cash::getLeftOver()
{
    cout << "���i���� � ��� ����������: " << this->balance << " ���\n";
}

CostCategories::CostCategories()
{
    this->numberOfCategories = 11;
    this->categories.push_back("Food");
    this->categories.push_back("Education");
    this->categories.push_back("Transport");
    this->categories.push_back("Home comfort");
    this->categories.push_back("Utility bills");
    this->categories.push_back("Entertainment");
    this->categories.push_back("Presents");
    this->categories.push_back("Clothes");
    this->categories.push_back("Internet payment");
    this->categories.push_back("Sport");
    this->categories.push_back("Other");
}

string CostCategories::getInfo()
{
    string tempBuf;
    bool checkNumber = false;
    int choose;
    do
    {
        do
        {
            checkNumber = false;
            cout << "�����i�� �������i�: \n";
            for (int i = 0; i < this->numberOfCategories; i++)
            {
                cout << i << " - " << this->categories[i] << "\n";
            }
            cin >> tempBuf;
            CheckNumber(tempBuf, checkNumber);
        } while (!checkNumber);
        choose = atoi(tempBuf.c_str());
        if (choose < 0 || choose >= this->numberOfCategories) cout << "�������i� �i� ����� ������� ����.�����i�� i���\n";
        else break;
    } while (true);
    return this->categories[choose];
}

int CostCategories::getNumber()
{
    return this->numberOfCategories;
}

CostCategories::~CostCategories()
{
    this->categories.clear();
}

bool Costs::AddCreditCard(CreditCard& cc, Date day)
{
    this->currentDate = day;
    this->category = this->ctCategories.getInfo();
    writeSum();
    if (cc.Cost(this->sum))
    {
        this->typeOfPaymentInstrument = "Credit card " + cc.getNumber();
        return true;
    }
    return false;
}

void Costs::writeSum()
{
    string tempBuf;
    bool checkNumber = false;
    do
    {
        cout << "����i�� ����(���.���): ";
        cin >> tempBuf;
        CheckNumber(tempBuf, checkNumber);
    } while (!checkNumber);
    this->sum = stof(tempBuf);
}

bool Costs::AddDebetCard(DebetCard& dc, Date day)
{
    this->currentDate = day;
    this->category = this->ctCategories.getInfo();
    writeSum();
    if (dc.Cost(this->sum))
    {
        this->typeOfPaymentInstrument = "Debet card " + dc.getNumber();
        return true;
    }
    return false;
}

bool Costs::AddCash(Cash& cash, Date day)
{
    this->currentDate = day;
    this->category = this->ctCategories.getInfo();
    writeSum();
    if (cash.Cost(this->sum))
    {
        this->typeOfPaymentInstrument = "Cash";
        return true;
    }
    return false;
}

bool Costs::Find(const Date& other)
{
    return this->currentDate == other;
}

void Costs::Show()
{
    cout << this->category << ": " << this->sum << " payed by " << this->typeOfPaymentInstrument << "\n";
}

Costs::Costs(const Costs& object)
{
    this->sum = object.sum;
    this->category = object.category;
    this->typeOfPaymentInstrument = object.typeOfPaymentInstrument;
    this->currentDate = object.currentDate;
}

void Costs::SetInfo(ifstream& fin, string path, int& check, int& check1)
{
    string buffer;
    fin.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        if (!check1)
        {
            getline(fin, buffer);
            check1++;
        }
        getline(fin, this->category);
        getline(fin, buffer);
        this->currentDate.MakeDate(buffer);
        getline(fin, buffer);
        this->sum = stof(buffer);;
        getline(fin, this->typeOfPaymentInstrument);
        check++;
    }
    catch (const exception& ex)
    {
        return;
    }
    catch (...)
    {
        fin.close();
    }
}

float Costs::getSum()
{
    return this->sum;
}

string Costs::getCategory()
{
    return this->category;
}

int Costs::getNumberOfCategories()
{
    return this->ctCategories.getNumber();
}

string Costs::getTypeOfPaymentInst()
{
    return this->typeOfPaymentInstrument;
}

CostCategories Costs::getCategories()
{
    return this->ctCategories;
}

ProfitCategories::ProfitCategories()
{
    this->numberOfCategories = 5;
    this->categories.push_back("Salary");
    this->categories.push_back("Pocket money");
    this->categories.push_back("Credit");
    this->categories.push_back("Present");
    this->categories.push_back("Other");
}

string ProfitCategories::getInfo()
{
    int choose;
    string tempBuf;
    bool checkNumber = false;
    do
    {
        do
        {
            cout << "�����i�� �������i�: \n";
            for (int i = 0; i < this->numberOfCategories; i++)
            {
                cout << i << " - " << this->categories[i] << "\n";
            }
            cin >> tempBuf;
            CheckNumber(tempBuf, checkNumber);
        } while (!checkNumber);
        choose = atoi(tempBuf.c_str());
        if (choose < 0 || choose >= this->numberOfCategories) cout << "�������i� �i� ����� ������� ����.�����i�� i���\n";
        else break;
    } while (true);
    return this->categories[choose];
}

ProfitCategories::~ProfitCategories()
{
    this->categories.clear();
}

void Profit::writeSum()
{
    string tempBuf;
    bool checkNumber = false;
    do
    {
        cout << "����i�� ����(���.���): ";
        cin >> tempBuf;
        CheckNumber(tempBuf, checkNumber);
    } while (!checkNumber);
    this->sum = stof(tempBuf);
}

void Profit::AddDebetCard(DebetCard& dc, Date day)
{
    this->currentDate = day;
    this->category = this->prCategories.getInfo();
    writeSum();
    dc.Profit(this->sum);
    this->profitInstrument = "Debet card " + dc.getNumber();
}

void Profit::AddCash(Cash& cash, Date day)
{
    this->currentDate = day;
    this->category = this->prCategories.getInfo();
    writeSum();
    cash.Profit(this->sum);
    this->profitInstrument = "Cash";
}

void Profit::Show() const
{
    cout << category << ": +" << sum << " on " << this->profitInstrument << "\n";
}

bool Profit::Find(const Date& day)
{
    return this->currentDate == day;
}

Profit::Profit(const Profit& object)
{
    this->sum = object.sum;
    this->category = object.category;
    this->profitInstrument = object.profitInstrument;
    this->currentDate = object.currentDate;
    this->prCategories = object.prCategories;
}

void Profit::SetInfo(ifstream& fin, string path, int& check, int& check1)
{
    string buffer;
    fin.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        if (!check1)
        {
            getline(fin, buffer);
            check1++;
        }
        getline(fin, this->category);
        getline(fin, buffer);
        this->currentDate.MakeDate(buffer);
        getline(fin, buffer);
        this->sum = stof(buffer);;
        getline(fin, this->profitInstrument);
        check++;
    }
    catch (const exception& ex)
    {
        return;
    }
    catch (...)
    {
        fin.close();
    }
}

void FinanceApp::UserStart()
{
    char opt;
    bool check = true;
    CreditCard temp(this->currentDate);
    DebetCard temp2;
    cout << "������i��, ���� �����, ��������� i�������i�\n";
    this->myCash.setInfo();
    do
    {
        cout << "������ ������ �������� ��� �������� ��������?\n1 - ���\n2 - �i\n";
        cin >> opt;
        switch (opt)
        {
        case '1':
            do
            {
                cout << "��� �������� �� ������ ��������?\n1 - ��������\n2 - ��������\n";
                cin >> opt;
                switch (opt)
                {
                case '1':
                    temp.set_info();
                    this->myCreditCards.push_back(temp);
                    system("cls");
                    do
                    {
                        cout << "������ �������� �� ���� ��������?\n1 - ���\n2 - �i\n";
                        cin >> opt;
                        if (opt == '1') check = true;
                        else if (opt == '2') check = false;
                        else cout << "���� �����i� ����.�����i�� i���\n";
                    } while (opt != '1' && opt != '2');
                    break;
                case '2':
                    temp2.set_info();
                    this->myDebetCards.push_back(temp2);
                    system("cls");
                    do
                    {
                        cout << "������ �������� �� ���� ��������?\n1 - ���\n2 - �i\n";
                        cin >> opt;
                        if (opt == '1') check = true;
                        else if (opt == '2') check = false;
                        else cout << "���� �����i� ����.�����i�� i���\n";
                    } while (opt != '1' && opt != '2');
                    break;
                default:
                    check = true;
                    cout << "���� �����i� ����.�����i�� i���\n";
                    break;
                }
            } while (check);
            check = false;
            break;
        case '2':
            check = false;
            break;
        default:
            check = true;
            cout << "���� �����i� ����.�����i�� i���\n";
            break;
        }
    } while (check);
    system("cls");
}

void FinanceApp::MainMenu()
{
    do
    {
        cout << "����i�� ����\n";
        cin >> this->currentDate;
        system("cls");
        if (!this->currentDate.CheckDate()) cout << "���� ���� �� i���.����i�� i��� ����\n";
    } while (!this->currentDate.CheckDate());
    int opt = 0;
    ReadCreditCards("CreditCards.txt", opt);
    ReadDebetCards("DebetCards.txt", opt);
    ReadCash("Cash.txt", opt);
    ReadCosts("Costs.txt", opt);
    ReadProfits("Profits.txt", opt);
    if (opt == 0)
    {
        UserStart();
    }
    bool check = true;
    char chOpt;
    cout << this->currentDate << "\n";
    do
    {
        cout << "�����i�� �����i�\n1 - ������� � ���� �������\n2 - ������� � ���� ��������\n3 - �i������� �������\n4 - ������� � ���� ��������� ��������\n\
5 - ������� � ���� ��������� ��������\n6 - ���������� ��������\n7 - ���������� ��i�� ������\n0 - ��������� ������\n";
        cin >> chOpt;
        switch (chOpt)
        {
        case '1':
            system("cls");
            CostMenu();
            system("cls");
            break;
        case '2':
            system("cls");
            ProfitMenu();
            system("cls");
            break;
        case '3':
            system("cls");
            getLeftOver();
            break;
        case '4':
            system("cls");
            CreditCardsMenu();
            system("cls");
            break;
        case '5':
            system("cls");
            DebetCardsMenu();
            system("cls");
            break;
        case '6':
            system("cls");
            Raiting();
            cout << "\n";
            break;
        case '7':
            system("cls");
            Statistics();
            cout << "\n";
            break;
        case '0':
            check = false;
            break;
        default:
            cout << "���� �����i� ����.�����i�� i���\n";
            break;
        }
    } while (check);
    SaveStatistic("Statistic.txt");
    SaveRaitings("Raitings.txt");
    SaveCash("Cash.txt");
    SaveCosts("Costs.txt");
    SaveCreditCards("CreditCards.txt");
    SaveDebetCards("DebetCards.txt");
    SaveProfits("Profits.txt");
}

void FinanceApp::Raiting()
{
    char opt;
    bool check = true;
    do
    {
        cout << "\n�����i�� �����i�\n1 - ��� ������ �� �������\n2 - ��� ������ �� �i����\n3 - ��� �������i� ������ �� �������\n4  - ��� �������i� ������ �� �i����\n\
0 - ����������� � ������� ����\n";
        cin >> opt;
        system("cls");
        switch (opt)
        {
        case '1':
            TopCostsForWeek();
            break;
        case '2':
            TopCostsForMonth();
            break;
        case '3':
            TopCostsCategoriesForWeek();
            break;
        case '4':
            TopCostsCategoriesForMonth();
            break;
        case '0':
            check = false;
            break;
        default:
            cout << "���� �����i� ����.�����i�� i���\n";
            break;
        }
    } while (check);
}

void FinanceApp::Statistics()
{
    char opt;
    bool check = true;
    do
    {
        cout << "\n�����i�� �����i�\n1 - ������� �� ����\n2 - ������� �� �������\n3 - ������� �� �i����\n0 - ����������� � ������� ����\n";
        cin >> opt;
        system("cls");
        switch (opt)
        {
        case '1':
            StatisticForDay(this->currentDate);
            break;
        case '2':
            StatisticForWeek();
            break;
        case '3':
            StatisticForMonth();
            break;
        case '0':
            check = false;
            break;
        default:
            cout << "���� �����i� ����.�����i�� i���\n";
            break;
        }
    } while (check);
}

void FinanceApp::StatisticForDay(Date& day)
{
    bool check = false;
    for (int i = 0; i < this->myCosts.size(); i++)
    {
        if (this->myCosts[i].Find(day))
        {
            myCosts[i].Show();
            check = true;
        }
    }
    if (!check) cout << "����\n";
}

void FinanceApp::StatisticForWeek()
{
    Date previos = this->currentDate;
    int count = 0;
    bool check = false;
    do
    {
        for (int i = 0; i < this->myCosts.size(); i++)
        {
            if (this->myCosts[i].Find(previos) && !check)
            {
                cout << "\n" << previos;
                myCosts[i].Show();
                check = true;
            }
            else if (this->myCosts[i].Find(previos)) myCosts[i].Show();
        }
        count++;
        check = false;
        previos.PreviosDate();
    } while (count < 7);
    if (!check) cout << "����\n";
}

void FinanceApp::StatisticForMonth()
{
    Date previos = this->currentDate;
    bool check = false;
    do
    {
        for (int i = 0; i < this->myCosts.size(); i++)
        {
            if (this->myCosts[i].Find(previos) && !check)
            {
                cout << "\n" << previos;
                myCosts[i].Show();
                check = true;
            }
            else if (this->myCosts[i].Find(previos)) myCosts[i].Show();
        }
        check = false;
        previos.PreviosDate();
    } while (this->currentDate.CheckMonth(previos));
    if (!check) cout << "����\n";
}

void FinanceApp::DebetCardsMenu()
{
    DebetCard temp;
    char opt;
    int num1;
    if (this->myDebetCards.empty())
    {
        do
        {
            cout << "� ��� ���� ��������� ��������\n������ ������?\n1 - ���\n2 - �i, ����������� � ������� ����\n";
            cin >> opt;
            if (opt == '1')
            {
                system("cls");
                temp.set_info();
                this->myDebetCards.push_back(temp);
                system("cls");
                cout << "������\n\n";
                break;
            }
            else if (opt == '2') return;
            else cout << "���� �����i� ����. �����i�� i���\n";
        } while (true);
    }
    string tempBuf;
    bool checkNumber = false;
    if (this->myDebetCards.size() == 1) num1 = 1;
    else
    {
        do
        {
            do
            {
                cout << "�����i�� �������� �������� ��� ������i�\n";
                for (int i = 0; i < this->myDebetCards.size(); i++)
                {
                    cout << i + 1 << " - " << this->myDebetCards[i].getBank() << " " << this->myDebetCards[i].getNumber() << "\n";
                }
                cin >> tempBuf;
                CheckNumber(tempBuf, checkNumber);
            } while (!checkNumber);
            num1 = atoi(tempBuf.c_str());
            if (num1 > 0 && num1 <= this->myDebetCards.size()) break;
            else cout << "���� �����i� ����.�����i�� i���\n";
        } while (true);
    }
    bool check = true;
    do
    {
        cout << "\n" << this->myDebetCards[num1 - 1].getBank() << " " << this->myDebetCards[num1 - 1].getNumber() << "\n\n";
        cout << "�����i�� �����i�\n1 - ������� �������\n2 - ������� ��� i�������i� ��� ��������\n0 - ����������� � ������� ����\n";
        cin >> opt;
        system("cls");
        switch (opt)
        {
        case '1':
            this->myDebetCards[num1 - 1].getLeftOver();
            break;
        case '2':
            this->myDebetCards[num1 - 1].getAllInfo();
            break;
        case '0':
            check = false;
            break;
        default:
            cout << "���� �����i� ����.�����i�� i���\n";
            break;
        }
    } while (check);
}

void FinanceApp::CreditCardsMenu()
{
    CreditCard temp(this->currentDate);
    char opt;
    int num;
    if (this->myCreditCards.empty())
    {
        do
        {
            cout << "� ��� ���� ��������� ��������\n������ ������?\n1 - ���\n2 - �i, ����������� � ������� ����\n";
            cin >> opt;
            if (opt == '1')
            {
                system("cls");
                temp.set_info();
                this->myCreditCards.push_back(temp);
                system("cls");
                cout << "������\n\n";
                break;
            }
            else if (opt == '2') return;
            else cout << "���� �����i� ����.�����i�� i���\n";
        } while (true);
    }
    string tempBuf;
    bool checkNumber = false;
    if (this->myCreditCards.size() == 1) num = 1;
    else
    {
        do
        {
            do
            {
                cout << "�����i�� �������� �������� ��� ������i�\n";
                for (int i = 0; i < this->myCreditCards.size(); i++)
                {
                    cout << i + 1 << " - " << this->myCreditCards[i].getBank() << " " << this->myCreditCards[i].getNumber() << "\n";
                }
                cin >> tempBuf;
                CheckNumber(tempBuf, checkNumber);
            } while (!checkNumber);
            num = atoi(tempBuf.c_str());
            if (num > 0 && num <= this->myCreditCards.size()) break;
            else cout << "���� �����i� ����.�����i�� i���\n";
        } while (true);
    }
    bool check = true;
    do
    {
        cout << "\n" << this->myCreditCards[num - 1].getBank() << " " << this->myCreditCards[num - 1].getNumber() << "\n\n";
        cout << "�����i�� �����i�\n1 - ������� �������\n2 - ������� ��� i�������i� ��� ��������\n3 - ������� ����, ��� �����i��� ��������� �����\n\
4 - ��������� ������� �����\n0 - ����������� � ������� ����\n";
        cin >> opt;
        system("cls");
        switch (opt)
        {
        case '1':
            this->myCreditCards[num - 1].getLeftOver();
            break;
        case '2':
            this->myCreditCards[num - 1].getAllInfo();
            break;
        case '3':
            this->myCreditCards[num - 1].getLeftCreditSum();
            break;
        case '4':
            this->myCreditCards[num - 1].returnCreditSum();
            break;
        case '0':
            check = false;
            break;
        default:
            cout << "���� �����i� ����.�����i�� i���\n";
            break;
        }
    } while (check);
}

void FinanceApp::getLeftOver()
{
    int opt;
    bool check;
    for (int i = 0; i < this->myCreditCards.size(); i++)
    {
        this->myCreditCards[i].getLeftOver();
    }
    for (int i = 0; i < this->myDebetCards.size(); i++)
    {
        this->myDebetCards[i].getLeftOver();
    }
    this->myCash.getLeftOver();
    cout << "\n";
}

void FinanceApp::CostMenu()
{
    cout << this->currentDate << "\n" << "������� �� �������i: \n";
    StatisticForDay(this->currentDate);
    Costs temp;
    Date temp3;
    bool check = false, check1 = false, checkNumber = false;
    char opt;
    int num;
    string tempBuf;
    do
    {
        cout << "�����i�� �����i�\n1 - �������� ���� �������\n2 - ������� ������� �� ����� ����\n0 - ����������� � ������� ����\n";
        cin >> opt;
        system("cls");
        switch (opt)
        {
        case '1':
            do
            {
                cout << "��� �� ������ ���������\n1 - ��������� ���������\n2 - ��������� ���������\n3 - ���i����\n";
                cin >> opt;
                switch (opt)
                {
                case '1':
                    if (!this->myCreditCards.size())
                    {
                        cout << "�������.� ��� ���� �������� ��������\n";
                        opt = '-';
                    }
                    else if (this->myCreditCards.size() == 1) check1 = temp.AddCreditCard(this->myCreditCards[0], this->currentDate);
                    else
                    {
                        do
                        {
                            do
                            {
                                cout << "�����i�� �������� �������� \n";
                                for (int i = 0; i < this->myCreditCards.size(); i++)
                                {
                                    cout << i + 1 << " - " << this->myCreditCards[i].getBank() << " " << this->myCreditCards[i].getNumber() << "\n";
                                }
                                cin >> tempBuf;
                                CheckNumber(tempBuf, checkNumber);
                            } while (!checkNumber);
                            num = atoi(tempBuf.c_str());
                            if (num > 0 && num <= this->myCreditCards.size()) break;
                            else cout << "���� �����i� ����.�����i�� i���\n";
                        } while (true);
                        check1 = temp.AddCreditCard(this->myCreditCards[num - 1], this->currentDate);
                    }
                    break;
                case '2':
                    if (!this->myDebetCards.size())
                    {
                        cout << "�������.� ��� ���� �������� ��������\n";
                        opt = '-';
                    }
                    else if (this->myDebetCards.size() == 1) check1 = temp.AddDebetCard(this->myDebetCards[0], this->currentDate);
                    else
                    {
                        do
                        {
                            do
                            {
                                cout << "�����i�� �������� ��������\n";
                                for (int i = 0; i < this->myDebetCards.size(); i++)
                                {
                                    cout << i + 1 << " - " << this->myDebetCards[i].getBank() << " " << this->myDebetCards[i].getNumber() << "\n";
                                }
                                cin >> tempBuf;
                                CheckNumber(tempBuf, checkNumber);
                            } while (!checkNumber);
                            num = atoi(tempBuf.c_str());
                            if (num > 0 && num <= this->myDebetCards.size()) break;
                            else cout << "���� �����i� ����.�����i�� i���\n";
                        } while (true);
                        check1 = temp.AddDebetCard(this->myDebetCards[num - 1], this->currentDate);
                    }
                    break;
                case '3':
                    check1 = temp.AddCash(this->myCash, this->currentDate);
                    break;
                default:
                    cout << "���� �����i� ����.�����i�� i���\n";
                    break;
                }
            } while (opt != '1' && opt != '2' && opt != '3');
            if (check1)
            {
                this->myCosts.push_back(temp);
                cout << "������\n";
            }
            check = true;
            break;
        case '2':
            cout << "����i�� ����\n";
            cin >> temp3;
            StatisticForDay(temp3);
            check = true;
            break;
        case '0':
            check = false;
            break;
        default:
            cout << "���� �����i� ����.�����i�� i���\n";
            check = true;
            break;
        }
    } while (check);
}

void FinanceApp::StatisticProfitForDay(Date& day)
{
    bool check = false;
    Date temp3;
    Profit temp;
    for (int i = 0; i < this->myProfit.size(); i++)
    {
        if (this->myProfit[i].Find(this->currentDate))
        {
            this->myProfit[i].Show();
            check = true;
        }
    }
    if (!check) cout << "����\n";
}

void FinanceApp::ProfitMenu()
{
    cout << this->currentDate << "\n" << "�������� �� �������i:\n";
    StatisticProfitForDay(this->currentDate);
    bool check = false, checkNumber = false;
    Date temp3;
    Profit temp;
    char opt;
    int num;
    string tempBuf;
    do
    {
        cout << "�����i�� �����i�\n1 - �������� ����� ��������\n2 - ������� �������� �� ����� ����\n0 - ����������� � ������� ����\n";
        cin >> opt;
        system("cls");
        switch (opt)
        {
        case '1':
            do
            {
                cout << "���� �������� ��������?\n1 - �� �������� ��������\n2 - �� ���i���\n";
                cin >> opt;
                switch (opt)
                {
                case '1':
                    if (!this->myDebetCards.size())
                    {
                        cout << "�������.� ��� ���� �������� ��������\n";
                        opt = '-';
                    }
                    else if (this->myDebetCards.size() == 1) temp.AddDebetCard(this->myDebetCards[0], this->currentDate);
                    else
                    {
                        do
                        {
                            do
                            {
                                cout << "�����i�� �������� ��������\n";
                                for (int i = 0; i < this->myDebetCards.size(); i++)
                                {
                                    cout << i + 1 << " - " << this->myDebetCards[i].getBank() << " " << this->myDebetCards[i].getNumber() << "\n";
                                }
                                cin >> tempBuf;
                                CheckNumber(tempBuf, checkNumber);
                            } while (!checkNumber);
                            num = atoi(tempBuf.c_str());
                            if (num > 0 && num <= this->myDebetCards.size()) break;
                            else cout << "���� �����i� ����.�����i�� i���\n";
                        } while (true);
                        temp.AddDebetCard(this->myDebetCards[num - 1], this->currentDate);
                    }
                    break;
                case '2':
                    temp.AddCash(this->myCash, this->currentDate);
                    break;
                default:
                    cout << "���� �����i� ����.�����i�� i���\n";
                    break;
                }
            } while (opt != '1' && opt != '2' && opt != '3');
            this->myProfit.push_back(temp);
            cout << "������\n";
            check = true;
            break;
        case '2':
            cout << "����i�� ����\n";
            cin >> temp3;
            StatisticProfitForDay(temp3);
            check = true;
            break;
        case '0':
            check = false;
            break;
        default:
            cout << "���� �����i� ����.�����i�� i���\n";
            check = true;
            break;
        }
    } while (check);
}

void FinanceApp::SaveStatistic(string path)
{
    ofstream fout;
    fout.exceptions(ofstream::badbit | ofstream::failbit);
    try
    {
        fout.open(path, ofstream::trunc | ofstream::out);
        Costs temp;
        Date previos = this->currentDate;
        bool check = false;
        do
        {
            for (int i = 0; i < this->myCosts.size(); i++)
            {
                if (this->myCosts[i].Find(previos) && !check)
                {
                    fout << "\n" << previos;
                    temp = myCosts[i];
                    fout << temp.getCategory() << ": " << temp.getSum() << " payed by " << temp.getTypeOfPaymentInst() << "\n";
                    check = true;
                }
                else if (this->myCosts[i].Find(previos))
                {
                    temp = myCosts[i];
                    fout << temp.getCategory() << ": " << temp.getSum() << " payed by " << temp.getTypeOfPaymentInst() << "\n";
                }
            }
            check = false;
            previos.PreviosDate();
        } while (this->currentDate.CheckMonth(previos));
        fout.close();
    }
    catch (const exception& ex)
    {
        cout << ex.what() << "\n";
    }
    catch (...)
    {
        fout.close();
    }
}

void FinanceApp::MaxElementFile(ofstream& fout, vector<Costs>& temp)
{
    vector<Costs>::iterator it = max_element(temp.begin(), temp.end(), [](Costs& one, Costs& two) {return one.getSum() < two.getSum(); });
    fout << it->getCategory() << ": " << it->getSum() << " payed by " << it->getTypeOfPaymentInst() << "\n";
    temp.erase(it);
}

void FinanceApp::MaxElement(vector<Costs>& temp)
{
    vector<Costs>::iterator it = max_element(temp.begin(), temp.end(), [](Costs& one, Costs& two) {return one.getSum() < two.getSum(); });
    it->Show();
    temp.erase(it);
}

void FinanceApp::MaxCategoryFile(ofstream& fout, vector<int>& statistics, CostCategories& ct)
{
    vector<int>::iterator it = max_element(statistics.begin(), statistics.end());
    for (int i = 0; i < statistics.size(); i++)
    {
        if (statistics[i] == *it)
        {
            fout << ct[i] << " - " << *it << " costs\n";
            break;
        }
    }
    *it = 0;
}

void FinanceApp::MaxCategory(vector<int>& statistics, CostCategories& ct)
{
    vector<int>::iterator it = max_element(statistics.begin(), statistics.end());
    for (int i = 0; i < statistics.size(); i++)
    {
        if (statistics[i] == *it)
        {
            cout << ct[i] << " - " << *it << " costs\n";
            break;
        }
    }
    *it = 0;
}

void FinanceApp::SaveRaitings(string path)
{
    ofstream fout;
    fout.exceptions(ofstream::badbit | ofstream::failbit);
    try
    {
        fout.open(path, ofstream::trunc | ofstream::out);
        Date previos = this->currentDate;
        vector<Costs> temp;
        Costs temp1;
        do
        {
            for (int i = 0; i < this->myCosts.size(); i++)
            {
                if (this->myCosts[i].Find(previos))
                {
                    temp1 = this->myCosts[i];
                    temp.push_back(temp1);
                }
            }
            previos.PreviosDate();
        } while (this->currentDate.CheckMonth(previos));
        fout << "Top costs for month\n";
        if (temp.size() > 0 && temp.size() < 4)
        {
            for (int i = 0; i < temp.size(); i++)
            {
                fout << temp[i].getCategory() << ": " << temp[i].getSum() << " payed by " << temp[i].getTypeOfPaymentInst() << "\n";
            }
        }
        else if (temp.empty()) fout << "Nothing\n";
        else
        {
            MaxElementFile(fout, temp);
            MaxElementFile(fout, temp);
            MaxElementFile(fout, temp);
        }
        previos = this->currentDate;
        temp.clear();
        do
        {
            for (int i = 0; i < this->myCosts.size(); i++)
            {
                if (this->myCosts[i].Find(previos))
                {
                    temp1 = this->myCosts[i];
                    temp.push_back(temp1);
                }
            }
            previos.PreviosDate();
        } while (this->currentDate.CheckMonth(previos));
        fout << "\nTop categories for month\n";
        if (temp.size() > 0 && temp.size() < 4)
        {
            for (int i = 0; i < temp.size(); i++)
            {
                fout << temp[i].getCategory() << ": " << temp[i].getSum() << " payed by " << temp[i].getTypeOfPaymentInst() << "\n";
            }
        }
        else if (temp.empty()) fout << "Nothing\n";
        else
        {
            vector<int> statistics;
            CostCategories ct;
            string tempstr;
            for (int i = 0; i < ct.getNumber(); i++)
            {
                tempstr = ct[i];
                statistics.push_back(count_if(temp.begin(), temp.end(), [tempstr](Costs& one) {return (one.getCategory() == tempstr); }));
            }
            MaxCategoryFile(fout, statistics, ct);
            MaxCategoryFile(fout, statistics, ct);
            MaxCategoryFile(fout, statistics, ct);
        }
        fout.close();
    }
    catch (const exception& ex)
    {
        cout << ex.what() << "\n";
    }
    catch (...)
    {
        fout.close();
    }
}

void FinanceApp::SaveCreditCards(string path)
{
    if (this->myCreditCards.empty()) return;
    ofstream fout;
    fout.exceptions(ofstream::badbit | ofstream::failbit);
    try
    {
        fout.open(path, ofstream::trunc | ofstream::out);
        CreditCard temp;
        for (int i = 0; i < this->myCreditCards.size(); i++)
        {
            temp = this->myCreditCards[i];
            fout << temp;
        }
        fout.close();
    }
    catch (const exception& ex)
    {
        cout << ex.what() << "\n";
    }
    catch (...)
    {
        fout.close();
    }
}

void FinanceApp::ReadCreditCards(string path, int& check)
{
    ifstream fin;
    CreditCard temp;
    int check1 = 0;
    try
    {
        fin.open(path, ifstream::in);
        while (!fin.eof())
        {
            temp.SetInfo(fin, path, check, check1);
            this->myCreditCards.push_back(temp);
        }
        fin.close();
    }
    catch (const exception& ex)
    {
        return;
    }
    catch (...)
    {
        fin.close();
    }
}

void FinanceApp::SaveDebetCards(string path)
{
    if (this->myDebetCards.empty()) return;
    ofstream fout;
    fout.exceptions(ofstream::badbit | ofstream::failbit);
    try
    {
        fout.open(path, ofstream::trunc | ofstream::out);
        DebetCard temp;
        for (int i = 0; i < this->myDebetCards.size(); i++)
        {
            temp = this->myDebetCards[i];
            fout << temp;
        }
        fout.close();
    }
    catch (const exception& ex)
    {
        cout << ex.what() << "\n";
    }
    catch (...)
    {
        fout.close();
    }
}

void FinanceApp::ReadDebetCards(string path, int& check)
{
    ifstream fin;
    DebetCard temp;
    int check1 = 0;
    try
    {
        fin.open(path, ifstream::in);
        while (!fin.eof())
        {
            temp.SetInfo(fin, path, check, check1);
            this->myDebetCards.push_back(temp);
        }
        fin.close();
    }
    catch (const exception& ex)
    {
        return;
    }
    catch (...)
    {
        fin.close();
    }
}

void FinanceApp::SaveCash(string path)
{
    ofstream fout;
    fout.exceptions(ofstream::badbit | ofstream::failbit);
    try
    {
        fout.open(path, ofstream::binary | ofstream::out);
        Cash temp(this->myCash);
        fout.write((char*)&temp, sizeof(Cash));
        fout.close();
    }
    catch (const exception& ex)
    {
        cout << ex.what() << "\n";
    }
    catch (...)
    {
        fout.close();
    }
}

void FinanceApp::ReadCash(string path, int& check)
{
    ifstream fin;
    fin.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        fin.open(path, ifstream::binary | ifstream::in);
        Cash temp;
        fin.read((char*)&temp, sizeof(Cash));
        this->myCash = temp;
        fin.close();
        check++;
    }
    catch (const exception& ex)
    {
        return;
    }
    catch (...)
    {
        fin.close();
    }
}

void FinanceApp::SaveCosts(string path)
{
    if (this->myCosts.empty()) return;
    ofstream fout;
    fout.exceptions(ofstream::badbit | ofstream::failbit);
    try
    {
        fout.open(path, ofstream::trunc | ofstream::out);
        Costs temp;
        for (int i = 0; i < this->myCosts.size(); i++)
        {
            temp = this->myCosts[i];
            fout << temp;
        }
        fout.close();
    }
    catch (const exception& ex)
    {
        cout << ex.what() << "\n";
    }
    catch (...)
    {
        fout.close();
    }
}

void FinanceApp::ReadCosts(string path, int& check)
{
    ifstream fin;
    Costs temp;
    int check1 = 0;
    try
    {
        fin.open(path, ifstream::in);
        while (!fin.eof())
        {
            temp.SetInfo(fin, path, check, check1);
            this->myCosts.push_back(temp);
        }
        fin.close();
    }
    catch (const exception& ex)
    {
        return;
    }
    catch (...)
    {
        fin.close();
    }
}

void FinanceApp::SaveProfits(string path)
{
    if (this->myProfit.empty()) return;
    ofstream fout;
    fout.exceptions(ofstream::badbit | ofstream::failbit);
    try
    {
        fout.open(path, ofstream::trunc | ofstream::out);
        Profit temp;
        for (int i = 0; i < this->myProfit.size(); i++)
        {
            temp = this->myProfit[i];
            fout << temp;
        }
        fout.close();
    }
    catch (const exception& ex)
    {
        cout << ex.what() << "\n";
    }
    catch (...)
    {
        fout.close();
    }
}

void FinanceApp::ReadProfits(string path, int& check)
{
    ifstream fin;
    Profit temp;
    int check1 = 0;
    try
    {
        fin.open(path, ifstream::in);
        while (!fin.eof())
        {
            temp.SetInfo(fin, path, check, check1);
            this->myProfit.push_back(temp);
        }
        fin.close();
    }
    catch (const exception& ex)
    {
        return;
    }
    catch (...)
    {
        fin.close();
    }
}

void FinanceApp::TopCostsForMonth()
{
    Date previos = this->currentDate;
    vector<Costs> temp;
    Costs temp1;
    do
    {
        for (int i = 0; i < this->myCosts.size(); i++)
        {
            if (this->myCosts[i].Find(previos))
            {
                temp1 = this->myCosts[i];
                temp.push_back(temp1);
            }
        }
        previos.PreviosDate();
    } while (this->currentDate.CheckMonth(previos));
    if (temp.size() > 0 && temp.size() < 4)
    {
        cout << "������ �� ��� �i���� � �i���� " << temp.size() << "\n";
        for (int i = 0; i < temp.size(); i++)
        {
            temp[i].Show();
        }
        return;
    }
    if (temp.empty())
    {
        cout << "������ �� ��� �i���� ����\n";
        return;
    }
    cout << "��� ������ �� �i����\n";
    MaxElement(temp);
    MaxElement(temp);
    MaxElement(temp);
}

void FinanceApp::TopCostsForWeek()
{
    Date previos = this->currentDate;
    vector<Costs> temp;
    Costs temp1;
    int count = 0;
    do
    {
        for (int i = 0; i < this->myCosts.size(); i++)
        {
            if (this->myCosts[i].Find(previos))
            {
                temp1 = this->myCosts[i];
                temp.push_back(temp1);
            }
        }
        count++;
        previos.PreviosDate();
    } while (count < 7);
    if (temp.size() > 0 && temp.size() < 4)
    {
        cout << "������ �� ��� ������� � �i���� " << temp.size() << "\n";
        for (int i = 0; i < temp.size(); i++)
        {
            temp[i].Show();
        }
        return;
    }
    if (temp.empty())
    {
        cout << "������ �� ��� ������� ����\n";
        return;
    }
    cout << "��� ������ �� �������\n";
    MaxElement(temp);
    MaxElement(temp);
    MaxElement(temp);
}

void FinanceApp::TopCostsCategoriesForWeek()
{
    Date previos = this->currentDate;
    vector<Costs> temp;
    Costs temp1;
    int count = 0;
    do
    {
        for (int i = 0; i < this->myCosts.size(); i++)
        {
            if (this->myCosts[i].Find(previos))
            {
                temp1 = this->myCosts[i];
                temp.push_back(temp1);
            }
        }
        count++;
        previos.PreviosDate();
    } while (count < 7);
    if (temp.size() > 0 && temp.size() < 4)
    {
        cout << "������ �� ��� ������� � �i���� " << temp.size() << "\n";
        for (int i = 0; i < temp.size(); i++)
        {
            temp[i].Show();
        }
        return;
    }
    if (temp.empty())
    {
        cout << "������ �� ��� ������� ����\n";
        return;
    }
    vector<int> statistics;
    CostCategories ct;
    string tempstr;
    for (int i = 0; i < ct.getNumber(); i++)
    {
        tempstr = ct[i];
        statistics.push_back(count_if(temp.begin(), temp.end(), [tempstr](Costs& one) {return (one.getCategory() == tempstr); }));
    }
    cout << "��� �������i� ������ �� �������\n";
    MaxCategory(statistics, ct);
    MaxCategory(statistics, ct);
    MaxCategory(statistics, ct);
}

void FinanceApp::TopCostsCategoriesForMonth()
{
    Date previos = this->currentDate;
    vector<Costs> temp;
    Costs temp1;
    do
    {
        for (int i = 0; i < this->myCosts.size(); i++)
        {
            if (this->myCosts[i].Find(previos))
            {
                temp1 = this->myCosts[i];
                temp.push_back(temp1);
            }
        }
        previos.PreviosDate();
    } while (this->currentDate.CheckMonth(previos));
    if (temp.size() > 0 && temp.size() < 4)
    {
        cout << "������ �� ��� �i���� � �i���� " << temp.size() << "\n";
        for (int i = 0; i < temp.size(); i++)
        {
            temp[i].Show();
        }
        return;
    }
    if (temp.empty())
    {
        cout << "������ �� ��� �i���� ����\n";
        return;
    }
    vector<int> statistics;
    CostCategories ct;
    string tempstr;
    for (int i = 0; i < ct.getNumber(); i++)
    {
        tempstr = ct[i];
        statistics.push_back(count_if(temp.begin(), temp.end(), [tempstr](Costs& one) {return (one.getCategory() == tempstr); }));
    }
    cout << "��� �������i� ������ �� �i����\n";
    MaxCategory(statistics, ct);
    MaxCategory(statistics, ct);
    MaxCategory(statistics, ct);
}