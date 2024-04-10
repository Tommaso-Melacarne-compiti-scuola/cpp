#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
  double x;
  double y;
} Point;

typedef struct {
  vector<Point> points;
} Shape;

Shape createShape(vector<Point> points) {
  Shape s;
  s.points = points;
  return s;
}

Point createPoint(double x, double y) {
  Point p;
  p.x = x;
  p.y = y;
  return p;
}

enum ShapeType {
  TRIANGLE = 1,
  RECTANGLE = 2,
  SQUARE = 3,
  CIRCLE = 4,
  UNKNOWN = 0
};

ShapeType getShapeType(Shape shape) {
  if (shape.points.size() == 3) {
    return ShapeType::TRIANGLE;
  }

  if (shape.points.size() == 2) {
    return ShapeType::CIRCLE;
  }

  if (shape.points.size() == 4) {
    double x1 = shape.points[0].x;
    double x2 = shape.points[1].x;
    double x3 = shape.points[2].x;
    double x4 = shape.points[3].x;
    double y1 = shape.points[0].y;
    double y2 = shape.points[1].y;
    double y3 = shape.points[2].y;
    double y4 = shape.points[3].y;
    if (x1 == x2 && x2 == x3 && x3 == x4 && y1 == y2 && y2 == y3 && y3 == y4) {
      return ShapeType::SQUARE;
    } else {
      return ShapeType::RECTANGLE;
    }
  }

  return ShapeType::UNKNOWN;
}

double distanceBetweenPoints(Point p1, Point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

double circlePerimeter(Shape shape) {
  return 2 * M_PI * distanceBetweenPoints(shape.points[0], shape.points[1]);
}

// Perimeter of any shape, doesn't fail
double perimeter(Shape shape, ShapeType type) {
  if (type == ShapeType::CIRCLE) {
    return circlePerimeter(shape);
  }

  double p = 0;
  for (int i = 0; i < shape.points.size(); i++) {
    p += distanceBetweenPoints(shape.points[i],
                               shape.points[(i + 1) % shape.points.size()]);
  }
  return p;
}

double circleArea(Shape shape) {
  return M_PI * distanceBetweenPoints(shape.points[0], shape.points[1]) *
         distanceBetweenPoints(shape.points[0], shape.points[1]);
}

double triangleArea(Shape shape, double perimeter) {
  double semiPerimeter = perimeter / 2.f;

  double t = semiPerimeter;
  for (int i = 0; i < shape.points.size(); i++) {
    t *= semiPerimeter -
         distanceBetweenPoints(shape.points[i],
                               shape.points[(i + 1) % shape.points.size()]);
  }

  return sqrt(t);
}

double rectangleArea(Shape shape) {
  return distanceBetweenPoints(shape.points[0], shape.points[1]) *
         distanceBetweenPoints(shape.points[1], shape.points[2]);
}

double squareArea(Shape shape) {
  return distanceBetweenPoints(shape.points[0], shape.points[1]) * 2;
}

// Area of any shape, returns -1 if the shape is unknown
double area(Shape shape, ShapeType type, double perimeter) {
  switch (type) {
  case ShapeType::CIRCLE:
    return circleArea(shape);
  case ShapeType::RECTANGLE:
    return rectangleArea(shape);
  case ShapeType::SQUARE:
    return squareArea(shape);
  case ShapeType::TRIANGLE:
    return triangleArea(shape, perimeter);
  default:
    return -1;
  }
}

int getNumberOfPointsUser() {
  do {
    int n;
    cout << "Inserisci il numero di punti"
            "\n(se è un cerchio, inserisci due punti, uno è il centro, l'altro "
            "uno qualsiasi sulla circonferenza): ";
    cin >> n;
    if (n < 2 || n > 4) {
      cout << "Numero di punti non valido" << endl;
      continue;
    }
    return n;
  } while (true);
}

Shape getPoints() {
  int n = getNumberOfPointsUser();
  vector<Point> points;
  for (int i = 0; i < n; i++) {
    double x, y;
    cout << "Inserisci la coordinata x del punto " << i << ": ";
    cin >> x;
    cout << "Inserisci la coordinata y del punto " << i << ": ";
    cin >> y;
    points.push_back(createPoint(x, y));
  }
  return createShape(points);
}

void printArea(double a) {
  if (a == -1) {
    cout << "Area non calcolabile" << endl;
    return;
  }
  cout << "Area: " << a << endl;
}

void printResults(double perimeter, double area) {
  cout << "Perimetro: " << perimeter << endl;
  printArea(area);
}

int main() {
  Shape shape = getPoints();
  ShapeType type = getShapeType(shape);
  double p = perimeter(shape, type);
  double a = area(shape, type, p);
  printResults(p, a);
}
