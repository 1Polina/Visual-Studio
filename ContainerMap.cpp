// Egor_Bilet.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <map>


using namespace std;


template <class K, class V>
void push(map<K, V>& m, K key, V value)
{
    m.insert({ key, value });
}

template <class T, class T1>
typename map<T, T1>::iterator find(map<T, T1>& m, T f) //Поиск по ключу
{
    typename map<T, T1>::iterator it = m.find(f); //Вызов метода find 
    return it;
}

template <class K, class V>
void remove(map<K, V>& m, K k)
{
    typename map<K, V>::iterator it = m.find(k);
    m.erase(it);
}

template <class K, class V>
ostream& operator<<(ostream& s, map<K, V> m)
{
    typename map<K, V>::iterator it = m.begin();
    s << '\n';
    for (; it != m.end(); it++)
    {
        s << "(" << it->first << " " << it->second << ") ";
    }
    return s;
}

template<class T, class T1>
vector<pair<T, T1>> fn(multimap<T, T1> m, T1 key)
{
    pair<typename multimap<T, T1>::iterator, typename multimap<T, T1>::iterator> range = m.equal_range(key);
    vector<pair<T, T1>> res;
    for (typename multimap<T, T1>::iterator i = range.first; i != range.second; i++)
        res.push_back(*i);
    return res;
}

int main()
{

    map<int, int> m;
    push(m, 3, 6);
    push(m, 7, 0);
    push(m, 1, 0);
    push(m, 5, 0);
    push(m, 8, 0);
    cout << m;
    remove(m, 7);
    cout << m;

    multimap<int, int> m2;
    m2.insert({ 3, 6 });
    m2.insert({ 7, 6 });
    m2.insert({ 3, 6 });
    m2.insert({ 2, 6 });
    m2.insert({ 1, 6 });
    vector<pair<int, int>> r = fn(m2, 1);
    cout << '\n';
    cout << r[0].first << " " << r[0].second;

    char c; cin >> c;
}

