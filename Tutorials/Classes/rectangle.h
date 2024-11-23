class Rectangle {
private:
    double length;
    double width;

public:
    // Construtores
    Rectangle();
    Rectangle(double side); // Construtor para quadrado
    Rectangle(double l, double w);

    // Métodos
    double getArea() const;
    double getPerimeter() const;
};

// Implementação dos métodos
Rectangle::Rectangle() : length(0), width(0) {}

Rectangle::Rectangle(double side) : length(side), width(side) {}

Rectangle::Rectangle(double l, double w) : length(l), width(w) {}

double Rectangle::getArea() const {
    return length * width;
}

double Rectangle::getPerimeter() const {
    return 2 * (length + width);
}