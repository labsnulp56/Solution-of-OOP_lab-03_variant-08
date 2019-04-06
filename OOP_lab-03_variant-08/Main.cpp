#define _USE_MATH_DEFINES // for C++
#include <cmath>

#include <iostream>
#define M 3

using namespace std;

class Cone
{
private:
	double *radius;
	double *height;

public:
	Cone()
	{
		this->radius = new double(0);
		this->height = new double(0);
	}
	Cone(double radius, double height)
	{
		this->radius = new double(radius);
		this->height = new double(height);
	}
	~Cone() {
		delete height;
		delete radius;
		cout << "destructor" << endl;
	}
	double GetX() const
	{
		return *radius;
	}
	double GetY() const
	{
		return *height;
	}
	void SetX(double a)
	{
		*radius = a;
	}
	void SetY(double b)
	{
		*height = b;
	}

	double Volume(Cone &obj);
	double Area(Cone &obj);
	friend bool operator<(const Cone& l1, const Cone& l2);
	friend const Cone operator+(const Cone& l1, const Cone& l2);
	friend ostream& operator<<(ostream &s, const Cone &l);
	void insertionSort(Cone *arr[], int n);

};

double Cone::Volume(Cone &obj)
{
	return (1.0 / 3.0)*M_PI*pow(*radius, 2)*(*height);
}
double Cone::Area(Cone &obj)
{
	return M_PI * (*radius)* ((*(radius)) + (*height));
}
/* -------------------------------------------------- */
bool operator<(const Cone& l1, const Cone& l2)
{
	double cone1 = (1.0 / 3.0)*M_PI*pow(l1.GetX(), 2)*l1.GetY();
	double cone2 = (1.0 / 3.0)*M_PI*pow(l2.GetX(), 2)*l2.GetY();
	return cone1 < cone2;
}

const Cone operator+(const Cone &l1, const Cone &l2)
{
	return Cone((l1.GetX() + l2.GetX()), l2.GetY() + l1.GetY());
}

ostream& operator<<(ostream &s, const Cone &l)
{
	s << "Radius sum: " << l.GetX() << " Height sum: " << l.GetY() << endl;
	return s;
}

void insertionSort(Cone *arr[], int n)
{
	int i, j;
	Cone *key = new Cone;
	for (i = 1; i < n; i++) {
		*key = *arr[i];
		j = i - 1;
		while (j >= 0 && *arr[j] < *arr[i]) {
			*arr[j + 1] = *arr[j];
			j = j - 1;
		}
		*arr[j + 1] = *key;
		delete key;
	}
}

int main()
{
	{
		Cone *list;
		list = new Cone[3];
		int n = sizeof(list) / sizeof(list[0]);
		int count = 3;
		int radius;
		int height;

		register int i = 0;
		for (i = 0; i < M; i++)
		{
			cout << "input radius" << endl;
			cin >> radius;
			list[i].SetX(radius);
			cout << "input height" << endl;
			cin >> height;
			list[i].SetY(height);
		}
		for (i = 0; i < M; i++)
		{
			cout << "Radius = " << list[i].GetX() << ' ' << "Height = " << list[i].GetY() << endl;
			cout << "Volume of con is " << list[i].Volume(list[i]) << endl;

			cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		}
		cout << "Comparison v1 < v2: " << (list[0] < list[1]) << endl;
		cout << "Comparison v2 < v1: " << (list[1] < list[0]) << endl;
		cout << (list[0] + list[1]);
		cout << (list[1] + list[2]);
		puts("--------------------------------------------------");

		insertionSort(&list, n);

		for (i = 0; i < M; i++)
		{
			cout << "Radius = " << list[i].GetX() << ' ' << "Height = " << list[i].GetY() << endl;
			cout << "Volume of con is " << list[i].Volume(list[i]) << endl;
			cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		}
	}
	//delete[]list;
	system("pause");

	return 0;
}

