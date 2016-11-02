#include "stdafx.h"
#include "Triangle.h"

using namespace std;

const double Triangle::EPSILON = 0.001;

bool Triangle::areEqual(double a, double b)
{
	return fabs(a - b) < EPSILON;//������� �����������
}

Triangle::Triangle()
	:x1_(0), y1_(0), x2_(0), y2_(0), x3_(0), y3_(0)//���������� ������������ ����� ��������� �������� � ���� 2
{

}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)//����������� ����� �������� ���������� � ������
	: x1_(x1), y1_(y1), x2_(x2), y2_(y2), x3_(x3), y3_(y3)
{

}

void Triangle::change(int x1, int y1, int x2, int y2, int x3, int y3)//�������� ��������
{
	x1_ = x1;
	y1_ = y1;
	x2_ = x2;
	y2_ = y2;
	x3_ = x3;
	y3_ = y3;
}

void Triangle::print()
{
	cout << "���������� ����� ������������:" << endl;
	cout << "A: " << '(' << x1_ << ", " << y1_ << ')' << endl;
	cout << "B: " << '(' << x2_ << ", " << y2_ << ')' << endl;
	cout << "C: " << '(' << x3_ << ", " << y3_ << ')' << endl;
	cout << "����� ������ ������������:" << endl;
	cout << "AB: " << getA() << endl;
	cout << "AC: " << getB() << endl;
	cout << "BC: " << getC() << endl;
	cout << "�������� ������������: " << getPerimeter() << endl;
	cout << "������� ������������: " << getArea() << endl;
	if (isValid())
	{
		cout << "����������� ����������" << endl;
	}
	else
	{
		cout << "����������� �� ����������" << endl;
	}
	if (isEquilateral())
	{
		cout << "����������� �������� ��������������" << endl;
	}
	else
	{
		cout << "����������� �� �������� ��������������" << endl;
	}
	if (isIsosceles())
	{
		cout << "����������� �������� ��������������" << endl;
	}
	else
	{
		cout << "����������� �� �������� ��������������" << endl;
	}
	if (isRectangular())
	{
		cout << "����������� �������� �������������" << endl;
	}
	else
	{
		cout << "����������� �� �������� �������������" << endl;
	}
}


double Triangle::getLength(int x1, int x2, int y1, int y2)//����ר� ������ �������
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double Triangle::getA()
{
	return getLength(x1_, x2_, y1_, y2_);
}

double Triangle::getB()
{
	return getLength(x1_, x3_, y1_, y3_);
}

double Triangle::getC()
{
	return getLength(x2_, x3_, y2_, y3_);
}

double Triangle::getPerimeter()//�����
{
	if (!isValid())
	{
		return 0;
	}
	return (getA() + getB() + getC());
}

double Triangle::getArea()//�������
{
	if (!isValid())
	{
		return 0;
	}
	double half_perimeter = getPerimeter() / 2;
	return sqrt(half_perimeter * (half_perimeter - getA()) * (half_perimeter - getB()) * (half_perimeter - getC()));
}

bool Triangle::isValid()
{
	return ((getB() + getC() - getA()) > 0) && ((getA() + getC() - getB()) > 0) && ((getA() + getB() - getC()) > 0);
}

bool Triangle::isEquilateral()//��������������
{
	if (!isValid())
	{
		return false;
	}
	return areEqual(getA(), getB()) && areEqual(getB(), getC()) && areEqual(getA(), getC());
}

bool Triangle::isIsosceles()//��������������
{
	if (!isValid())
	{
		return false;
	}
	return areEqual(getA(), getB()) || areEqual(getB(), getC()) || areEqual(getA(), getC());
}

bool Triangle::isRectangular()//�������������
{
	if (!isValid())
	{
		return false;
	}
	return areEqual(pow(getA(), 2) + pow(getB(), 2), pow(getC(), 2)) ||
		   areEqual(pow(getB(), 2) + pow(getC(), 2), pow(getA(), 2)) ||
		   areEqual(pow(getA(), 2) + pow(getC(), 2), pow(getB(), 2));
};