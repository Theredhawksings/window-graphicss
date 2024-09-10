#include <iostream>
#include <deque> 
#include <algorithm> 
using namespace std;
struct Point {
    int x;
    int y;
    int z;
};
bool as = true;
void add_point(deque<Point>& points, int x, int y, int z) {
    points.push_front({ x, y, z });
}
void remove_point_front(deque<Point>& points) {
    if (!points.empty()) {
        points.pop_front();
    }
    else {
        cout << "리스트가 비어 있습니다.\n";
    }
}
void add_point_end(deque<Point>& points, int x, int y, int z) {
    points.push_back({ x, y, z }); 
}
void print_points(const deque<Point>& points) {
    for (const auto& point : points) {
        cout << point.x << ", " << point.y << ", " << point.z << endl;
    }
}
void remove_point_end(deque<Point>& points) {
    if (!points.empty()) {
        points.pop_back();
    }
    else {
        cout << "리스트가 비어 있습니다.\n";
    }
}
void print_size(deque<Point>& points) {
    cout << points.size() << endl;
}
void remove_all_point(deque<Point>& points) {
    while (!points.empty()) {
        points.pop_front();
    }
}

void print_farthest_point(deque<Point>& points) {

    Point* farthestPoint = &points[0];
    int max = points[0].x * points[0].x + points[0].y * points[0].y + points[0].z * points[0].z;

    for (Point& p : points) {
        int dis = p.x * p.x + p.y * p.y + p.z * p.z;
        if (dis > max) {
            max = dis;
            farthestPoint = &p;
        }
    }

    cout << farthestPoint->x << ", " << farthestPoint->y << ", " << farthestPoint->z << endl;
}

void print_closest_point(deque<Point>& points) {

    Point* closestPoint = &points[0];
    int min= points[0].x * points[0].x + points[0].y * points[0].y + points[0].z * points[0].z;

    for (Point& p : points) {
        int dis = p.x * p.x + p.y * p.y + p.z * p.z;
        if (dis < min) {
            min = dis;
            closestPoint = &p;
        }
    }

    cout << closestPoint->x << ", " << closestPoint->y << ", " << closestPoint->z << endl;
}

bool compareAscending(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.z < b.z;
}

bool compareDescending(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x > b.x;
    if (a.y != b.y) return a.y > b.y;
    return a.z > b.z;
}

void print_sorted_ascending(const deque<Point>& points) {
    deque<Point> pointss = points;
    sort(pointss.begin(), pointss.end(), compareAscending);
    cout << "오름차순 정렬:\n";
    print_points(pointss);
}

void print_sorted_descending(const deque<Point>& points) {
    deque<Point> pointss = points;
    sort(pointss.begin(), pointss.end(), compareDescending);
    cout << "내림차순 정렬:\n";
    print_points(pointss);
}
int main() {
    deque<Point> points;
    string command;
    points.push_front({ 1, 1, 0 });
    points.push_front({ 1, 0, 0 });
    points.push_front({ 1, 1, 1 });
    

    while (1) {
        cout << endl << endl;
        print_points(points);
        cout << "명령어 입력     " << endl << endl;
        cin >> command;



        if (command == "+") {
            int x, y, z;
            cin >> x >> y >> z;
            add_point(points, x, y, z);
        }
        else if (command == "-") {
            remove_point_front(points);
        }
        else if (command == "q") {
            break;
        }
        else if (command == "d") {
            remove_point_end(points);
        }
        else if (command == "e") {
            int x, y, z;
            cin >> x >> y >> z;
            add_point_end(points, x, y, z);
        }
        else if (command == "l") {
            print_size(points);
        }
        else if (command == "c") {
            remove_all_point(points);
        }
        else if (command == "m") {
            print_farthest_point(points);
        }
        else if (command == "n") {
            print_closest_point(points);
        }
        else if (command == "a") {
            if (as == true) {
                print_sorted_ascending(points);
            }
            else  if (as == false) {
                print_points(points);
            }

            as = !as;
        }
        else if (command == "s") {
            if (as == true) {
                print_sorted_descending(points);
            }
            else  if (as == false) {
                print_points(points);
            }
            as = !as;
        }
    }
    return 0;
}