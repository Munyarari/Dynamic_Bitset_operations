// bitset.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "boost\dynamic_bitset.hpp"
//#include <bitset>
using namespace std;
using namespace boost;
class Flags
{
private:
	int size;
	dynamic_bitset<> set;
public:
	Flags()
	{
		for (int i = 0; i < size; i++)
		{
			set[i] = 0;
		}
	}
	void magnitude(int n)
	{
		set.resize(n);
	}

	void Insert(int n)
	{
		set[n - 1] = 1;
	}


	Flags Union(Flags k) {
		Flags temp;
		temp.set = set | k.set;
		return temp;
	}
	Flags Intersection(Flags k) {
		Flags temp;
		temp.set = set & k.set;
		return temp;
	}
	Flags Substraction(Flags k) {
		Flags temp;
		temp.set = set & ~(k.set);
		return temp;
	}
	void Print_Stuff()
	{
		for (int i = 0; i < 32; i++)
		{
			if (set[i] == 1)
				cout << i + 1 << " ";
		}
		/*cout<<a<<endl;*/
	}
};


int main()
{
	Flags a, b, c, d, e;
	int n;
	cin >> n;
	a.magnitude(n);
	b.magnitude(n);
	c.magnitude(n);
	d.magnitude(n);
	e.magnitude(n);
	a.Insert(10); a.Insert(20); a.Insert(30); a.Insert(18); a.Insert(19); a.Insert(15); a.Insert(13); a.Insert(11); a.Insert(7); a.Insert(5); a.Insert(4); a.Insert(2); a.Insert(1);
	b.Insert(23); b.Insert(94); b.Insert(25); b.Insert(18); b.Insert(15); b.Insert(13); b.Insert(11); b.Insert(10); b.Insert(9);
	c = a.Union(b);
	d = a.Intersection(b);
	e = a.Substraction(b);

	a.Print_Stuff();
	cout << endl;
	b.Print_Stuff();
	cout << endl;
	c.Print_Stuff();
	cout << endl;
	d.Print_Stuff();
	cout << endl;
	e.Print_Stuff();
	cout << endl;

	return 0;
}

