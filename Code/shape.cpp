#include "shape.h"

#include <string>

using namespace std;

/* Shape */
Shape::Shape() {
    // default constructor. set private members x and y to zero.
    this->x = 0;
    this->y = 0;
}

Shape::Shape(int x, int y) {
    // parametrized constructor. set private members x and y to value of parameters x and y.
    this->x = x;
    this->y = y;
}

Shape::~Shape() {
    // destructor. free all allocated memory.
}

Shape* Shape::copy() {
    // return a new shape with the current x and y values
    return new Shape(this->x, this->y);
}

int Shape::getX() const {
    return this->x;
}

int Shape::getY() const {
    return this->y;
}

void Shape::setX(int x) {
    this->x = x;
}

void Shape::setY(int y) {
    this->y = y;
}

string Shape::as_string() const {
    return "It's a Shape at x: " + to_string(this->x) + ", y: " + to_string(this->y);
}


/* Circle */
Circle::Circle() {
    // default constructor. set private members x and y to zero.
    this->radius = 0;
}

Circle::Circle(int r) {
    // parametrized constructor. set private members x and y to value of parameters x and y.
    this->radius = r;
}

Circle::Circle(int x, int y, int r) {
    // parametrized constructor. set private members x and y to value of parameters x and y.
    this->radius = r;
    this->x = x;
    this->y = y;
}

Circle::~Circle() {
    // destructor. free all allocated memory.
}

Circle* Circle::copy() {
    // return a new shape with the current x, y, and r values
    return new Circle(this->x, this->y, this->radius);
}

int Circle::getRadius() const {
    return this->radius;
}

void Circle::setRadius(int r) {
    this->radius = r;
}

string Circle::as_string() const {
    return "It's a Circle at x: " + to_string(this->x) + ", y: " + to_string(this->y) + ", radius: " + to_string(this->radius);
}


/* Rectangle */
Rect::Rect() {
    // default constructor. set private members width and height to zero.
    this->width = 0;
    this->height = 0;
}

Rect::Rect(int w, int h) {
    // parametrized constructor. set private members x and y to value of parameters x and y.
    this->width = w;
    this->height = h;
}

Rect::Rect(int x, int y, int w, int h) {
    // parametrized constructor. set private members x and y to value of parameters x and y.
    this->width = w;
    this->height = h;
    this->x = x;
    this->y = y;
}

Rect::~Rect() {
    // destructor. free all allocated memory.
}

Rect* Rect::copy() {
    // return a new shape with the current x, y, w, and h values
    return new Rect(this->x, this->y, this->width, this->height);
}

int Rect::getWidth() const {
    return this->width;
}

int Rect::getHeight() const {
    return this->height;
}

void Rect::setWidth(int w) {
    this->width = w;
}

void Rect::setHeight(int h) {
    this->height = h;
}

string Rect::as_string() const {
    return "It's a Rectangle at x: " + to_string(this->x) + ", y: " + to_string(this->y) + " with width: " + to_string(this->width) + " and height: " + to_string(this->height);
}


/* Right Triangle */
RightTriangle::RightTriangle() {
    // default constructor. set private members width and height to zero.
    this->base = 0;
    this->height = 0;
}

RightTriangle::RightTriangle(int b, int h) {
    // parametrized constructor. set private members x and y to value of parameters x and y.
    this->base = b;
    this->height = h;
}

RightTriangle::RightTriangle(int x, int y, int b, int h) {
    // parametrized constructor. set private members x and y to value of parameters x and y.
    this->base = b;
    this->height = h;
    this->x = x;
    this->y = y;
}

RightTriangle::~RightTriangle() {
    // destructor. free all allocated memory.
}

RightTriangle* RightTriangle::copy() {
    // return a new shape with the current x, y, b, and h values
    return new RightTriangle(this->x, this->y, this->base, this->height);
}

int RightTriangle::getBase() const {
    return this->base;
}

int RightTriangle::getHeight() const {
    return this->height;
}

void RightTriangle::setBase(int b) {
    this->base = b;
}

void RightTriangle::setHeight(int h) {
    this->height = h;
}

string RightTriangle::as_string() const {
    return "It's a Right Triangle at x: " + to_string(this->x) + ", y: " + to_string(this->y) + " with base: " + to_string(this->base) + " and height: " + to_string(this->height);
}
