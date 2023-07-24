/* 수학 관련 소프트웨어를 만드는 회사에서 의뢰가 들어왔습니다. 중학생용 기하학 소프트웨워를 만드는 것인데요, 
클래스는 총 두 개로 하나는 Point 로 점에 관한 정보를 담는 것이고 
다른 하나는 Geometry 로 점들을 가지고 연산을 하는 클래스 입니다. 
즉 아래와 같은 두 클래스의 함수들을 모두 정의하세요 */
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

  // 모든 점들 간의 거리를 출력하는 함수 입니다.
  void PrintDistance();

  // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
  // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
  // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
  // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
  void PrintNumMeets();
  
  // 두 직선이 만나는지 확인하는 함수
  bool IsDivided(Point *point1, Point *point2, Point *point3, Point *point4);
private:
  // 점 100 개를 보관하는 배열.
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
    std::cout << "모든 점들을 잇는 직선의 교점의 개수는 " << num_meet << "개 이다." << std::endl;
}