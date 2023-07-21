/* 동물 관리 프로그램 */
#include <iostream>

// previous version
/*
typedef struct Animal {
    char name[30];  // 이름
    int age;        // 나이     
    int health;     // 건강 상태(%)
    int food;       // 배부름정도(%)
    int clean;       // 청결상태(%)
} Animal;

// 새로운 동물 생성
void create_animal(Animal *animal){             
    std::cout << "Enter the name of animal: ";
    std::cin >> animal->name;

    std::cout << "Enter the age of animal: ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal){
    animal->health -= 10;
    animal->food -= 20;
    animal->clean -= 30;
}

// 하루가 지나면
void one_day_pass(Animal *animal){
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -=20;
}

void show_stat(Animal *animal){
    std::cout << animal->name << "의 상태" << std::endl;
    std::cout << "체력: " << animal->health << std::endl;
    std::cout << "배부름: " << animal->food << std::endl;
    std::cout << "청결도: " << animal->clean << std::endl;
}

int main(){
    Animal *list[10];
    int animal_num = 0;

    for(;;){
        std::cout << "1. 동물 추가하기" << std::endl;
        std::cout << "2. 동물 놀아주기" << std::endl;
        std::cout << "3. 상태 보기" << std::endl;

        int input;
        std::cin >> input;

        switch(input){
            int play_with;
            case 1:
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);
                animal_num++;
                break;
            
            case 2:
                std::cout << "누구랑 놀까?: ";
                std::cin >> play_with;
                if(play_with < animal_num)  play(list[play_with]);
                break;
            
            case 3:
                std::cout << "누구의 상태를 볼까?: ";
                std::cin >> play_with;
                if(play_with < animal_num)  show_stat(list[play_with]);
                break;
        }
        for (int i = 0; i != animal_num; i++){
            one_day_pass(list[i]);
        }
    }
    for (int i = 0; i != animal_num; i++){
        delete list[i];
    }
    return 0;
}
*/

// current version(with class)

class Animal{
    private:            // 외부에서 접근 불가 ex) animal.food = 20; 이라는 문장은 오류가 발생함
        int food;
        int weight;

    public:             // 외부에서 접근 가능(공개) ex) aniaml.increase_food(20); 이라는 문장이 가능
        void set_animal(int _food, int _weight) {
            food = _food;
            weight = _weight;
        }
        void increase_food(int inc){
            food += inc;
            weight +=(inc/3);
        }
        void view_stat(){
            std::cout << "이 동물의 배부름: " << food << std::endl;
            std::cout << "이 동물의 무게: " << weight << std::endl;
        }
        // 만약 private 과 public 둘다 명시하지 않았다면, private 으로 자동 설정됨
};      // don't forget semicolon

int main(){
    Animal animal;
    animal.set_animal(100, 50);      // food: 100, weight: 50
    animal.increase_food(30);

    animal.view_stat();
    return 0;
}
