#include <list>
#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

class sportsman
{
private:
	string fi;
	int medals;
	int vozvrast;
	string grajdanka;
	string vid;
public:
	sportsman(string fii, int med, int voz, string gra, string vidi)
	{
		fi = fii;
		medals = med;
		vozvrast = voz;
		grajdanka = gra;
		vid = vidi;
	}


	bool operator> (sportsman a)
	{
		if (medals > a.medals)
		{
			return true;
		}
		else if (medals == a.medals)
		{
			if (vozvrast > a.vozvrast)
			{
				return true;
			}
			else if (vozvrast == a.vozvrast)
			{
				if (fi > a.fi)
				{
					return true;
				}
			}
		}
		return false;

	}

	bool operator< (sportsman a)
	{
		if (medals < a.medals)
		{
			return true;
		}
		else if (medals == a.medals)
		{
			if (vozvrast < a.vozvrast)
			{
				return true;
			}
			else if (vozvrast == a.vozvrast)
			{
				if (fi < a.fi)
				{
					return true;
				}
			}
		}
		return false;

	}
	friend ostream& operator<< (ostream& s, sportsman r);
};

ostream& operator<< (ostream& s, sportsman r)
{
	s << r.medals << " " << r.fi << r.grajdanka << r.vid << r.vozvrast;
	return s;
}

bool complexComparator(const complex<double>& a, const complex<double>& b) {
	return abs(a) < abs(b);
}

bool operator>(complex<double> a, complex<double> b)
{
	return abs(a) < abs(b);
}

bool operator<(complex<double> a, complex<double> b)
{
	return abs(a) < abs(b);
}

template<class T>
void push(list<T>& lst, T element)
{
	typename list<T>::iterator p = lst.begin();
	while (p != lst.end())
	{
		if (*p < element)
			break;
		p++;
	}lst.insert(p, element);
}

template<class T>
T pop(list<T>& lst, int i)
{

	T b = *lst.begin();
	lst.erase(lst.begin()); 
	return b;

}

template<class T>
void print(list<T>& lst)
{
	typename list<T>::iterator p = lst.begin();
	while (p != lst.end())
	{
		cout << '\n' << *p;
		p++;
	}
}


template<class T>
list<T> filter(list<T>& lst, bool(*k)(T))
{
	list<T> res;
	typename list<T>::iterator it = lst.begin();
	while (it != lst.end())
	{
		if (k(*it))
			push<T>(res, *it);
		it++;
	}
	return res;
}

bool predicat(complex<double> comp)
{
	return comp.real() < 0;
}

int main()
{
	list<complex<double>> complexList;

	complexList.push_back(complex<double>(-1.5, 2.0));
	complexList.push_back(complex<double>(-3.0, -4.0));
	complexList.push_back(complex<double>(2.0, 1.0));
	complexList.push_back(complex<double>(-1.0, 0.5));
	complexList.push_back(complex<double>(0.5, -0.5));

	complexList.sort(complexComparator);


	list<sportsman> newlist;
	push(newlist, sportsman("Vinogradov", 3, 19, "RS", "voleybol"));
	push(newlist, sportsman("Ablom", 0, 19, "RS", "voleybol"));
	push(newlist, sportsman("Gromov", 10, 19, "RS", "footbool"));

	print(complexList);
	print(newlist);
	pop(complexList, 2);
	cout << '\n';
	print(complexList);
	list<complex<double>> testFilter = filter(complexList, predicat);
	cout << '\n';
	print(testFilter);


	char c; cin >> c;

	return 0;
}

















