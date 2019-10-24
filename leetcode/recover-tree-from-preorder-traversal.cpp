/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        stack<pair<int, TreeNode*>> stk;
        int num = 0;
        int level = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] >= '0' && S[i] <= '9') {
                num *= 10;
                num += S[i] - '0';

                if (i + 1 >= S.size() || S[i + 1] == '-') {
                    if (stk.empty())
                        stk.push({level, new TreeNode(num)});
                    else {
                        TreeNode* n = new TreeNode(num);
                        pair<int, TreeNode*> top = stk.top();
                        if (level <= top.first) {
                            while (stk.top().first >= level && !stk.empty()) {
                                stk.pop();
                            }
                            top = stk.top();
                        }
                        cout << level << " " << n->val << " top:" << top.second->val << endl;
                        stk.push({level, n});
                        if (top.second->left == NULL) {
                            top.second->left = n;
                        } else {
                            top.second->right = n;
                        }
                    }
                }
            } else {
                if (num != 0) {
                    num = 0;
                    level = 0;
                }
                ++level;
            }
        }
        while (stk.size() > 1) stk.pop();
        return stk.top().second;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
        return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);

        TreeNode* ret = Solution().recoverFromPreorder(S);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}