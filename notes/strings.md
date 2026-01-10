# String Algorithms

## Introduction

String algorithms are essential for text processing, pattern matching, and parsing problems in competitive programming.

**Key Algorithms:**
- KMP (Knuth-Morris-Pratt)
- Rabin-Karp (Rolling Hash)
- Trie Data Structure
- Z-Algorithm
- Manacher's Algorithm
- String Matching Patterns

---

## KMP Algorithm (Knuth-Morris-Pratt)

Efficient pattern matching algorithm using failure function (LPS array).

### Understanding LPS (Longest Proper Prefix which is also Suffix)

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

// Build LPS array
vector<int> buildLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}

// KMP Search
vector<int> kmpSearch(string text, string pattern) {
    vector<int> result;
    vector<int> lps = buildLPS(pattern);
    
    int n = text.length();
    int m = pattern.length();
    int i = 0, j = 0;  // i for text, j for pattern
    
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        
        if (j == m) {
            result.push_back(i - j);  // Found at index i - j
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return result;
}
```

#### Python Implementation
```python
def build_lps(pattern):
    m = len(pattern)
    lps = [0] * m
    length = 0
    i = 1
    
    while i < m:
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    
    return lps

def kmp_search(text, pattern):
    result = []
    lps = build_lps(pattern)
    
    n, m = len(text), len(pattern)
    i = j = 0  # i for text, j for pattern
    
    while i < n:
        if text[i] == pattern[j]:
            i += 1
            j += 1
        
        if j == m:
            result.append(i - j)  # Found at index i - j
            j = lps[j - 1]
        elif i < n and text[i] != pattern[j]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    
    return result
```

**Time Complexity:** O(n + m)  
**Space Complexity:** O(m)

---

## Rabin-Karp Algorithm (Rolling Hash)

Pattern matching using hash functions with rolling hash technique.

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

const int BASE = 256;
const int MOD = 101;  // Prime number for modulo

// Rabin-Karp with single hash
vector<int> rabinKarp(string text, string pattern) {
    vector<int> result;
    int n = text.length();
    int m = pattern.length();
    
    if (m > n) return result;
    
    // Calculate hash of pattern and first window
    int patternHash = 0, windowHash = 0;
    int h = 1;
    
    // h = BASE^(m-1) % MOD
    for (int i = 0; i < m - 1; i++) {
        h = (h * BASE) % MOD;
    }
    
    // Calculate initial hashes
    for (int i = 0; i < m; i++) {
        patternHash = (BASE * patternHash + pattern[i]) % MOD;
        windowHash = (BASE * windowHash + text[i]) % MOD;
    }
    
    // Slide window and check hash
    for (int i = 0; i <= n - m; i++) {
        if (patternHash == windowHash) {
            // Check for actual match (to handle hash collisions)
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result.push_back(i);
            }
        }
        
        // Calculate hash for next window
        if (i < n - m) {
            windowHash = (BASE * (windowHash - text[i] * h) + text[i + m]) % MOD;
            if (windowHash < 0) {
                windowHash += MOD;
            }
        }
    }
    
    return result;
}
```

**Time Complexity:** O(n + m) average, O(n × m) worst case  
**Space Complexity:** O(1)

---

## Trie Data Structure

Efficient data structure for storing and searching strings.

### Trie Implementation

#### C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word
    void insert(string word) {
        TrieNode* node = root;
        
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        
        node->isEndOfWord = true;
    }
    
    // Search a word
    bool search(string word) {
        TrieNode* node = root;
        
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        
        return node->isEndOfWord;
    }
    
    // Check if prefix exists
    bool startsWith(string prefix) {
        TrieNode* node = root;
        
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        
        return true;
    }
};
```

#### Python Implementation
```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word):
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_end_of_word = True
    
    def search(self, word):
        node = self.root
        for ch in word:
            if ch not in node.children:
                return False
            node = node.children[ch]
        return node.is_end_of_word
    
    def starts_with(self, prefix):
        node = self.root
        for ch in prefix:
            if ch not in node.children:
                return False
            node = node.children[ch]
        return True
```

**Time Complexity:**  
- Insert: O(m) where m is word length
- Search: O(m)
- Prefix Search: O(m)

**Space Complexity:** O(ALPHABET_SIZE × N × M) where N is number of words, M is average length

---

## Palindrome Problems

### Check if String is Palindrome

#### C++ Implementation
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}
```

