#pragma once

class Triangle
{
public:
	
	static bool areEqual(double, double); //сравнение чисел с плавающей точкой
	Triangle();
	Triangle(int, int, int, int, int, int);
	void change(int, int, int, int, int, int);
	void print();
	double getLength(int, int, int, int);
	double getA();
	double getB();
	double getC();
	double getPerimeter(); //периметр
	double getArea(); //площадь
	bool isValid(); //существует
	bool isEquilateral(); //равносторонний
	bool isIsosceles(); //равнобедренный
	bool isRectangular(); //прямоугольный

private:

	static const double EPSILON; //максимальная погрешность
	int x1_, y1_, x2_, y2_, x3_, y3_;
};