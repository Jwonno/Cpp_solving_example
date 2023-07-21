/* 여러분은 아래와 같은 Date 클래스를 디자인 하려고 합니다. 
SetDate 는 말그대로 Date 함수 내부를 초기화 하는 것이고 
AddDay, AddMonth, AddYear 는 일, 월, 년을 원하는 만큼 더하게 됩니다. 
한 가지 주의할 점은 만일 2012 년 2 월 28 일에 3 일을 더하면 
2012 년 2 월 31 일이 되는 것이 아니라 2012 년 3 월 2 일이 되겠지요? */

#include <iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date){
    year_ = year;
    month_ = month;
    day_ = date;
  }
  
  void AddDay(int inc){
    int day = day_+inc;
    if(month_==2){
        if(day>28){
                day_ = day-28;
                month_+=1;
            }
            else day_ = day;
    }
    else if(month_<=7){
        if(month_%2==0){
            if(day>30){
                day_ = day-30;
                month_+=1;
            }
            else day_ = day;
        }
        else{
            if(day>31){
                day_ = day - 31;
                month_ += 1;
            }
            else day_ = day;
        }
    }
    else{
         if(month_%2==0){
            if(day>31){
                day_ = day-31;
                month_+=1;
            }
            else day_ = day;
        }
        else{
            if(day>30){
                day_ = day - 30;
                month_ += 1;
            }
            else day_ = day;
        }
    }
    if(month_==13){
        month_ = 1;
        year_ += 1;
    }
  }
  void AddMonth(int inc){
    int month = month_ + inc;
    month_ = month%12;
    year_ += month/12;
  }
  void AddYear(int inc){
    year_ += inc;
  }

  void ShowDate(){
    std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
  }
};

int main(){
    Date date;
    date.SetDate(2023, 12, 21);
    date.ShowDate();
    
    date.AddMonth(3);
    std::cout << "3 months later..." << std::endl;
    date.ShowDate();

    date.AddDay(11);
    std::cout << "11 days later...." << std::endl;
    date.ShowDate();

    date.AddYear(2);
    std::cout << "2 years later..." << std::endl;
    date.ShowDate();
    
    return 0;
}