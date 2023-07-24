/* Photon Cannon */
/*
#include <iostream>
#include <string.h>

class Photon_Cannon{
    int hp, shield;
    int damage;
    int coord_x, coord_y;

    public:
     Photon_Cannon(int x, int y);
     Photon_Cannon(const Photon_Cannon& pc);    // Copy Constructor
     // standard definition of Copy Constructor
     // class T{...T(const T& a);...};
     // 즉 다른 T 의 객체 a 를 const references 로 받는 다는 것

     void show_status();
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc){
    std::cout << "복사 생성자 호출 !" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
    // pc.coord_x = 3;  const reference 로 인자를 받았기 때문에 불가능 !
}
Photon_Cannon::Photon_Cannon(int x, int y){
    std::cout << "생성자 호출" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}

void Photon_Cannon::show_status(){
    std::cout << "*** Photon Cannon ***" << std::endl;
    std::cout << "Location : ( " << coord_x << ", " << coord_y << " )" << std::endl;
    std::cout << "HP: " << hp << std::endl;
}

int main(){
    Photon_Cannon pc1(3, 3);
    Photon_Cannon pc2(pc1);
    Photon_Cannon pc3 = pc2;    
    // 이 문장은 Photon_Cannon pc3(pc2); 와 동일한 문장이며 똑같이 복사 생성자를 호출한다.
    // 만약 pc3 = pc2; 를 했다면 이는 평범한 대입연산자이다.

    pc1.show_status();
    pc2.show_status();

    return 0;
}

// 놀랍게도 C++ compiler 는 Default Copy Constructor 또한 지원하고 있다. 
// 따라서 위 코드에서 copy constructor 를 지우고 실행해도 이전과 정확히 동일한 결과를 출력한다.
*/
/* Default Copy Constructor's limitation */
/*
#include <iostream>
#include <string.h>

class Photon_Cannon{
    int hp, shield;
    int damage;
    int coord_x, coord_y;

    char *name;     // 이름 추가

    public:
     Photon_Cannon(int x, int y);
     Photon_Cannon(int x, int y, const char *cannon_name);
     ~Photon_Cannon();   

     void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y){
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}
Photon_Cannon::Photon_Cannon(int x, int y, const char*cannon_name){
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);      // name 문자열에 cannon_name 문자열을 복사
}
Photon_Cannon::~Photon_Cannon(){
    if(name)    delete[] name;
}
void Photon_Cannon::show_status(){
    std::cout << "*** Photon Cannon " << name << " ***" << std::endl;
    std::cout << "Location : ( " << coord_x << ", " << coord_y << " )" << std::endl;
    std::cout << "HP: " << hp << std::endl;
}

int main(){
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2 = pc1;

    pc1.show_status();
    pc2.show_status();

    return 0;
}
*/
// 위 코드를 실행해보면 런타임 오류가 발생한다.
// 왜 그럴까? Default copy constructor 는 다음과 같이 정의되었을 것이다.
/*
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc){
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
    name = pc.name;
}
*/
// hp, shield,... 그리고 name 까지 모두 같은 값을 가지게 된다.
// name 이 같다면, 즉 두 개의 포인터가 같은 값을 가진다는 것은 같은 주소값을 가리킨다는 말이된다.
// 즉, 우리는 pc1 의 name 이 동적으로 할당받아서 가리키고 있던 메모리를 
// pc2 의 name 도 같이 가리키게 되는 것이다.

// 물론 이 상태에서는 별 문제가 없다.

// 하지만 main() 함수가 종료되기 직전에 생성되었던 객체들은 파괴되면서 
// destructor 를 호출할 때 문제가 발생한다.

// 만약 pc1 이 먼저 파괴되었다고 해보자
// 소멸자는 pc1 의 내용을 모두 파괴 함과 동시에 주소에 할당한 메모리까지 delete 하게 된다.
// 문제는 pc2 의 name 이 해제된 메모리의 주소를 가리키고 있다.

// 따라서 pc2 의 destructor 가 호출되면 name 이 NULL 이 아니므로 delete[] name; 이 수행되는데
// 이미 해제된 메모리에 접근해서 다시 해제하려고 했기 때문에 런타임 오류가 발생한 것이다.

// 해결방법
#include <iostream>
#include <string.h>

class Photon_Cannon{
    int hp, shield;
    int damage;
    int coord_x, coord_y;

    char *name;     // 이름 추가

    public:
     Photon_Cannon(int x, int y);
     Photon_Cannon(int x, int y, const char *cannon_name);
     Photon_Cannon(const Photon_Cannon &pc);
     ~Photon_Cannon();   

     void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y){
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char*cannon_name){
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);      
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc){
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
    // name = pc.name 처럼 내용을 바로 복사하는 얕은복사(shallow copy)가 아니라
    // 메모리를 새로 할당해서 내용을 복사하는 깊은 복사(deep copy)를 이용한다.
    // 따라서 객체 pc1 을 만들고 copy constructor 를 이용하여 객체 pc2 에 복사했다면,
    // pc1.name 과 pc2.name 은 서로 다른 주소값을 가리킨다.
}

Photon_Cannon::~Photon_Cannon(){
    if(name)    delete[] name;
}
void Photon_Cannon::show_status(){
    std::cout << "*** Photon Cannon " << name << " ***" << std::endl;
    std::cout << "Location : ( " << coord_x << ", " << coord_y << " )" << std::endl;
    std::cout << "HP: " << hp << std::endl;
}

int main(){
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2 = pc1;

    pc1.show_status();
    pc2.show_status();

    return 0;
}