#include <iostream>
#include <list>
using namespace std;

class Exception : public exception
{
private:
    string str;
public:
    Exception(string s)
    {
        str = s;
    }

    void print()
    {
        cout << '\n' << str;
    }
};

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

    sportsman()
    {
        fi = " ";
        medals = 0;
        vozvrast = 0;
        grajdanka = " ";
        vid = " ";
    }

    string getF()
    {
        return fi;
    }

    bool operator==(sportsman s)
    {
        return fi == s.fi and medals == s.medals and vozvrast == s.vozvrast and grajdanka == s.grajdanka and vid == s.vid;
    }

    friend ostream& operator<< (ostream& s, sportsman r);
};

ostream& operator<< (ostream& s, sportsman r)
{
    s << r.medals << " " << r.fi << r.grajdanka << r.vid << r.vozvrast;
    return s;
}



template <class K, class V>
class Node
{
protected:
    K key;
    V data;
    Node* left;
    Node* right;
    Node* parent;
    int height;
public:
    virtual void setData(V d) { data = d; }
    virtual void setKey(K k) { key = k; }
    virtual void setLeft(Node* N) { left = N; }
    virtual void setRight(Node* N) { right = N; }
    virtual void setParent(Node* N) { parent = N; }
    virtual V getData() { return data; }
    int getHeight() { return height; }
    virtual Node* getLeft() { return left; }
    virtual Node* getRight() { return right; }
    virtual Node* getParent() { return parent; }
    virtual K getKey() { return key; }

    Node<K, V>(K k, V v)
    {
        data = v;
        key = k;
        left = right = parent = NULL;
        height = 1;
    }

    virtual void setHeight(int h)
    {
        height = h;
    }

    void fixHeight()
    {
        int hl = 0;
        int hr = 0;
        if (left != NULL)
            hl = left->getHeight();
        if (right != NULL)
            hr = right->getHeight();
        setHeight((hl > hr ? hl : hr) + 1);
    }

    int bfactor()
    {
        int hl = 0;
        int hr = 0;
        if (left != NULL)
            hl = left->height;
        if (right != NULL)
            hr = right->height;
        return (hl - hr);
    }

    Node<K, V>* successor()
    {
        if (right != NULL)
        {
            Node<K, V>* c = this->right;
            while (c->left != NULL)
                c = c->left;
            return c;
        }
        Node<K, V>* c = this->parent;
        if (c == NULL)
            return NULL;
        if (c->key > key)
            return c;
        do
        {
            c = c->parent;
        } while (c->key <= key);
        return c;
    }

    Node<K, V>* predecessor()
    {
        if (left != NULL)
        {
            Node<K, V>* c = this->left;
            while (c->right != NULL)
                c = c->right;
            return c;
        }
        Node<K, V>* c = this->parent;
        if (c == NULL)
            return NULL;
        while (c->key > key)
            c = c->parent;
        return c;
    }

    template<class K, class V>
    friend ostream& operator<< (ostream& stream, Node<K, V> N);
};

template<class K, class V>
ostream& operator<< (ostream& stream, Node<K, V> N)
{
    stream << "\nNode key: " << N.key << ", node data: " << N.data << ", node height: " << N.height;
    return stream;
}

template <class K, class V>
class TreeIterator //итератор для дерева
{
private:
    Node<K, V>* ptr;
public:
    TreeIterator()
    {
        ptr = NULL;
    }
    TreeIterator(Node<K, V>* p)
    {
        ptr = p;
    }
    void operator++(int)
    {
        ptr = ptr->successor();
    }
    void operator--(int)
    {
        ptr = ptr->predecessor();
    }
    Node<K, V> operator*()
    {
        return *ptr;
    }
    bool operator!=(TreeIterator<K, V> it)
    {
        return ptr != it.ptr;
    }
    bool operator==(Node<K, V>* p)
    {
        return ptr == p;
    }
    bool operator==(TreeIterator it)
    {
        return ptr == it.ptr;
    }
    Node<K, V>* operator->()
    {
        return ptr;
    }
    TreeIterator<K, V> operator=(Node<K, V>* p)
    {
        return ptr = p;
    }
    Node<K, V>* getPtr()
    {
        return ptr;
    }
};


//Задание 2.3
template <class K, class V>
class AVL_tree
{
protected:
    Node<K, V>* root;

