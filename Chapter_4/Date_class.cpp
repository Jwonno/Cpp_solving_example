#include <iostream>

class Date{
    int year_;
    int month_;
    int day_;

    public:
        void SetDate(int year, int month, int day);
        void AddDay(int inc);
        void AddMonth(int inc);
        void AddYear(int inc);

        int GetCurrentMonthTotalDays(int year, int month);

        void ShowDate();

        // Constructor: 객체 생성시 자동으로 호출되는 함수
        // 객체를 초기화 하는 역할을 하기 때문에 리턴값이 없다.
        Date(int year, int month, int day){
            year_ = year;
            month_ = month;
            day_ = day;
        }
};

void Date::SetDate(int year, int month, int day){       // Date:: 는 Date 클래스에 정의된 함수라는 뜻
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month){
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month != 2){
        return month_day[month-1];
    } else if(year % 4 == 0 && year % 100 != 0){
       return 29;   //윤년 
    } else {
        return 28;
    }
}

void Date::AddDay(int inc){
    while(true){
        int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

        if(day_+inc <= current_month_total_days){
            day_ += inc;
            break;
        } else {
            inc -= (current_month_total_days - day_ + 1);
            day_ = 1;
            AddMonth(1);
        }
    }
}

void Date::AddMonth(int inc){
    AddYear((inc + month_ - 1)/12);
    month_ = month_ + inc % 12;
    month_ = (month_== 12 ? 12 : month_ % 12);      // 삼항 연산자 (조건식 ? 반환값1 : 반환값2)
}

void Date::AddYear(int inc) { year_ += inc;}

void Date::ShowDate(){
    std::cout << "오늘은 " << year_ << "년 " << month_ << "월 " << day_ << "일 입니다."
    << std::endl;
}

int main(){
    // Date date(2011, 2, 1);           암시적 방법(implicit)  Date(int year, int month, int day) 를 호출한다.
    // Date day = Date(2012, 3, 1);     명시적 방법(explicit)
    Date date;                       // 생성자를 정의하지 않으면 디폴트 생성자(Default Constructor)가 호출된다.
    // Date date = Date();              이렇게 명시적 방법으로 디폴트 생성자를 호출할 수도 있다. 
    // 주의해야 할 것은 Date date(); 라고 하면 
    // 디폴트 생성자를 이용해서 초기화하는 것이 아니라, 
    // 리턴값이 Date 이고 인자가 없는 '함수' date 를 정의한 것
    date.SetDate(2011, 3, 1);
    date.ShowDate();

    date.AddDay(30);
    date.ShowDate();

    date.AddDay(2000);
    date.ShowDate();

    date.SetDate(2012, 1, 31);      // 윤년
    date.AddDay(29);
    date.ShowDate();

    return 0;
}

/* 명시적으로 디폴트 생성자 사용하기 */
class Test {
    public:
        Test() = default;   // 디폴트 생성자를 정의
};

/* 생성자 오버로딩 */
class Test2 {
    int a;
    int b;
    public:
        Test2(){
            a = 1;
            b = 2;
        }
        Test2(int a_, int b_){
            a = a_;
            b = b_;
        }
};
// 위와 같이 생성자도 오버로딩이 가능하다.