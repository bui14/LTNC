#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'crosswordPuzzle' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY crossword
 *  2. STRING words
 */

bool checkHorizontalFit(const vector<std::string>& puzzle, int row, int col, const string& word) {
   int wordLen = word.length();
   if (col + wordLen > 10) {
       return false;
   }
   for (int i = 0; i < wordLen; ++i) {
       if (puzzle[row][col + i] != '-' && puzzle[row][col + i] != word[i]) {
           return false;
       }
   }
   return true;
}

bool checkVerticalFit(const vector<string>& puzzle, int row, int col, const string& word) {
   int wordLen = word.length();
   if (row + wordLen > 10) {
       return false;
   }
   for (int i = 0; i < wordLen; ++i) {
       if (puzzle[row + i][col] != '-' && puzzle[row + i][col] != word[i]) {
           return false;
       }
   }
   return true;
}

void placeWordHorizontal(vector<string>& puzzle, int row, int col, const string& word) {
   int wordLen = word.length();
   for (int i = 0; i < wordLen; ++i) {
       puzzle[row][col + i] = word[i];
   }
}

void placeWordVertical(vector<string>& puzzle, int row, int col, const string& word) {
   int wordLen = word.length();
   for (int i = 0; i < wordLen; ++i) {
       puzzle[row + i][col] = word[i];
   }
}

bool solvePuzzle(vector<string>& puzzle, const vector<string>& words, int wordIndex) {
   if (wordIndex == words.size()) {
       return true;
   }

   string word = words[wordIndex];
   for (int row = 0; row < 10; ++row) {
       for (int col = 0; col < 10; ++col) {
           if (puzzle[row][col] == '-' || puzzle[row][col] == word[0]) {
               if (checkHorizontalFit(puzzle, row, col, word)) {
                   vector<string> oldState = puzzle;
                   placeWordHorizontal(puzzle, row, col, word);
                   if (solvePuzzle(puzzle, words, wordIndex + 1)) {
                       return true;
                   }
                   puzzle = oldState;
               }
               if (checkVerticalFit(puzzle, row, col, word)) {
                   vector<string> oldState = puzzle;
                   placeWordVertical(puzzle, row, col, word);
                   if (solvePuzzle(puzzle, words, wordIndex + 1)) {
                       return true;
                   }
                   puzzle = oldState;
               }
           }
       }
   }

   return false;
}

vector<string> crosswordPuzzle(const vector<string>& crossword, const string& words) {
   vector<string> puzzle = crossword;
   vector<string> wordList;
   istringstream iss(words);
   string word;
   while (getline(iss, word, ';')) {
       wordList.push_back(word);
   }

   solvePuzzle(puzzle, wordList, 0);

   return puzzle;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

