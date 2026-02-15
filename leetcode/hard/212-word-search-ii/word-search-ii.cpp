class Solution {
  class Trie {
   public:
    bool isEndOfWord;
    Trie* child[26];
    string word;
    Trie() {
      isEndOfWord = false;
      for (int i = 0; i < 26; i++) {
        child[i] = NULL;
      }
      word = "";
    }

    void insert(string word) {
      Trie* crawl = this;
      for (auto ch : word) {
        int idx = ch - 'a';
        if (crawl->child[idx] == NULL) {
          crawl->child[idx] = new Trie();
        }
        crawl = crawl->child[idx];
      }
      crawl->isEndOfWord = true;
      crawl->word = word;
    }

    bool search(string word) {
      Trie* crawl = this;
      for (auto ch : word) {
        int idx = ch - 'a';
        if (crawl->child[idx] == NULL) {
          return false;
        }
        crawl = crawl->child[idx];
      }
      return crawl->isEndOfWord;
    }

    bool startsWith(string prefix) {
      Trie* crawl = this;
      for (auto ch : prefix) {
        int idx = ch - 'a';
        if (crawl->child[idx] == NULL) {
          return false;
        }
        crawl = crawl->child[idx];
      }
      return true;
    }
  };
  int n, m;
  int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  vector<string> result;
  void findWord(vector<vector<char>>& board, int i, int j, Trie* root) {
    int n = board.size();
    int m = board[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m) {
      return;
    }
    if (board[i][j] == '$' || root->child[board[i][j] - 'a'] == NULL) {
      return;
    }
    root = root->child[board[i][j] - 'a'];
    if (root->isEndOfWord == true) {
      result.push_back(root->word);
      root->isEndOfWord = false;
    }
    char temp = board[i][j];
    board[i][j] = '$';
    for (auto d : dir) {
      findWord(board, i + d[0], j + d[1], root);
    }
    board[i][j] = temp;
  }

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie* root = new Trie();

    for (int i = 0; i < words.size(); i++) {
      root->insert(words[i]);
    }
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char ch = board[i][j];
        if (root->child[ch - 'a'] != NULL) {
          findWord(board, i, j, root);
        }
      }
    }
    return result;
  }
};