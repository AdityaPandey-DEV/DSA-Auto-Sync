class WordDictionary {
public:
    bool isEndOfWord;
    WordDictionary *child[26];
    WordDictionary() {
        isEndOfWord=false;
        for(auto &c:child){
            c=NULL;
        }
        
    }
    
    void addWord(string word) {
        WordDictionary *curl=this;
        for(auto ch:word){
            int idx=ch-'a';
            if(curl->child[idx]==NULL){
                curl->child[idx]=new WordDictionary();
            }
            curl=curl->child[idx];

        }
        curl->isEndOfWord=true;
        
    }
    
    bool searchHelper(string &word, int pos, WordDictionary* node) {
        if(pos == word.size())
            return node->isEndOfWord;

        char ch = word[pos];

        if(ch == '.') {
            for(int i = 0; i < 26; i++) {
                if(node->child[i] != NULL) {
                    if(searchHelper(word, pos + 1, node->child[i]))
                        return true;
                }
            }
            return false;
        }
        else {
            int idx = ch - 'a';
            if(node->child[idx] == NULL)
                return false;

            return searchHelper(word, pos + 1, node->child[idx]);
        }
    }

    bool search(string word) {
        return searchHelper(word, 0, this);
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */