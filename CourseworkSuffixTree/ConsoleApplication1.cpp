#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <chrono>
using namespace std;

class Node {
public:
    map<char, Node*> children;
    Node* suffixLink;
    int start;
    int* end;
    int suffixIndex;

    Node(int start, int* end, Node* root) : start(start), end(end), suffixLink(root), suffixIndex(-1) {}

    friend class SuffixTree;
};

class SuffixTree {
private:
    string text;
    Node* root;
    Node* lastNewNode;
    Node* activeNode;
    int activeEdge;
    int activeLength;
    int remainingSuffixCount;
    int leafEnd;
    int* rootEnd;
    int* splitEnd;
    int size;

    Node* newNode(int start, int* end) {
        Node* node = new Node(start, end, root);
        return node;
    }

    inline auto edgeLength(Node* n) {
        return *n->end - n->start + 1;
    }

    inline auto walkDown(Node* currNode) {
        if (activeLength >= edgeLength(currNode)) {
            activeEdge += edgeLength(currNode);
            activeLength -= edgeLength(currNode);
            activeNode = currNode;
            return true;
        }
        return false;
    }

    void extendSuffixTree(int pos) {
        leafEnd = pos;
        remainingSuffixCount++;
        lastNewNode = nullptr;

        // Переменные, которые могут быть вынесены из цикла
        bool conditionCheck = false;
        Node* next = nullptr;
        int* splitEnd = nullptr;

        while (remainingSuffixCount > 0) {
            if (activeLength == 0) activeEdge = pos;
            conditionCheck = conditionCheck = (activeNode->children.find(text[activeEdge]) == activeNode->children.end()) ? true : false;

            if (conditionCheck) {
                auto next = activeNode->children[text[activeEdge]] = newNode(pos, &leafEnd);
                if (lastNewNode != nullptr) {
                    lastNewNode->suffixLink = activeNode;
                    lastNewNode = nullptr;
                }
                remainingSuffixCount--;
            }
            else {
                next = activeNode->children[text[activeEdge]];
                if (walkDown(next)) continue;
                if (text[(next->start) + activeLength] == text[pos]) {
                    switch (lastNewNode != nullptr && activeNode != root)
                    {
                    case true:
                        lastNewNode->suffixLink = activeNode;
                        lastNewNode = nullptr;
                        break;
                    case false:
                        activeLength++;
                        break;
                    }
                    break;
                }

                splitEnd = new int;
                *splitEnd = next->start + activeLength - 1;
                Node* split = newNode(next->start, splitEnd);
                activeNode->children[text[activeEdge]] = split;
                split->children[text[pos]] = newNode(pos, &leafEnd);
                next->start += activeLength;
                split->children[text[next->start]] = next;
                if (lastNewNode != nullptr) lastNewNode->suffixLink = split;
                lastNewNode = split;
                remainingSuffixCount--;
            }
            if (activeNode == root && activeLength > 0) {
                activeLength--;
                activeEdge = pos - remainingSuffixCount + 1;
            }
            else if (activeNode != root) {
                activeNode = activeNode->suffixLink;
            }
        }
    }

    void freeSuffixTreeByPostOrder(Node* n) {
        if (n == nullptr) return;
        for (auto& child : n->children) {
            freeSuffixTreeByPostOrder(child.second);
        }
        if (n->suffixIndex == -1) delete n->end;
        delete n;
    }

    void print(int i, int j, ostream& os) {
        for (int k = i; k <= j; k++) os << text[k];
    }

    void printAllSubstrings(Node* n, ostream& os) {
        if (n == nullptr) return;
        if (n->start != -1) {
            print(n->start, *(n->end), os);
            os << "\n";
        }
        for (auto& child : n->children) {
            printAllSubstrings(child.second, os);
        }
    }

    void printSuffixTree(Node* n, int height, int level, ostream& os) {
        if (n == nullptr) return;
        for (int i = 0; i < level; i++) os << "+-";
        if (n->start != -1) {
            print(n->start, *(n->end), os);
            os << "\n";
        }
        int leaf = 1;
        for (auto& child : n->children) {
            if (child.second) {
                if (leaf == 1 && n->start != -1) {
                    for (int i = 0; i <= level; i++) os << "| ";
                    os << "\n";
                }
                leaf = 0;
                printSuffixTree(child.second, height + edgeLength(child.second), level + 1, os);
            }
        }
        if (leaf == 1) {
            for (int i = 0; i <= level; i++) os << "| ";
            n->suffixIndex = size - height;
            os << "\n";
        }
    }


public:
    SuffixTree() : root(nullptr), lastNewNode(nullptr), activeNode(nullptr),
        activeEdge(0), activeLength(0), remainingSuffixCount(0),
        leafEnd(0), rootEnd(nullptr), splitEnd(nullptr), size(0) {}

