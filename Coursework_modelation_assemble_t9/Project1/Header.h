#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 
#include "MyForm.h"
#include <queue>
#include <unordered_map>

using namespace std;

class erException : public::exception
{
public:
	erException(const string& message) : exception(message.c_str())
	{
	}

};

struct Node {
	string data;
	Node* left;
	Node* right;
	Node(string data) {
		this->data = data;
		left = right = nullptr;
	}
};
class BinaryTree {
private:
	Node* root;

	//поиск куда вставить элемент
	Node* insert(Node* node, string data) {
		if (node == nullptr)
			return new Node(data);
		if (data < node->data)
			node->left = insert(node->left, data);
		else if (data > node->data)
			node->right = insert(node->right, data);
		return node;
	}
	//запись дерева в файл
	void inorder(Node* node, ofstream& file) {
		if (node == nullptr)
			return;
		inorder(node->left, file);
		file << node->data << "\n";
		inorder(node->right, file);
	}

public:
	BinaryTree() {
		root = nullptr;
	}

	void insert(string data) {
		root = insert(root, data);
	}

	void writeToDisk() {
		ofstream file("words.txt", ofstream::app);
		inorder(root, file);
		file.close();
	}
};

void addWordsToBinaryTree(BinaryTree& tree, string words) {
	int i = 0;
	while (i < words.length()) {
		string word = "";
		while (i < words.length() && isalpha(words[i])) {
			word += words[i];
			i++;
		}
		if (word != "") {
			tree.insert(word);
		}
		i++;
	}
}
void readFileToBinaryTree(BinaryTree& tree) {

	ifstream file("words.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			addWordsToBinaryTree(tree, line);
			fstream clear_file("words.txt", ios::out);
			clear_file.close();
		}
		file.close();
	}
}

int minimum(int a, int b, int c)
{
	return min(min(a, b), c);
}

int LevenshteinDistance(const string& word1, const string& word2)
{
	int m = word1.length();
	int n = word2.length();

	// Создаем двумерный вектор размером (m+1)x(n+1) и заполняем его нулями
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	// Инициализируем первую строку и первый столбец
	for (int i = 0; i <= m; i++)
		dp[i][0] = i;
	for (int j = 0; j <= n; j++)
		dp[0][j] = j;

	// Заполняем остальные ячейки таблицы
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (word1[i - 1] == word2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]);
		}
	}

	// Возвращаем значение в нижней правой ячейке таблицы
	return dp[m][n];
}

void LoadFileContentsToTextBox(System::Windows::Forms::TextBox^ textBox4, const string& filename) { //выводим содержимое файла в textBox
	ifstream file(filename);
	if (!file.is_open()) {
		// Обработка ошибки открытия файла
		return;
	}

	string contents;
	string line;
	while (getline(file, line)) {
		contents += " " + line + "\n";
	}

	file.close();

	// Преобразование string в System::String^
	System::String^ textContents = msclr::interop::marshal_as<System::String^>(contents);

	// Запись содержимого файла в TextBox
	textBox4->Text = textContents;
}

struct WordFrequency {
	string word;
	int frequency;

	WordFrequency(const string& w, int f) : word(w), frequency(f) {}
	/*WordFrequency(const string& w) : word(w) {}*/

	bool operator<(const WordFrequency& other) const {
		return frequency < other.frequency; // Сортировка по убыванию
	}
};

unordered_map<string, int> frequencyMap;
priority_queue<WordFrequency> wordQueue;

void SaveWordFrequencies(const unordered_map<string, int>& frequencyMap, const string& filename) {
	ofstream file(filename);
	if (file.is_open()) {
		for (const auto& pair : frequencyMap) {
			file << pair.first << " " << pair.second << endl;
		}
		file.close();
	}
}

void LoadWordFrequencies(unordered_map<string, int>& frequencyMap, const string& filename) {
	ifstream file(filename);
	if (file.is_open()) {
		string word;
		int frequency;
		while (file >> word >> frequency) {
			frequencyMap[word] = frequency;
		}
		file.close();
	}
}

