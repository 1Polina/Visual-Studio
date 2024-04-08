#include <iostream>
#include <queue>

using namespace std;

template<class T>
void push(priority_queue<T>& q, T el)
{
    q.push(el);
}

template <class T>
void pop(priority_queue<T>& q)
{
    q.pop();
}

template <class T>
T top(priority_queue<T> q)
{
    return q.top();
}

template <class T>
ostream& operator<<(ostream& s, priority_queue<T> q)
{
    s << '\n';
    while(!q.empty())
    {
        s << top(q) << " ";
        q.pop();
    }
    return s;
}

template <class T>
T getElement(priority_queue<T> q, int index)
{
    if (index < q.size())
    {
        for (int i = 0; i < index; i++)
        {
            q.pop();
        }
        return q.top();
    }
}

int main()
{
    priority_queue<int> q;
    push(q, 0);
    push(q, 4);
    push(q, 1);
    push(q, 8);

    cout << q;

    int a = getElement(q, 2);
    cout << '\n' << a;

    char c; cin >> c;
    return 0;
}