    ~SuffixTree() {
        freeSuffixTreeByPostOrder(root);
    }

    void buildSuffixTree(const string& inputText) {
        text = inputText;
        size = text.length();
        rootEnd = new int(-1);
        root = newNode(-1, rootEnd);
        activeNode = root;
        for (size_t i = 0; i < size; i++) extendSuffixTree(static_cast<int>(i));
        int labelHeight = 0;
       // setSuffixIndexByDFS(root, labelHeight);
    }

    bool searchSubstring(const string& substring) {
        Node* currentNode = root;
        int i = 0;
        while (i < substring.size()) {
            if (currentNode->children.find(substring[i]) == currentNode->children.end()) {
                return false;
            }
            Node* nextNode = currentNode->children[substring[i]];
            int j = nextNode->start;
            while (j <= *nextNode->end && i < substring.size()) {
                if (text[j] != substring[i]) {
                    return false;
                }
                i++;
                j++;
            }
            currentNode = nextNode;
        }
        return true;
    }

    void searchSubstringFromConsole() {
        string substring;
        cout << "Введите подстроку для поиска: ";
        cin >> substring;
        getline(cin, substring);

        if (searchSubstring(substring)) {
            cout << "Подстрока " << substring << " найдена в исходной строке.\n";
            printAllSubstrings(root, cout);
        }
        else {
            cout << "Подстрока " << substring << " не найдена в исходной строке.\n";
        }
    }

    friend ostream& operator<<(ostream& os, SuffixTree& st);
    friend istream& operator>>(istream& is, SuffixTree& st);
};

class Timer
{
private:
    using clock_t = chrono::high_resolution_clock;
    using second_t = chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};


void appendToFile(const std::string& file_path) {
    ofstream file(file_path, std::ios::app);

    if (file.is_open()) {
        std::string input;
        std::cout << "Введите текст для добавления в файл (введите 'exit' для завершения):" << std::endl;

        while (true) {
            std::getline(std::cin, input);

            if (input == "exit") {
                break;
            }

            file << input << std::endl;
        }

        file.close();
        std::cout << "Текст успешно добавлен в файл." << std::endl;
    }
    else {
        std::cout << "Не удалось открыть файл." << std::endl;
    }
}

ostream& operator<<(ostream& os, SuffixTree& st) {
    os << "Suffix Tree:\n";
    st.printSuffixTree(st.root, 0, 0, os);
    return os;
}

istream& operator>>(istream& is, SuffixTree& st) {
    auto inputText = string{};
    cout << "Введите строку для построения суффиксного дерева: ";
    getline(is, inputText);
    st.buildSuffixTree(inputText);
    return is;
}


int main() {
    setlocale(LC_ALL, "Rus");
    SuffixTree ST;
    Timer timer;

    string filename;
    cout << "Введите имя файла для записи информации: ";
    cin >> filename;

    int choice;
    string inputText;

    do {
        cout << "Выберите действие:\n"
            << "1. Добавить строку в дерево\n"
            << "2. Найти слово в дереве\n"
            << "3. Вывести содержимое файла\n"
            << "4. Вывести все содержимое дерева\n"
            << "5. Выход\n";

        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Введите строку для добавления в дерево: ";
            cin.ignore();
            getline(cin, inputText);
            timer.reset();
            ST.buildSuffixTree(inputText);
            cout << ST;

            ofstream file("Tree.txt", ios::app);

            if (file.is_open()) {
                file << ST << endl;
                file.close();
                cout << "Дерево успешно добавлено в файл." << endl;
            }
            else {
                cout << "Не удалось открыть файл." << endl;
            }
            cout << "Время выполнения: " << timer.elapsed() << " секунд" << endl;
            cout << std::flush; 
            break;
        }
        case 2: {
            timer.reset();
            ST.searchSubstringFromConsole();
            cout << "Время выполнения: " << timer.elapsed() << " секунд" << endl;
            cout << std::flush; 
            break;
        }
        case 3:
        {
            string filee = "Tree.txt";
            ifstream file(filee);

            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            }
            else {
                cout << "Не удалось открыть файл.\n";
            }
        }
        break;

        case 4:
            cout << ST;
            break;

        case 5:
            cout << "Программа завершена.\n";
            break;

        default:
            cout << "Некорректный ввод. Пожалуйста, выберите действие от 1 до 5.\n";
        }

    } while (choice != 5);

    return 0;
}
