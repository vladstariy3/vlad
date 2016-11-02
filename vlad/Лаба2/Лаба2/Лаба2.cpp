// ЛР2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Triangle.h"

using namespace std;

int random(int min, int max)
{
	return (int)(((double)rand() / (double)RAND_MAX) * (max + 1 - min) + min);
}

int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Triangle* triangles = new Triangle[6];
	for (int i = 0; i < 6; i++)
	{
		triangles[i] = Triangle(random(-9, 9), random(-9, 9), random(-9, 9), random(-9, 9), random(-9, 9), random(-9, 9));
		triangles[i].print();
		cout << endl;
	}
	delete[] triangles;
    return 0;
	system("pause");
}