### Longest Palindromic Substring (Manacher's Algorithm)

#### C++ Implementation (Expansion around centers)
```cpp
string longestPalindrome(string s) {
    if (s.empty()) return "";
    
    int start = 0, maxLen = 1;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        // Odd length palindromes
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
        
        // Even length palindromes
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }
    
    return s.substr(start, maxLen);
}
```

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

---

## String Matching Patterns

### Valid Anagram

#### C++ Implementation
```cpp
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    
    vector<int> count(26, 0);
    
    for (char ch : s) {
        count[ch - 'a']++;
    }
    
    for (char ch : t) {
        count[ch - 'a']--;
        if (count[ch - 'a'] < 0) {
            return false;
        }
    }
    
    return true;
}
```

### Group Anagrams

#### C++ Implementation
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    
    for (string str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        groups[key].push_back(str);
    }
    
    vector<vector<string>> result;
    for (auto& pair : groups) {
        result.push_back(pair.second);
    }
    
    return result;
}
```

### Longest Common Prefix

#### C++ Implementation
```cpp
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    
    string prefix = strs[0];
    
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) return "";
        }
    }
    
    return prefix;
}
```

---

## String Manipulation

### Reverse Words in String

#### C++ Implementation
```cpp
string reverseWords(string s) {
    // Remove extra spaces
    string cleaned;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ' || (i > 0 && s[i-1] != ' ')) {
            cleaned += s[i];
        }
    }
    
    // Trim leading/trailing spaces
    if (cleaned[0] == ' ') cleaned = cleaned.substr(1);
    if (cleaned.back() == ' ') cleaned.pop_back();
    
    // Reverse entire string
    reverse(cleaned.begin(), cleaned.end());
    
    // Reverse each word
    int start = 0;
    for (int i = 0; i <= cleaned.length(); i++) {
        if (i == cleaned.length() || cleaned[i] == ' ') {
            reverse(cleaned.begin() + start, cleaned.begin() + i);
            start = i + 1;
        }
    }
    
    return cleaned;
}
```

### Valid Parentheses

#### C++ Implementation (Using Stack)
```cpp
bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> mapping = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    
    for (char ch : s) {
        if (mapping.find(ch) != mapping.end()) {
            if (st.empty() || st.top() != mapping[ch]) {
                return false;
            }
            st.pop();
        } else {
            st.push(ch);
        }
    }
    
    return st.empty();
}
```

---

## Complexity Analysis

### Time Complexity
- **KMP:** O(n + m)
- **Rabin-Karp:** O(n + m) average, O(n × m) worst
- **Trie Insert/Search:** O(m) where m is string length
- **Palindrome Check:** O(n)
- **Longest Palindrome:** O(n²) or O(n) with Manacher's

### Space Complexity
- **KMP:** O(m) for LPS array
- **Rabin-Karp:** O(1)
- **Trie:** O(ALPHABET_SIZE × N × M)
- **Most string operations:** O(n) for result

---

## Quick Reference

### Algorithm Selection Guide
- **Pattern matching** → KMP or Rabin-Karp
- **Multiple pattern search** → Trie or Aho-Corasick
- **Palindrome problems** → Two pointers or Manacher's
- **String validation** → Stack or counting
- **Anagram problems** → Sorting or frequency counting

### Common Patterns
1. **Pattern matching** → KMP (most efficient)
2. **Multiple strings** → Trie structure
3. **Palindrome** → Expansion or two pointers
4. **Anagrams** → Sorting or frequency map
5. **Valid parentheses** → Stack

---

## Practice Problems

### Easy
- Valid Anagram
- Valid Parentheses
- Longest Common Prefix
- Reverse Words in String

### Medium
- Group Anagrams
- Longest Palindromic Substring
- Word Break
- Implement Trie
- Repeated DNA Sequences

### Hard
- Edit Distance
- Minimum Window Substring
- Word Ladder II
- Shortest Palindrome
- Palindrome Partitioning II

---

## External Resources

- [GeeksforGeeks String Algorithms](https://www.geeksforgeeks.org/string-algorithms/)
- [CP Algorithms String Hashing](https://cp-algorithms.com/string/string-hashing.html)
- [LeetCode String Explore](https://leetcode.com/tag/string/)

---

_Last updated: January 2026_

