#include <iostream>
#include <queue>
#include <list>

using namespace std;

enum sex { man, woman };
enum weakness { head, ass, hands, legs, nails, hair };

class Superhero
{
private:
    string pseudonym;
    string name;
    string date;
    sex S;
    string superpower;
    weakness W;
    int victory;
    int rating;
public:
    Superhero()
    {
        pseudonym = "Pseudonym";
        name = "Name";
        date = "1984";
        S = man;
        superpower = "superpower";
        W = ass;
        victory = 0;
        rating = 0;
    }

    Superhero(string p, string n, string d, sex s1, string s2, weakness w, int v, int r)
    {
        pseudonym = p;
        name = n;
        date = d;
        S = s1;
        superpower = s2;
        W = w;
        victory = v;
        rating = r;
    }

    friend ostream& operator<<(ostream& stream, Superhero hero);
    friend bool operator>(Superhero s1, Superhero s);
    friend bool operator<(Superhero s1, Superhero s);
};

bool operator>(Superhero s1, Superhero s)
{
    if (s1.rating > s.rating)
        return true;
    else if (s1.rating == s.rating)
    {
        if (s1.victory > s.victory)
            return true;
        else if (s1.victory == s.victory)
        {
            if (s1.pseudonym > s.pseudonym)
                return true;
        }
        else
            return false;
    }
    return false;
}

bool operator<(Superhero s1, Superhero s)
{
    if (s1.rating < s.rating)
        return true;
    else if (s1.rating == s.rating)
    {
        if (s1.victory < s.victory)
            return true;
        else if (s1.victory == s.victory)
        {
            if (s1.pseudonym < s.pseudonym)
                return true;
        }
        else
            return false;
    }
    return false;
}

ostream& operator<<(ostream& stream, Superhero hero)
{
    stream << '\n' << hero.pseudonym << " " << hero.name << " " << hero.date << " " << hero.S << " " << hero.superpower << " " << hero.W << " " << hero.victory << " " << hero.rating;
    return stream;
}

template<typename T>
void print_queue(priority_queue<T> q)
{
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << '\n';
}

template <class T>
class Heap
{
protected:
    T* arr;
    int count;
    int memory;
public:
    Heap(int m = 100)
    {
        arr = new T[m];
        count = 0;
        memory = m;
    }

    ~Heap()
    {
        delete[] arr;
    }

    int getLeftChildIndex(int index)
    {
        if (index >= 0 and index * 2 + 1 < count)
            return 2 * index + 1;
        return -1;
    }

    int getRightChildIndex(int index)
    {
        if (index >= 0 and index * 2 + 2 < count)
            return 2 * index + 2;
        return -1;
    }

    int getParentIndex(int index)
    {
        if (index > 0 and index < count)
        {
            if (index % 2 == 1)
                return (index - 1) / 2;
            else
                return (index - 2) / 2;
        }
        return -1;
    }

    T getLeftChild(int index)
    {
        if (index >= 0 and index * 2 + 1 < count)
            return arr[2 * index + 1];
    }

    T getRightChild(int index)
    {
        if (index >= 0 and index * 2 + 2 < count)
            return arr[2 * index + 2];
    }

    T getParent(int index)
    {
        if (index > 0 and index < count)
        {
            if (index % 2 == 1)
                return arr[(index - 1) / 2];
            else
                return arr[(index - 2) / 2];
        }
    }

    void Swap(int index1, int index2)
    {
        if (index1 >= 0 and index1 < count and index2 >= 0 and index2 < count)
        {
            T temp = arr[index1];
            arr[index1] = arr[index2];
            arr[index2] = temp;
        }
    }

    void SiftUp(int index)
    {
        if (index == 0) return;
        int ParentIndex = getParentIndex(index);
        while (index != 0 and arr[ParentIndex] < arr[index])
        {
            Swap(index, ParentIndex);
            index = ParentIndex;
            ParentIndex = getParentIndex(index);
        }
    }

    T push(T data)
    {
        T el = data;
        if (count < memory)
        {
            arr[count] = el;
            count++;
            SiftUp(count - 1);
            return el;
        }
    }

    void Heapify(int index = 0)
    {
        int LeftChild = getLeftChildIndex(index);
        int RightChild = getRightChildIndex(index);
        if (LeftChild < 0 and RightChild < 0) { return; }
        if (LeftChild > 0 and RightChild < 0)
        {
            if (arr[index] < arr[LeftChild])
                Swap(index, LeftChild);
            return;
        }
        if (arr[LeftChild] > arr[index] or arr[RightChild] > arr[index])
        {
            if (arr[LeftChild] > arr[RightChild])
            {
                Swap(index, LeftChild);
                Heapify(LeftChild);
            }
            else
            {
                Swap(index, RightChild);
                Heapify(RightChild);
            }
        }
        return;
    }

