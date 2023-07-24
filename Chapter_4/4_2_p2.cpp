/* ���� ���� ����Ʈ��� ����� ȸ�翡�� �Ƿڰ� ���Խ��ϴ�. ���л��� ������ ����Ʈ������ ����� ���ε���, 
Ŭ������ �� �� ���� �ϳ��� Point �� ���� ���� ������ ��� ���̰� 
�ٸ� �ϳ��� Geometry �� ������ ������ ������ �ϴ� Ŭ���� �Դϴ�. 
�� �Ʒ��� ���� �� Ŭ������ �Լ����� ��� �����ϼ��� */
#include<iostream>
#include <cmath>
class Point {
  int x, y;

 public:
  Point(int pos_x, int pos_y){
    x = pos_x;
    y = pos_y;
  }
};

class Geometry {
 public:
  Geometry() {
    num_points = 0;
  }

  void AddPoint(const Point &point) {
    point_array[num_points ++] = new Point(point.x, point.y);
  }

  // ��� ���� ���� �Ÿ��� ����ϴ� �Լ� �Դϴ�.
  void PrintDistance();

  // ��� ������ �մ� ������ ���� ������ ���� ������ִ� �Լ� �Դϴ�.
  // ���������� ������ �� ���� �մ� ������ �������� f(x,y) = ax+by+c = 0
  // �̶�� �� �� ������ �ٸ� �� �� (x1, y1) �� (x2, y2) �� f(x,y)=0 �� ��������
  // ���� �ٸ� �κп� ���� ������ f(x1, y1) * f(x2, y2) <= 0 �̸� �˴ϴ�.
  void PrintNumMeets();
  
  // �� ������ �������� Ȯ���ϴ� �Լ�
  bool IsDivided(Point *point1, Point *point2, Point *point3, Point *point4);
private:
  // �� 100 ���� �����ϴ� �迭.
  Point* point_array[100];
  int num_points;
};

void Geometry::PrintDistance(){
    int x1, x2, y1, y2;
    double d;
    for(int i=0; i<num_points; i++){
        for(int j=0; j<i; j++){
            x1 = point_array[i]->x;
            x2 = point_array[j]->x;
            y1 = point_array[i]->y;
            y2 = point_array[j]->y;
            d = sqrt(pow(x1-x2, 2) + pow(y1 - y2, 2));
            std::cout << "Distance of " << i+1 << "th point " << "and " << j+1 << "th point: " << d << std::endl;
        }
    }
}

bool IsDivided(Point &point1, Point &point2, Point &point3, Point &point4){
    int m1 = (point2->y - point1->y) * (point4->x - point3->x);
    int m2 = (point4->y - point3->y) * (point2->x - point1->x);
    if(m1==m2) return 0;
    else return 1;
 }

void Geometry::PrintNumMeets(){
    int x1, x2, y1, y2;
    int num_meet = 0;
    for(int i=0; i<num_points; i++){
        for(int j=0; j<i; j++){
            for(int k=0;k<j;k++){
                for(int l=0; l<k; l++){
                    num_meet+=IsDivided(point_array[i], point_array[j], point_array[k], point_array[l]);
                }
            }
        }
    }
    std::cout << "��� ������ �մ� ������ ������ ������ " << num_meet << "�� �̴�." << std::endl;
}