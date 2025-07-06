class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int i = s.length() - 1;

        // Skip trailing spaces at the end of the string
        while (i >= 0 && s[i] == ' ') i--;

        while (i >= 0) {
            int end = i;

            // Move `i` to the beginning of the current word
            while (i >= 0 && s[i] != ' ') i--;

            // Extract the word from s[i+1] to s[end] and append to result
            res += s.substr(i + 1, end - i);

            // Skip spaces between words
            while (i >= 0 && s[i] == ' ') i--;

            // Add a space if more words remain
            if (i >= 0) res += " ";
        }

        return res;
    }
};
