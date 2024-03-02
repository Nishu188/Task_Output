# Longest Compound Word Finder

This program is designed to find the longest and second longest compound words from a list of words provided in a text file. It utilizes a Trie data structure to efficiently determine if a word can be formed by concatenating two or more words from the list.

## How to Use

### Prerequisites

- C++ compiler that supports C++11 or later
- Input text file containing a list of words (e.g., "Input_02.txt" , "Input_01.txt")

### Running the Program

1. Open the terminal or command prompt.
2. Navigate to the directory containing the source code file (`output.cpp`) and the input text file.
3. Compile the source code using the C++ compiler.
4. Run the compiled executable, providing the input text file as an argument.
5. The program will output the longest compound word, the second longest compound word, and the time taken to process the list of words.

## File Structure

- `longest_compound_word.cpp`: C++ source code file containing the implementation of the program.
- `Input_02.txt`: Example input text file containing a list of words.
- `Input_02.txt`: Example input text file containing a list of words.

## Understanding the Code

- `TrieNode` class: Represents a node in the Trie data structure. It contains an unordered map to store child nodes and a boolean flag to mark the end of a word.
- `Trie` class: Implements the Trie data structure and provides functions to insert words into the Trie and find compound words.
- `readWordsFromFile` function: Reads words from a text file and stores them in a vector.
- `main` function: Initializes a Trie, reads words from the input text file, finds the longest and second longest compound words using the Trie, and outputs the results along with the processing time.

## Performance

The program utilizes a Trie data structure to efficiently find compound words. The time complexity for constructing the Trie is O(N * M), where N is the number of words and M is the average length of a word. The time complexity for finding compound words is O(N * M^2), where N is the number of words and M is the maximum length of a word. The actual performance may vary depending on the size of the input and the system's hardware capabilities.

