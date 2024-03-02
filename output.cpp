#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Trie node structure
class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // Map to store child nodes
    bool isEnd; // Flag to mark end of word

    // Constructor to initialize TrieNode
    TrieNode() : isEnd(false) {}
};

// Trie data structure
class Trie {
public:
    TrieNode* root; // Root node of the trie

    // Constructor to initialize Trie
    Trie() {
        root = new TrieNode();
    }

    // Function to insert a word into the trie
    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children.count(c)) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEnd = true; // Mark the last node as end of word
    }

    // Function to check if a word can be formed by concatenating two or more words from the trie
    bool isCompound(const string& word, int startIdx, int wordCount) {
        if (startIdx == word.length())
            return wordCount >= 2;

        TrieNode* current = root;
        for (int i = startIdx; i < word.length(); ++i) {
            if (!current->children.count(word[i]))
                return false;
            current = current->children[word[i]];
            if (current->isEnd && isCompound(word, i + 1, wordCount + 1))
                return true;
        }
        return false;
    }

    // Function to find the longest and second longest compound words in the given vector of words
    pair<string, string> findLongestCompoundedWords(const vector<string>& words) {
        string longestWord = "", secondLongestWord = "";

        // Insert all words into the trie
        for (const string& word : words) {
            insert(word);
        }

        // Iterate through each word in the vector
        for (const string& word : words) {
            // Check if the current word is a compound word
            if (isCompound(word, 0, 0)) {
                // Update longest and second longest compound words
                if (word.length() > longestWord.length()) {
                    secondLongestWord = longestWord;
                    longestWord = word;
                } else if (word.length() > secondLongestWord.length()) {
                    secondLongestWord = word;
                }
            }
        }

        return {longestWord, secondLongestWord};
    }
};

// Function to read words from a file and store them in a vector
vector<string> readWordsFromFile(const string& filename) {
    vector<string> words;
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        string word;
        while (inputFile >> word) {
            words.push_back(word);
        }
        inputFile.close();
    } else {
        cerr << "Error: Unable to open file " << filename << endl;
    }
    return words;
}

int main() {
    Trie trie;
    vector<string> inputWords = readWordsFromFile("Input_02.txt");

    string longestCompound, secondLongestCompound;
    auto startTime = high_resolution_clock::now();
    tie(longestCompound, secondLongestCompound) = trie.findLongestCompoundedWords(inputWords);
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    // Output the longest and second longest compound words along with processing time
    cout << "Longest Compound Word: " << longestCompound << endl;
    cout << "Second Longest Compound Word: " << secondLongestCompound << endl;
    cout << "Time taken to process: " << duration.count() << " microseconds" << endl;

    return 0;
}
