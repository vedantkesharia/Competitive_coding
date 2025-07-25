#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <set>

using namespace std; 


// TrieNode represents each node in the Trie
class TrieNode {
public:
    bool is_end;                        // Marks if a word ends at this node
    vector<TrieNode*> children;         // 26 children (for each lowercase English letter)

    TrieNode() {
        is_end = false;
        children = vector<TrieNode*>(26, NULL); // Initialize children to NULL
    }
};

// Trie class to build the Trie from a list of words
class Trie {
public:
    TrieNode* getRoot() { return root; }

    // Constructor: builds the Trie by inserting all words
    Trie(vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            addWord(words[i]);
    }

    // Inserts a single word into the Trie
    void addWord(const string& word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (cur->children[index] == NULL)
                cur->children[index] = new TrieNode(); // Create node if it doesn't exist
            cur = cur->children[index]; // Move to next character
        }
        cur->is_end = true; // Mark end of word
    }

private:
    TrieNode* root; // Root of the Trie
};

// Main solution class
class Solution {
public:
    // Finds all words in the board that exist in the dictionary
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);             // Build Trie from dictionary
        TrieNode* root = trie->getRoot();         // Get root of Trie
        set<string> result_set;                   // Use set to avoid duplicates

        // Traverse each cell of the board as a potential starting point
        for (int x = 0; x < board.size(); x++)
            for (int y = 0; y < board[0].size(); y++)
                findWords(board, x, y, root, "", result_set); // Perform DFS

        // Convert set to vector
        vector<string> result;
        for (auto it : result_set)
            result.push_back(it);
        return result;
    }

private:
    // Helper DFS function to explore the board
    void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, set<string>& result) {
        // Boundary and visited check
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == ' ')
            return;

        char ch = board[x][y];
        int idx = ch - 'a';

        // If current character not in Trie path, backtrack
        if (root->children[idx] != NULL) {
            word += ch;                            // Append current character to word
            root = root->children[idx];            // Move Trie pointer to next node

            if (root->is_end)                      // Found a word in the Trie
                result.insert(word);               // Add to result set

            board[x][y] = ' ';                     // Mark current cell as visited (in-place)

            // Explore 4 directions: down, up, right, left
            findWords(board, x + 1, y, root, word, result);
            findWords(board, x - 1, y, root, word, result);
            findWords(board, x, y + 1, root, word, result);
            findWords(board, x, y - 1, root, word, result);

            board[x][y] = ch;                      // Restore cell after backtracking
        }
    }
};