    TreeIterator<K, V> push_P(K k, V v, TreeIterator<K, V> c)
    {
        Node<K, V>* el = new Node<K, V>(k, v);
        TreeIterator<K, V> newElement = el;
        if (root == NULL)
        {
            root = newElement.getPtr();
            root->fixHeight();
            return newElement;
        }

        if (c->getKey() > k and c->getLeft() == NULL)
        {
            c->setLeft(newElement.getPtr());
            newElement->setParent(c.getPtr());
            TreeIterator<K, V> cur = newElement;
            while (cur != NULL)
            {
                cur->fixHeight();
                cur = cur->getParent();
            }
            return c;
        }

        if (c->getKey() < k and c->getRight() == NULL)
        {
            c->setRight(newElement.getPtr());
            newElement->setParent(c.getPtr());
            TreeIterator<K, V> cur = newElement;
            while (cur != NULL)
            {
                cur->fixHeight();
                cur = cur->getParent();
            }
            return c;
        }

        if (c->getKey() > k)
        {
            return push_P(k, v, c->getLeft());
        }

        if (c->getKey() < k)
        {
            return push_P(k, v, c->getRight());
        }
    }

    TreeIterator<K, V> RotateRight(TreeIterator<K, V> p) //Правый поворот вокруг p
    {
        TreeIterator<K, V> q = p->getLeft();
        q->setParent(p->getParent());
        if (p != root)
        {
            q->setParent(p->getParent());
            if (p->getKey() < p->getParent()->getKey())
                p->getParent()->setLeft(q.getPtr());
            else
                p->getParent()->setRight(q.getPtr());
        }
        else
            root = q.getPtr();
        p->setLeft(q->getRight());
        if (q->getRight() != NULL)
            q->getRight()->setParent(p.getPtr());
        q->setRight(p.getPtr());
        p->setParent(q.getPtr());
        p->fixHeight();
        if (q->getLeft() != NULL)
            q->getLeft()->fixHeight();
        q->fixHeight();
        return q;
    }

    TreeIterator<K, V> RotateLeft(TreeIterator<K, V> p) //Левый поворот вокруг p
    {
        TreeIterator<K, V> q = p->getRight();
        q->setParent(p->getParent());
        if (p != root)
        {
            q->setParent(p->getParent());
            if (p->getKey() < p->getParent()->getKey())
                p->getParent()->setLeft(q.getPtr());
            else
                p->getParent()->setRight(q.getPtr());
        }
        else
            root = q.getPtr();
        p->setRight(q->getLeft());
        if (q->getLeft() != NULL)
            q->getLeft()->setParent(p.getPtr());
        q->setLeft(p.getPtr());
        p->setParent(q.getPtr());
        p->fixHeight();
        if (q->getRight() != NULL)
            q->getRight()->fixHeight();
        q->fixHeight();
        return q;
    }

    TreeIterator<K, V> Balance(TreeIterator<K, V> p) //Балансировка узла p
    {
        if (p->bfactor() >= 2 and p->getLeft()->getLeft() != NULL)
        {
            p = RotateRight(p);
            Balance(p);
        }
        if (p->bfactor() <= -2 and p->getRight()->getRight() != NULL and p->getKey() != p->getRight()->getKey())
        {
            p = RotateLeft(p);
            Balance(p);
        }
        return p;
    }

    void BeginBalance(TreeIterator<K, V> p)
    {
        p->fixHeight();
        while (p->getParent() != NULL)
        {
            Balance(p);
            p = p->getParent();
        }
        Balance(p);
    }

    TreeIterator<K, V> remove(TreeIterator<K, V> it) //Удаление элемента. Используется TreeIterator
    {
        if (it->getLeft() == NULL and it->getRight() == NULL)
        {
            if (it->getKey() < it->getParent()->getKey())
                it->getParent()->setLeft(NULL);
            else
                it->getParent()->setRight(NULL);
            return TreeIterator<K, V>(it->getParent());
        }
        else if (it->getLeft() != NULL and it->getRight() == NULL)
        {
            it->setKey(it->getLeft()->getKey());
            it->setData(it->getLeft()->getData());
            it = it->getLeft();
            return remove(it);
        }
        else if (it->getLeft() == NULL and it->getRight() != NULL)
        {
            it->setKey(it->getRight()->getKey());
            it->setData(it->getRight()->getData());
            it = it->getRight();
            return remove(it);
        }
        else
        {
            TreeIterator<K, V> it2 = it->successor();
            it->setKey(it2->getKey());
            return remove(it2);
        }
    }

public:
    AVL_tree()
    {
        root = NULL;
    }

    TreeIterator<K, V> push(K k, V v)
    {
        TreeIterator<K, V> c = push_P(k, v, root);
        if (c != root)
            BeginBalance(c->getParent());
        else
            BeginBalance(c);
        return c;
    }

    TreeIterator<K, V> max(TreeIterator<K, V> c)
    {
        while (c->getRight() != NULL)
            c = c->getRight();
        return c;
    }

    TreeIterator<K, V> min(TreeIterator<K, V> c)
    {
        while (c->getLeft() != NULL)
            c = c->getLeft();
        return c;
    }

    Node<K, V>* getRoot()
    {
        return root;
    }

