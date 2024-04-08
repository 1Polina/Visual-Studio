#include <vector>
#include <iostream>
#include <set>
#include <queue>


using namespace std;

template<class T>
typename set<T>::iterator Insert(set<T>& s, T newEl)
{
    pair<typename set<T>::iterator, bool> p = s.insert(newEl);
    return p.first;
}

template <class T>
ostream& operator<<(ostream& s, set<T> Set)
{
    s << '\n';
    typename set<T>::iterator it = Set.begin();
    for (; it != Set.end(); it++)
    {
        s << " " << *it;
    }
    return s;
}

template<class T>
typename set<T>::iterator find(set<T>& s, T el)
{
    return s.find(el);
}

template<class T>
typename set<T>::iterator remove(set<T>& s, typename set<T>::iterator it)
{
    return s.erase(it);
}

template<class T>
typename set<T>::iterator min(set<T>& s)
{
    return s.begin();
}

template<class T>
typename set<T>::iterator max(set<T>& s)
{
    return --s.end();
}

template <class T>
vector<T> filter(set<T> s, T el)
{
    vector<T> res;
    typename set<T>::iterator it = s.find(el);
    it++;
    for (; it != s.end(); it++)
    {
        res.push_back(*it);
    }
    return res;
}





int main()
{
    set<int> test;
    Insert(test, 3);
    Insert(test, 7);
    Insert(test, 1);
    Insert(test, 9);
    Insert(test, 0);
    Insert(test, 2);

    cout << test;

    set<int>::iterator f = find(test, 3);
    cout << test;

    set<int>::iterator m = min(test);
    set<int>::iterator k = max(test);
    cout << '\n' << *m;
    cout << '\n' << *k;

    vector<int> r = filter(test, 1);
    vector<int>::iterator it = r.begin();
    cout << '\n';
    for (; it != r.end(); it++)
        cout << *it << " ";

    char c; cin >> c;
    
}