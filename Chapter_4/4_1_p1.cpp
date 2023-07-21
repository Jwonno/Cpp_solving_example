/* �������� �Ʒ��� ���� Date Ŭ������ ������ �Ϸ��� �մϴ�. 
SetDate �� ���״�� Date �Լ� ���θ� �ʱ�ȭ �ϴ� ���̰� 
AddDay, AddMonth, AddYear �� ��, ��, ���� ���ϴ� ��ŭ ���ϰ� �˴ϴ�. 
�� ���� ������ ���� ���� 2012 �� 2 �� 28 �Ͽ� 3 ���� ���ϸ� 
2012 �� 2 �� 31 ���� �Ǵ� ���� �ƴ϶� 2012 �� 3 �� 2 ���� �ǰ�����? */

#include <iostream>

class Date {
  int year_;
  int month_;  // 1 ���� 12 ����.
  int day_;    // 1 ���� 31 ����.

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
    std::cout << year_ << "�� " << month_ << "�� " << day_ << "��" << std::endl;
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