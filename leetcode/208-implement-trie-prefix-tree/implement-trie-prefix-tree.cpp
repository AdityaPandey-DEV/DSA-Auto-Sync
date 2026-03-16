class Trie {
 public:
  bool isEndOfWord;
  Trie *child[26];
  Trie() {
    isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
      child[i] = NULL;
    }
  }

  void insert(string word) {
    Trie *crawl = this;
    for (auto ch : word) {
      int idx = ch - 'a';
      if (crawl->child[idx] == NULL) {
        crawl->child[idx] = new Trie();
      }
      crawl = crawl->child[idx];
    }
    crawl->isEndOfWord = true;
  }

  bool search(string word) {
    Trie *crawl = this;
    for (auto ch : word) {
      int idx = ch - 'a';
      if (crawl->child[idx] == NULL) {
        return false;
      }
      crawl = crawl->child[idx];
    }
    return crawl->isEndOfWord == true;
  }

  bool startsWith(string prefix) {
    Trie *crawl = this;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */