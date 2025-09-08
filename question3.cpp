#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// TODO: Define Point struct if not given
struct Point {
  double x;
  double y;
};
Point rotate_point(const Point& p, const Point& pivot, double theta) {
    Point rotated;
    rotated.x = pivot.x + (p.x - pivot.x) * cos(theta) - (p.y - pivot.y) * sin(theta);
    rotated.y = pivot.y + (p.x - pivot.x) * sin(theta) - (p.y - pivot.y) * cos(theta);
    if (fabs(rotated.x) < 1e-6) {
    rotated.x = 0;
    }
    return rotated;
    }

void print_point_rotation(double x_before, double y_before,
                          double theta, double x_after, double y_after) {
    cout << "Before rotation: (x=" << x_before << ", y=" << y_before << ")\n";
    cout << "After rotation (θ=" << theta << " rad): "
         << "(x=" << x_after << ", y=" << y_after << ")\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" <<endl;;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    // TODO: Declare point, pivot, and angle variables
    double x, y, theta, px, py;
    input >> x >> y >> theta >> px >> py;
    
    Point p = {x, y};
    Point pivot = {px, py};
    Point rotated = rotate_point(p, pivot, theta);
    
    print_point_rotation(p.x, p.y, theta, rotated.x, rotated.y);
    
   
  
    return 0;
}


    // TODO: Compute rotated coordinates around pivot


    // TODO: Print rotated point


    return 0;
}