    TreeIterator<K, V> Remove(TreeIterator<K, V> it)
    {
        TreeIterator<K, V> res = remove(it);
        while (res->getParent() != NULL)
        {
            res->fixHeight();
            res = res->getParent();
        }
        root->fixHeight();
        BeginBalance(res.getPtr());
        return res;
    }

    TreeIterator<K, V> operator[](int i)
    {
        int i2 = 0;
        TreeIterator<K, V> m = min(root);
        while (i2 != i)
        {
            m = m->successor();
            i2++;
        }
        return m;
    }

    TreeIterator<K, V> find_key(bool (*ptr)(TreeIterator<K, V>, K key), K key) //Поиск по ключу. Используется TreeIterator
    {
        TreeIterator<K, V> cur = root;
        while (true)
        {
            if (cur->getKey() > key)
                cur = cur->getLeft();
            if (cur->getKey() < key)
                cur = cur->getRight();
            if (cur.getPtr() == NULL or ptr(cur, key))
                return cur;
        }
    }

    TreeIterator<K, V> find_value(bool (*ptr)(TreeIterator<K, V>)) //Поиск по значению. Используется TreeIterator
    {
        TreeIterator<K, V> cur = min(root);
        while (true)
        {
            if (cur.getPtr() == NULL or ptr(cur))
                return cur;
            cur++;
        }
    }

    template <class K, class V>
    friend ostream& operator<<(ostream& s, AVL_tree<K, V> t);
};

template <class K, class V>
ostream& operator<<(ostream& s, AVL_tree<K, V> t) //Оператор <<. Используется TreeIterator
{
    TreeIterator<K, V> cur = t.min(t.getRoot());
    TreeIterator<K, V> mx = t.max(t.getRoot());
    while (true)
    {
        K parent = "NULL";
        K k1 = "NULL";
        K k2 = "NULL";
        if (cur->getRight() != NULL)
            k2 = cur->getRight()->getKey();
        if (cur->getLeft() != NULL)
            k1 = cur->getLeft()->getKey();
        if (cur->getParent() != NULL)
            parent = cur->getParent()->getKey();
        s << *cur << " | " << "Left: " << k1 << ", Right: " << k2 << ", Parent: " << parent;
        if (cur == t.getRoot())
            s << " - root";
        if (cur == mx)
            break;
        cur++;
    }
    return s;
}

//Задание 2.4
template<class K, class V>
class Tree : public AVL_tree<K, V>
{
private:
    TreeIterator<K, V> push_P(K k, V v, TreeIterator<K, V> c)
    {
        Node<K, V>* el = new Node<K, V>(k, v);
        TreeIterator<K, V> newElement = el;
        if (this->root == NULL)
        {
            this->root = newElement.getPtr();
            this->root->fixHeight();
            return newElement;
        }

        if (c->getKey() > k and c->getLeft() == NULL)
        {
            c->setLeft(newElement.getPtr());
            newElement->setParent(c.getPtr());
            TreeIterator<K, V> cur = newElement;
            while (cur != NULL)
            {
                cur->fixHeight();
                cur = cur->getParent();
            }
            return c;
        }

        if (c->getKey() <= k and c->getRight() == NULL)
        {
            c->setRight(newElement.getPtr());
            newElement->setParent(c.getPtr());
            TreeIterator<K, V> cur = newElement;
            while (cur != NULL)
            {
                cur->fixHeight();
                cur = cur->getParent();
            }
            return c;
        }

        if (c->getKey() > k)
            return push_P(k, v, c->getLeft());

        if (c->getKey() <= k)
            return push_P(k, v, c->getRight());
    }
public:
    Tree() : AVL_tree<K, V>() {}

    TreeIterator<K, V> push(K k, V v)
    {
        TreeIterator<K, V> c = push_P(k, v, this->root);
        this->BeginBalance(c);
        return c;
    }

    list<V> operator[](K key)
    {
        TreeIterator<K, V> cur = this->root;
        list<V> res;
        while (true)
        {
            if (cur->getKey() < key)
                cur = cur->getRight();
            else if (cur->getKey() > key)
                cur = cur->getLeft();
            if (cur == NULL)
                throw Exception("Not found");
            if (cur->getKey() == key)
                break;
        }
        while (cur != NULL)
        {
            res.push_back(cur->getData());
            cur = cur->getRight();
        }
        return res;
    }
};

//Задание 2.5
template<class K, class V>
class SplayTree : public AVL_tree<K, V>
{
public:
    SplayTree() : AVL_tree<K, V>() {}

    TreeIterator<K, V> Remove(TreeIterator<K, V> it)
    {
        return AVL_tree<K, V>::remove(it);
    }

