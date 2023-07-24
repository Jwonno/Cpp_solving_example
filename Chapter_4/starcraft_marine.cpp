#include <iostream>
#include <string.h>

class Marine{
    int hp;                     // ������ ü��
    int coord_x, coord_y;       // ������ ��ġ
    int damage;                 // ���ݷ�
    bool is_dead;
    char *name;                  // ������ �̸�        

    public:
     Marine();                  // default constructor
     Marine(int x, int y);      // ��ǥ (x, y) �� ���� ����
     Marine(int x, int y, const char *marine_name); // ���� �̸����� ����
     ~Marine();                 // Destructor 
     // �Ҹ��ڴ� ������ó�� class �� �̸��� ���µ�, �տ� ~ �� �ٿ��ָ�ȴ�.
     // �Ҹ��ڴ� ���ڸ� ���� �ʱ� ������ overloading ������ �ʴ´�.

     int attack();                      // �������� �����Ѵ�.
     void be_attacked(int damage_earn);  // �޴� ������
     void move(int x, int y);           // ���ο� ��ġ

     void show_status();                // ���¸� �����ش�.
};

Marine::Marine(){
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y){
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage =5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name){
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}

int Marine::attack(){return damage;}
void Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if(hp < 0)  is_dead = true;
}

void Marine::show_status(){
    std::cout << "*** Marine " << name << " ***" << std::endl;
    std::cout << " Location: { "<< coord_x << ", " << coord_y << " }" << std::endl;
    std::cout << "HP: " << hp << std::endl;
}

Marine::~Marine() {
    std::cout << name << "�� �Ҹ��� ȣ�� ! " << std::endl;
    if(name != NULL){
        delete[] name;
    }
}

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
    Marine *marine[100];

    marine[0] = new Marine(2, 3, "Tom");       // new �� ��ü�� �������� �����ϸ鼭 ���ÿ� �ڵ����� �����ڵ� ȣ���Ѵ�.
    marine[1] = new Marine(3, 5, "James");

    marine[0]->show_status();
    marine[1]->show_status();

    std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;

    marine[0]->be_attacked(marine[1]->attack());

    marine[0]->show_status();
    marine[1]->show_status();

    delete marine[0];
    delete marine[1];
    // ��ü�� ���� ���� �Ҹ�� �� destructor(~Marine(){...}) �� ȣ��ȴ�.
    return 0;
}