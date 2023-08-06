#include <iostream>
#include <string.h>

class Marine{
    // static ��� ������ ���
    static int total_marine_num;

    int hp;                     // ������ ü��
    int coord_x, coord_y;       // ������ ��ġ
    // int damage;                 // ���ݷ�
    bool is_dead;
    // char *name;                  // ������ �̸�        

    const int default_damage;   // �⺻ ���ݷ�

    public:
     Marine();                  // default constructor
     Marine(int x, int y);      // ��ǥ (x, y) �� ���� ����
    //  Marine(int x, int y, const char *marine_name); // ���� �̸����� ����
     Marine(int x, int y, int default_damage);  // �⺻ ���ݷ±��� ����   

     int attack();                       // �������� �����Ѵ�.
     // void be_attacked(int damage_earn);  // �޴� ������
     Marine& be_attacked(int damage_earn);  // �޴� ������(���۷����� ����)
     void move(int x, int y);            // ���ο� ��ġ

     void show_status();                 // ���¸� �����ش�.

     static void ShowTotalMarineNum();   // �� ������ ���� �����ش�.

     ~Marine(){ total_marine_num--;};                 // Destructor 
     // �Ҹ��ڴ� ������ó�� class �� �̸��� ���µ�, �տ� ~ �� �ٿ��ָ�ȴ�.
     // �Ҹ��ڴ� ���ڸ� ���� �ʱ� ������ overloading ������ �ʴ´�.
};

// static ��� ������ �ʱ�ȭ
int Marine::total_marine_num = 0;

// static ��� �Լ��� ����
void Marine::ShowTotalMarineNum(){
    std::cout << "��ü ���� ��: " << total_marine_num << std::endl;
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

// �ʱ�ȭ ����Ʈ(initializer list) �� �̿�
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

    // ��ü�ڽ��� ����Ű�� ������ this
    return *this;
}

void Marine::show_status(){
    // std::cout << "*** Marine " << name << " ***" << std::endl;
    std::cout << " Location: { "<< coord_x << ", " << coord_y << " }" << std::endl;
    std::cout << "HP: " << hp << std::endl;
   // std::cout << "���� �� ���� ��: " << total_marine_num << std::endl;
}

// Marine::~Marine() {
//     std::cout << name << "�� �Ҹ��� ȣ�� ! " << std::endl;
//     if(name != NULL){
//         delete[] name;
//     }
// }

int main(){
   /* Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << " ���� 1 �� ���� 2 �� ����! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
    */
    // �迭�� �̿��Ͽ� �������� ����
    // Marine *marine[100];

    // marine[0] = new Marine(2, 3, "Tom");       // new �� ��ü�� �������� �����ϸ鼭 ���ÿ� �ڵ����� �����ڵ� ȣ���Ѵ�.
    // marine[1] = new Marine(3, 5, "James");

    // marine[0]->show_status();
    // marine[1]->show_status();

    // std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;

    // marine[0]->be_attacked(marine[1]->attack());

    // marine[0]->show_status();
    // marine[1]->show_status();

    // delete marine[0];
    // delete marine[1];
    // ��ü�� ���� ���� �Ҹ�� �� destructor(~Marine(){...}) �� ȣ��ȴ�.

    Marine marine3(2, 3, 10);
    Marine marine4(3, 5, 10);

    // (Ŭ����)::(static �Լ�) ���·� ȣ���Ѵ�. 
    Marine::ShowTotalMarineNum();

    marine3.show_status();
    marine4.show_status();

    std::cout << std::endl << "���� 3 �� ���� 4 �� �� �� ����!" << std::endl;
    marine4.be_attacked(marine3.attack()).be_attacked(marine3.attack());

    marine3.show_status();
    marine4.show_status();
    return 0;
}