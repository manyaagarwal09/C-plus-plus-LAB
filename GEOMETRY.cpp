#include <iostream>
using namespace std;

class Shape {
private:
    float radius;
    float length;
    float width;

public:
    // Constructor for Circle
    Shape(float r) {
        radius = r;
        cout << "Circle Constructor called" << endl;
    }

    // Constructor for Rectangle
    Shape(float l, float w) {
        length = l;
        width = w;
        cout << "Rectangle Constructor called" << endl;
    }

    // Destructor
    ~Shape() {
        cout << "Destructor Called" << endl;
    }

    // Member function to calculate Circle perimeter
    float circlePerimeter() {
        return 2 * 3.14159 * radius;
    }

    // Member function to calculate Rectangle perimeter
    float rectanglePerimeter() {
        return 2 * (length + width);
    }
};

int main() {
    float r, l, w;

    // Circle calculation
    cout << "Enter radius of circle: ";
    cin >> r;
    Shape circle(r);
    cout << "Perimeter of Circle = " << circle.circlePerimeter() << endl;

    // Rectangle calculation
    cout << "\nEnter length of rectangle: ";
    cin >> l;
    cout << "Enter breadth: ";
    cin >> w;
    Shape rectangle(l, w);
    cout << "Perimeter of rectangle = " << rectangle.rectanglePerimeter() << endl;

    return 0;
}
```[cite: 7, 8]

---

### Corrections applied from the handwritten version:

* **Object and Identifier Casing:** In the handwritten code, objects were instantiated as capitalized names (`Shape Circle(r);` and `Shape Rectangle(l, w);`)[cite: 8], but then invoked using lowercase names (`circle.circlePerimeter()` and `rectangle.rectanglePerimeter()`)[cite: 8]. In C++, identifiers are case-sensitive. The instances are standardized to lowercase `circle` and `rectangle` to match their method calls[cite: 8].
* **Placement of Destructor:** In Image 8, `~Shape()` was placed after the class definition block began to close[cite: 8]. It has been placed neatly inside the `public:` section of `class Shape` before the closing `};`[cite: 7, 8].
* **Newline Cleanups:** Fixed minor spacing/newline formatting (`\nEnter breadth: ` instead of the awkward duplicate `\n` outputs)[cite: 8].
