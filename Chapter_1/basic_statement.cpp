#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
    /*//������ ����
    int i;
    char c;
    double d;
    float f;

    //�������� ����
    int arr[10];
    int *parr = arr;

    int j;
    int *pj = &j;

    //for ��
    int sum = 0;
    for(int i=0;i<10;i++){
        std::cout << i << std::endl;
        sum+=i;
    }
    std::cout <<"sum is: "<< sum << std::endl;

    //while ��
    int sum2=0;
    while(i<=10){
        sum2+=i;
        i++;
    }
    std::cout <<"sum2 is: "<< sum2 << std::endl;*/

    /*//if-else ������ �̿��� ���� ���߱� ����
    int lucky_number = 3;
    std::cout << "Try guessing the lucky number"<<std::endl;
    
    int user_input;

    while(1){
        std::cout <<"Insert the number(0~9): ";
        std::cin >> user_input;
        if(lucky_number==user_input){
            std::cout<<"congratulation!! you got it!!"<<std::endl;
            break;
        } else{
            std::cout<<"Try again..."<<std::endl;
        }
    }*/
    
    //switch �� �̿��ϱ�
    int user_input;
    cout <<"My information"<< endl;
    cout <<"1. Name "<< endl;
    cout <<"2. Age "<< endl;
    cout <<"3. Gender "<< endl;

    cin >> user_input;

    switch(user_input){
        case 1:
        cout << "Won_ho" << endl;
        break;

        case 2:
        cout << "22" << endl;
        break;

        case 3:
        cout << "Male" << endl;
        break;

        default:
        cout << "Invalid number" << endl;
        break;
    }
    return 0;
}
//C�� C++�� �⺻���� ���� ������ �����ϴ�.