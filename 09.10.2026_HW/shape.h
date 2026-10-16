#pragma once

#include <string>
#include <iostream>
#include <cmath>

class Shape
{
protected:
    std::string name_;
    double S_;
    double P_;

public:
    const std::string &getName() const;
    virtual double area();
    virtual double perimeter();

    Shape() = default;
    virtual ~Shape() = default;

    friend bool operator==(const Shape &lhs, const Shape &rhs);
    friend bool operator^(const Shape &lhs, const Shape &rhs);
};

class Triangle : public Shape
{
private:
    double a_, b_, c_, p_; // стороны и полупериметр

public:
    virtual double area() override final;
    virtual double perimeter() override final;

    Triangle(std::string name, double a, double b, double c);
    ~Triangle() = default;
    Triangle(const Triangle &other);
    Triangle(Triangle &&other);
    Triangle &operator=(const Triangle &other);
    Triangle &operator=(Triangle &&other);

    friend std::ostream &operator<<(std::ostream &stream, const Triangle &shape_t);
};

class Rectangular : public Shape
{
protected:
    double weight_, hight_;

public:
    virtual double area() override final;
    virtual double perimeter() override final;

    Rectangular(std::string name, double weight, double height);
    ~Rectangular() = default;
    Rectangular(const Rectangular &other);
    Rectangular(Rectangular &&other);
    Rectangular &operator=(const Rectangular &other);
    Rectangular &operator=(Rectangular &&other);

    friend std::ostream &operator<<(std::ostream &stream, const Rectangular &rhs);
};

class Circle : public Shape
{
private:
    double R_;

public:
    virtual double area() override final;
    virtual double perimeter() override final;

    Circle(std::string name, double R);
    ~Circle() = default;
    Circle(const Circle &other);
    Circle(Circle &&other);
    Circle &operator=(const Circle &other);
    Circle &operator=(Circle &&other);

    friend std::ostream &operator<<(std::ostream &stream, const Circle &rhs);
};

class Square : public Rectangular
{
public:
    Square(std::string name, double lengh);
    ~Square() = default;
    Square(const Square &other);
    Square(Square &&other);
    Square &operator=(const Square &other);
    Square &operator=(Square &&other);

    friend std::ostream &operator<<(std::ostream &stream, const Square &rhs);
};