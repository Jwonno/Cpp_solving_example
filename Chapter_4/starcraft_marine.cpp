#include <iostream>
#include <string.h>

class Marine{
    // static 멤버 변수의 사용
    static int total_marine_num;

    int hp;                     // 마린의 체력
    int coord_x, coord_y;       // 마린의 위치
    // int damage;                 // 공격력
    bool is_dead;
    // char *name;                  // 마린의 이름        

    const int default_damage;   // 기본 공격력

    public:
     Marine();                  // default constructor
     Marine(int x, int y);      // 좌표 (x, y) 에 마린 생성
    //  Marine(int x, int y, const char *marine_name); // 마린 이름까지 지정
     Marine(int x, int y, int default_damage);  // 기본 공격력까지 지정   

     int attack();                       // 데미지를 리턴한다.
     // void be_attacked(int damage_earn);  // 받는 데미지
     Marine& be_attacked(int damage_earn);  // 받는 데미지(레퍼런스를 리턴)
     void move(int x, int y);            // 새로운 위치

     void show_status();                 // 상태를 보여준다.

     static void ShowTotalMarineNum();   // 총 마린의 수를 보여준다.

     ~Marine(){ total_marine_num--;};                 // Destructor 
     // 소멸자는 생성자처럼 class 의 이름을 쓰는데, 앞에 ~ 만 붙여주면된다.
     // 소멸자는 인자를 받지 않기 때문에 overloading 되지도 않는다.
};

// static 멤버 변수의 초기화
int Marine::total_marine_num = 0;

// static 멤버 함수의 정의
void Marine::ShowTotalMarineNum(){
    std::cout << "전체 마린 수: " << total_marine_num << std::endl;
}
// Marine::Marine(){
//     hp = 50;
//     coord_x = coord_y = 0;
//     damage = 5;
//     is_dead = false;
//     name = NULL;
// }

// Marine::Marine(int x, int y){
//     coord_x = x;
//     coord_y = y;
//     hp = 50;
//     damage =5;
//     is_dead = false;
//     name = NULL;
// }

// 초기화 리스트(initializer list) 를 이용
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false){
        total_marine_num++;
    }

Marine::Marine(int x, int y)
    : hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false){
        total_marine_num++;
    }
Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(5),
      is_dead(false) {
        total_marine_num++;
      }

// Marine::Marine(int x, int y, const char* marine_name)
//     : default_damage(5){
//     name = new char[strlen(marine_name) + 1];
//     strcpy(name, marine_name);
//     coord_x = x;
//     coord_y = y;
//     hp = 50;
//     is_dead = false;
//     total_marine_num++;
// }


void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}

int Marine::attack(){return default_damage;}
// void Marine::be_attacked(int damage_earn){
Marine& Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if(hp < 0)  is_dead = true;

    // 객체자신을 가리키는 포인터 this
    return *this;
}

void Marine::show_status(){
    // std::cout << "*** Marine " << name << " ***" << std::endl;
    std::cout << " Location: { "<< coord_x << ", " << coord_y << " }" << std::endl;
    std::cout << "HP: " << hp << std::endl;
   // std::cout << "현재 총 마린 수: " << total_marine_num << std::endl;
}

// Marine::~Marine() {
//     std::cout << name << "의 소멸자 호출 ! " << std::endl;
//     if(name != NULL){
//         delete[] name;
//     }
// }

int main(){
   /* Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << " 마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
    */
    // 배열을 이용하여 마린들을 생성
    // Marine *marine[100];

    // marine[0] = new Marine(2, 3, "Tom");       // new 는 객체를 동적으로 생성하면서 동시에 자동으로 생성자도 호출한다.
    // marine[1] = new Marine(3, 5, "James");

    // marine[0]->show_status();
    // marine[1]->show_status();

    // std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;

    // marine[0]->be_attacked(marine[1]->attack());

    // marine[0]->show_status();
    // marine[1]->show_status();

    // delete marine[0];
    // delete marine[1];
    // 객체가 위와 같이 소멸될 때 destructor(~Marine(){...}) 가 호출된다.

    Marine marine3(2, 3, 10);
    Marine marine4(3, 5, 10);

    // (클래스)::(static 함수) 형태로 호출한다. 
    Marine::ShowTotalMarineNum();

    marine3.show_status();
    marine4.show_status();

    std::cout << std::endl << "마린 3 이 마린 4 를 두 번 공격!" << std::endl;
    marine4.be_attacked(marine3.attack()).be_attacked(marine3.attack());

    marine3.show_status();
    marine4.show_status();
    return 0;
}