    T ExtractMax()
    {
        if (count != 0)
        {
            T r = arr[0];
            if (count == 1)
            {
                count--;
                return r;
            }
            Swap(0, count - 1);
            count--;
            Heapify();
            return r;
        }
    }

    T Remove(int index)
    {
        if (index == 0)
            return ExtractMax();
        if (index == count - 1)
        {
            T r = arr[index];
            count--;
            return r;
        }
        if (index > 0 and index < count)
        {
            T r = arr[index];
            Swap(index, count - 1);
            count--;
            if (arr[getParentIndex(index)] < arr[index])
                SiftUp(index);
            else
                Heapify(index);
            return r;
        }
    }

    template <class T> friend ostream& operator<<(ostream& s, Heap<T> h);
};

template <class T>
ostream& operator<<(ostream& s, Heap<T> h)
{
    while (h.count != 0)
    {
        T v = h.ExtractMax();
        s << v;
    }
    return s;
}

template <class T>
class Node
{
private:
    T value;
    list<Node<T>*> children;
    int degree;
    bool marked;

public:
    T getValue() { return value; }
    void setValue(T v) { value = v; }
    list<Node<T>*> getChildren() { return children; }
    int& getDegree() { return degree; }
    bool& getMarked() { return marked; }

    Node(T Value)
    {
        value = Value;
        degree = 0;
        marked = false;
    }

    bool operator>(Node<T>& other)
    {
        return value > other.getValue();
    }

    bool operator<(Node<T>& other)
    {
        return value < other.getValue();
    }

    void print()
    {
        cout << value;
    }

};

template<typename T>
class FibonacciHeap {
private:

    void merge(Node<T>*& child, Node<T>*& parent)
    {
        roots.remove(child);
        parent->getChildren().push_back(child);
        child->getMarked() = false;
        ++parent->getDegree();
    }

public:
    FibonacciHeap()
    {
        maxNode = NULL;
    }

    void insert(T v)
    {
        Node<T>* newNode = new Node<T>(v);
        roots.push_back(newNode);

        if (!maxNode || v > maxNode->getValue()) {
            maxNode = newNode;
        }
    }

    T ExtractMax()
    {
        if (!roots.empty())
        {
            T maxV = maxNode->getValue();

            roots.remove(maxNode);

            for (auto child : maxNode->getChildren())
            {
                roots.push_back(child);
            }

            delete maxNode;
            maxNode = NULL;

            if (!roots.empty())
            {
                auto max = *(roots.begin());
                for (auto m : roots)
                {
                    if (m->getValue() > max->getValue())
                        max = m;
                }
                maxNode = max;
            }
            return maxV;
        }
    }

    void print()
    {
        for (auto node : roots)
        {
            cout << node->getValue() << " ";
        }
        cout << endl;
    }

    list<Node<T>*> roots;
    Node<T>* maxNode;
};

int main()
{
    Superhero B("x", "f", "d", man, "m", head, 3, 11);
    Superhero B1("y", "f", "d", man, "m", head, 3, 3);
    Superhero B2("b", "f", "d", man, "m", head, 3, 41);
    Superhero B3("s", "f", "d", man, "m", head, 3, 12);
    Superhero B4("h", "f", "d", man, "m", head, 3, 67);
    Superhero B5("n", "f", "d", man, "m", head, 6, 11);

    priority_queue<Superhero> test1;
    test1.push(B);
    test1.push(B1);
    test1.push(B2);
    test1.push(B3);
    test1.push(B4);
    test1.push(B5);

    print_queue(test1);

    Heap<Superhero> test2;
    test2.push(B);
    test2.push(B1);
    test2.push(B2);
    test2.push(B3);
    test2.push(B4);
    test2.push(B5);
    test2.Remove(3);
    cout << '\n' << test2;

    FibonacciHeap<Superhero> fibonacciHeap;

    fibonacciHeap.insert(B);
    fibonacciHeap.insert(B1);
    fibonacciHeap.insert(B3);
    fibonacciHeap.insert(B4);
    fibonacciHeap.insert(B5);

    cout << '\n';
    fibonacciHeap.print();

    while (!fibonacciHeap.roots.empty())
    {
        Superhero maxKey = fibonacciHeap.ExtractMax();
        cout << maxKey << endl;
    }

    char c; cin >> c;
    return 0;
}
