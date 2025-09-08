#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// TODO: Define the Rectangle struct according to README
 struct Rectangle {
  double width;
  double height;
  double thickness;
  double density;
  double mass;
  string material;
 };

void print_plate(int index, double width, double height,
                 double density, double mass, const char* material) {
    cout << "Plate[" << index << "]: "
         << "width=" << width << ", "
         << "height=" << height << ", "
         << "density=" << density << ", "
         << "mass=" << mass << ", "
         << "material=" << material << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    int num_plates;
    input >> num_plates;
    input.ignore(); // skip newline after number

    const int MAX_PLATES = 10;
    if (num_plates > MAX_PLATES) {
    cerr << "Number of plates exceeds maximum allowed (" << MAX_PLATES << endl;
     return 1;
     }

    // TODO: Create an array of Rectangle
    Rectangle plates[MAX_PLATES];

    // TODO: Read plate data from input
    for (int i = 0; i < num_plates; i++) {
    input >> plates[i].width;
    input >> plates[i].height;
    input >> plates[i].thickness;
    input >> plates[i].density;
    input.ignore();
    getline(input, plates[i].material); 
    }

    // TODO: Compute mass for each plate and call print_plate
     for (int i = 0; i < num_plates; i++) {
      plates[i].mass = plates[i].width * plates[i].height * plates[i].thickness * plates[i].density;
      print_plate(i, plates[i].width, plates[i].height, plates[i].density, plates[i].mass, plates[i].material.c_str());
      
    }

    return 0;
}