    TreeIterator<K, V> push(K k, V v) //Добавление нового элемента. Вызывает splay для добавленного элемента
    {
        TreeIterator<K, V> it = AVL_tree<K, V>::push_P(k, v, TreeIterator<K, V>(this->root));
        if (it == this->root)
            return it;
        if (it->getLeft() != NULL and it->getLeft()->getKey() == k)
            splay(TreeIterator<K, V>(it->getLeft()));
        else
            splay(TreeIterator<K, V>(it->getRight()));
        return it;
    }



    TreeIterator<K, V> operator[](K key) //Доступ к элементу
    {
        TreeIterator<K, V> cur = this->root;
        while (true)
        {
            if (cur->getKey() < key)
                cur = cur->getRight();
            else if (cur->getKey() > key)
                cur = cur->getLeft();
            if (cur == NULL)
                throw Exception("Not found");
            if (cur->getKey() == key)
                break;
        }
        splay(cur); //Вызов splay для найденного элемента
        return cur;
    }

    TreeIterator<K, V> find_key(bool (*ptr)(TreeIterator<K, V>, K key), K key) //Поиск
    {
        TreeIterator<K, V> cur = this->root;
        while (true)
        {
            if (cur->getKey() < key)
                cur = cur->getRight();
            else if (cur->getKey() > key)
                cur = cur->getLeft();
            if (cur == NULL)
                throw Exception("Not found");
            if (ptr != NULL)
                if (ptr(cur, key))
                    break;
                else
                    if (cur->getKey() == key)
                        break;
        }
        splay(cur); //Вызов splay для найденного элемента
        return cur;
    }

    void splay(TreeIterator<K, V> it) //Та самая функция, которая двигает элемент к корню
    {
        if (it == NULL)
            throw Exception("error");
        while (it->getParent() != NULL)
        {
            if (it->getParent() == this->root)
            {
                if (it == it->getParent()->getLeft())
                    this->RotateRight(TreeIterator<K, V>(it->getParent()));
                else
                    this->RotateLeft(TreeIterator<K, V>(it->getParent()));
            }
            else if (it == it->getParent()->getLeft() and it->getParent() == it->getParent()->getParent()->getLeft())
            {
                this->RotateRight(TreeIterator<K, V>(it->getParent()->getParent()));
                this->RotateRight(TreeIterator<K, V>(it->getParent()));
            }
            else if (it == it->getParent()->getRight() and it->getParent() == it->getParent()->getParent()->getRight())
            {
                this->RotateLeft(TreeIterator<K, V>(it->getParent()->getParent()));
                this->RotateLeft(TreeIterator<K, V>(it->getParent()));
            }
            else if (it == it->getParent()->getRight() and it->getParent() == it->getParent()->getParent()->getLeft())
            {
                this->RotateLeft(TreeIterator<K, V>(it->getParent()));
                this->RotateRight(TreeIterator<K, V>(it->getParent()));
            }
            else
            {
                this->RotateRight(TreeIterator<K, V>(it->getParent()));
                this->RotateLeft(TreeIterator<K, V>(it->getParent()));
            }
        }
    }
};

bool pred1(TreeIterator<string, sportsman> it, string k)
{
    return it->getKey() == k;
}

bool pred2(TreeIterator<string, sportsman> it)
{
    sportsman B1("Ablom", 0, 19, "RS", "voleybol");
    return it->getData() == B1;
}

template<class V>
void print(list<V> l)
{
    typename list<V>::iterator i = l.begin();
    while (i != l.end())
    {
        cout << '\n' << *i;
        i++;
    }
}

int main()
{
    sportsman B("Vinogradov", 3, 19, "RS", "voleybol");
    sportsman B1("Ablom", 0, 19, "RS", "voleybol");
    sportsman B2("Gromov", 10, 19, "RS", "footbool");

    AVL_tree<string, sportsman> test;
    test.push(B.getF(), B);
    test.push(B1.getF(), B1);
    test.push(B2.getF(), B2);
    cout << test;
    TreeIterator<string, sportsman> fn = test.find_key(pred1, "Gromov");
    if (fn.getPtr() != NULL)
        cout << '\n' << *fn;
    TreeIterator<string, sportsman> fv = test.find_value(pred2);
    if (fv.getPtr() != NULL)
        cout << '\n' << *fv;

    Tree<string, sportsman> test2;
    test2.push(B.getF(), B);
    test2.push(B1.getF(), B1);
    test2.push(B2.getF(), B2);
    test2.push(B2.getF(), B2);
    test2.push(B2.getF(), B2);
    cout << '\n' << test2;

    SplayTree<string, sportsman> test3;
    test3.push(B.getF(), B);
    test3.push(B1.getF(), B1);
    test3.push(B2.getF(), B2);
    TreeIterator<string, sportsman> fk = test3["Vinogradov"];
    TreeIterator<string, sportsman> fk2 = test3.find_key(pred1, "Vinogradov");
    cout << '\n' << *fk;
    cout << '\n' << *fk2;
    cout << '\n' << test3;

    char c; cin >> c;
    return 0;
}

