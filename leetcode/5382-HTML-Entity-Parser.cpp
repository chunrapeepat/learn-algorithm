class Solution {
public:
    string entityParser(string text) {
        const int n = text.length();
        string q = "";
        string res = "";
        bool isStore = false;
        for (int i = 0; i < n; ++i) {
            if (text[i] == '&') {
                isStore = true;
                q = "";
                continue;
            }
            if (isStore && text[i] != ';') {
                q += text[i];
                continue;
            }
            if (text[i] == ';') {
                if (q.compare("quot") == 0) {
                    res += '""';
                } else if (q.compare("apos") == 0) {
                    res += '\'';
                } else if (q.compare("amp") == 0) {
                    res += '&';
                } else if (q.compare("gt") == 0) {
                    res += '>';
                } else if (q.compare("lt") == 0) {
                    res += '<';
                } else if (q.compare("frasl") == 0) {
                    res += '/';
                } else {
                    res += '&';
                    res += q;
                    res += ';';
                }
                isStore = false;
                q = "";
            } else {
                res += text[i];
            }
        }
        res += q;
        return res;
    }
};