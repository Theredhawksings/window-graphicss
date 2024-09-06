#include <iostream>
#include <deque>  // std::deque 사용
using namespace std;

struct Point {
    int x;
    int y;
    int z;
};

void add_point(deque<Point>& points, int x, int y, int z) {
    points.push_front({ x, y, z });  // 맨 위에 추가
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
    points.push_back({ x, y, z });  // 맨 아래에 추가
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

void print_count(deque<Point>& points) {
    cout << points.size() << endl;
}

void remove_all_point(deque<Point>& points) {
    while (!points.empty()) {
        points.pop_front();
    }
}

int main() {
    deque<Point> points;

    string command;

    while (1) {
        cout << "명령어 입력     ";
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
            print_count(points);
        }

        else if (command == "c") {
            remove_all_point(points);
        }
    }

    return 0;
}