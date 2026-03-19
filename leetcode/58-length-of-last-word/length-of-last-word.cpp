class Solution {
public:
    int lengthOfLastWord(string s) {

        while(!s.empty() && s.back() == ' '){
            s.pop_back();
        }

        int count = 0;

        for(int i = s.length() - 1; i >= 0 && s[i] != ' '; i--){
            count++;
        }

        return count;
    }
};