#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int sumToN(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumToN(n - 1);
}

long long power(int a, int n) {
    if (n == 0) {
        return 1;
    }
    return a * power(a, n - 1);
}

int countDigits(int n) {
    if (n < 10) {
        return 1;
    }
    return 1 + countDigits(n / 10);
}

int sumDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return n % 10 + sumDigits(n / 10);
}

int reverseNumber(int n, int result = 0) {
    if (n == 0) {
        return result;
    }
    return reverseNumber(n / 10, result * 10 + n % 10);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int arraySum(const vector<int>& arr, int index = 0) {
    if (index == (int)arr.size()) {
        return 0;
    }
    return arr[index] + arraySum(arr, index + 1);
}

int findMax(const vector<int>& arr, int index = 0) {
    if (index == (int)arr.size() - 1) {
        return arr[index];
    }
    int maxOfRest = findMax(arr, index + 1);
    return arr[index] > maxOfRest ? arr[index] : maxOfRest;
}

int countOccurrences(const vector<int>& arr, int x, int index = 0) {
    if (index == (int)arr.size()) {
        return 0;
    }
    int match = (arr[index] == x) ? 1 : 0;
    return match + countOccurrences(arr, x, index + 1);
}

bool isPalindrome(const string& s, int left, int right) {
    if (left >= right) {
        return true;
    }
    if (s[left] != s[right]) {
        return false;
    }
    return isPalindrome(s, left + 1, right - 1);
}

string reverseString(const string& s) {
    if (s.empty()) {
        return "";
    }
    return reverseString(s.substr(1)) + s[0];
}

int binarySearch(const vector<int>& arr, int target, int low, int high) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] < target) {
        return binarySearch(arr, target, mid + 1, high);
    }
    return binarySearch(arr, target, low, mid - 1);
}

int hanoi(int n, char from, char to, char helper) {
    if (n == 0) {
        return 0;
    }
    int moves = hanoi(n - 1, from, helper, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    moves++;
    moves += hanoi(n - 1, helper, to, from);
    return moves;
}

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) {
            cout << ", ";
        }
    }
    cout << "]";
}

void subsetsOfSize(const vector<int>& arr, int size, int start, vector<int>& current) {
    if ((int)current.size() == size) {
        printVector(current);
        cout << " ";
        return;
    }
    for (int i = start; i < (int)arr.size(); i++) {
        current.push_back(arr[i]);
        subsetsOfSize(arr, size, i + 1, current);
        current.pop_back();
    }
}

void permutations(const string& s, string& current, vector<bool>& used) {
    if (current.size() == s.size()) {
        cout << current << " ";
        return;
    }
    for (size_t i = 0; i < s.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            current.push_back(s[i]);
            permutations(s, current, used);
            current.pop_back();
            used[i] = false;
        }
    }
}

bool solveMaze(vector<vector<int>>& maze, int row, int col, vector<pair<int, int>>& path) {
    int n = maze.size();
    if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] != 0) {
        return false;
    }
    path.push_back({row, col});
    if (row == n - 1 && col == n - 1) {
        return true;
    }
    maze[row][col] = 2;
    if (solveMaze(maze, row + 1, col, path) ||
        solveMaze(maze, row, col + 1, path) ||
        solveMaze(maze, row - 1, col, path) ||
        solveMaze(maze, row, col - 1, path)) {
        return true;
    }
    maze[row][col] = 0;
    path.pop_back();
    return false;
}

bool isSafe(const vector<int>& queens, int row, int col) {
    for (int r = 0; r < row; r++) {
        int c = queens[r];
        if (c == col || abs(c - col) == row - r) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int n, int row, vector<int>& queens, int& solutionCount) {
    if (row == n) {
        solutionCount++;
        cout << "Solution " << solutionCount << ":" << endl;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                cout << (queens[r] == c ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solveNQueens(n, row + 1, queens, solutionCount);
        }
    }
}

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}

void postorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->value << " ";
}

void deleteTree(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void title(int number, const string& name) {
    cout << endl << "===== " << number << ". " << name << " =====" << endl;
}

int main() {
    title(1, "Factorial");
    cout << "Input: 5" << endl;
    cout << "Output: " << factorial(5) << endl;

    title(2, "Sum of Numbers");
    cout << "Input: 5" << endl;
    cout << "Output: " << sumToN(5) << endl;

    title(3, "Power of a Number");
    cout << "Input: a = 2, n = 5" << endl;
    cout << "Output: " << power(2, 5) << endl;

    title(4, "Count Digits");
    cout << "Input: 58321" << endl;
    cout << "Output: " << countDigits(58321) << endl;

    title(5, "Sum of Digits");
    cout << "Input: 58321" << endl;
    cout << "Output: " << sumDigits(58321) << endl;

    title(6, "Reverse a Number");
    cout << "Input: 12345" << endl;
    cout << "Output: " << reverseNumber(12345) << endl;

    title(7, "Fibonacci Number");
    cout << "Input: 7" << endl;
    cout << "Output: " << fibonacci(7) << endl;
    cout << "Time complexity: O(2^n)" << endl;

    title(8, "Greatest Common Divisor");
    cout << "Input: 48, 18" << endl;
    cout << "Output: " << gcd(48, 18) << endl;

    title(9, "Recursive Array Sum");
    vector<int> sumArray = {2, 4, 6, 8};
    cout << "Input: ";
    printVector(sumArray);
    cout << endl << "Output: " << arraySum(sumArray) << endl;

    title(10, "Find the Maximum Element");
    vector<int> maxArray = {4, 8, 2, 15, 7};
    cout << "Input: ";
    printVector(maxArray);
    cout << endl << "Output: " << findMax(maxArray) << endl;

    title(11, "Count Occurrences");
    vector<int> countArray = {2, 5, 2, 8, 2, 9};
    cout << "Input: ";
    printVector(countArray);
    cout << ", x = 2" << endl;
    cout << "Output: " << countOccurrences(countArray, 2) << endl;

    title(12, "Check for Palindrome");
    string words[] = {"level", "hello"};
    for (const string& word : words) {
        cout << "Input: \"" << word << "\"" << endl;
        cout << "Output: " << (isPalindrome(word, 0, word.size() - 1) ? "true" : "false") << endl;
    }

    title(13, "Reverse a String");
    cout << "Input: \"algorithm\"" << endl;
    cout << "Output: \"" << reverseString("algorithm") << "\"" << endl;

    title(14, "Recursive Binary Search");
    vector<int> sortedArray = {2, 4, 7, 10, 15, 21};
    cout << "Array: ";
    printVector(sortedArray);
    cout << endl << "Target: 15" << endl;
    cout << "Output: Index " << binarySearch(sortedArray, 15, 0, sortedArray.size() - 1) << endl;
    cout << "Time complexity: O(log n)" << endl;

    title(15, "Tower of Hanoi");
    cout << "Input: n = 3" << endl;
    int moves = hanoi(3, 'A', 'C', 'B');
    cout << "Total moves: " << moves << endl;
    cout << "Moves for n disks: 2^n - 1" << endl;

    title(16, "Generate All Subsets");
    vector<int> setArray = {1, 2, 3};
    cout << "Input: ";
    printVector(setArray);
    cout << endl << "Output: ";
    vector<int> currentSubset;
    for (int size = 0; size <= (int)setArray.size(); size++) {
        subsetsOfSize(setArray, size, 0, currentSubset);
    }
    cout << endl;

    title(17, "Generate All Permutations");
    string letters = "ABC";
    string currentPermutation;
    vector<bool> used(letters.size(), false);
    cout << "Input: \"" << letters << "\"" << endl;
    cout << "Output: ";
    permutations(letters, currentPermutation, used);
    cout << endl;

    title(18, "Maze Solver");
    vector<vector<int>> maze = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0},
        {0, 0, 0, 0}
    };
    cout << "Input:" << endl;
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    vector<pair<int, int>> path;
    if (solveMaze(maze, 0, 0, path)) {
        cout << "Output (path): ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << "(" << path[i].first << "," << path[i].second << ")";
            if (i + 1 < path.size()) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout << "Output: no path found" << endl;
    }

    title(19, "N-Queens Problem");
    int n = 4;
    vector<int> queens(n);
    int solutionCount = 0;
    cout << "Input: N = " << n << endl << endl;
    solveNQueens(n, 0, queens, solutionCount);
    cout << "Total solutions: " << solutionCount << endl;

    title(20, "Recursive Binary Tree Traversal");
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(20);
    cout << "Preorder:  ";
    preorder(root);
    cout << endl << "Inorder:   ";
    inorder(root);
    cout << endl << "Postorder: ";
    postorder(root);
    cout << endl;
    deleteTree(root);

    return 0;
}