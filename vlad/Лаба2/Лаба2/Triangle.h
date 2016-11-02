#pragma once

class Triangle
{
public:
	
	static bool areEqual(double, double); //��������� ����� � ��������� ������
	Triangle();
	Triangle(int, int, int, int, int, int);
	void change(int, int, int, int, int, int);
	void print();
	double getLength(int, int, int, int);
	double getA();
	double getB();
	double getC();
	double getPerimeter(); //��������
	double getArea(); //�������
	bool isValid(); //����������
	bool isEquilateral(); //��������������
	bool isIsosceles(); //��������������
	bool isRectangular(); //�������������

private:

	static const double EPSILON; //������������ �����������
	int x1_, y1_, x2_, y2_, x3_, y3_;
};