/* ------------------------------------------------------------------|
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 

提示：

0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/edit-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	dp法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.1 MB, 在所有 C++ 提交中击败了81.94%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    if (!(n*m)) {
        return m + n;
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m + 1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j < n + 1; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            int up = dp[i - 1][j] + 1;
            int left = dp[i][j - 1] + 1;
            int left_up = dp[i - 1][j - 1] + 1;

            if (word1[i - 1] == word2[j - 1]) {
                left_up -= 1;
            }
            dp[i][j] = min(left, min(left_up, up));
        }
    }
    return dp[m][n];
}