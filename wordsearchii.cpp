class Trie{
public:
    Trie* children[26];
    bool leaf;
    Trie(){
        memset(children, NULL, sizeof(children));
        leaf = false;
    }
};
class Solution {
private:
    Trie* root = new Trie();
    int row = 0, col = 0;
public:
    void buildTrie(vector<string> & words){
        for(string word : words){
            Trie* node = root;
            for(char c : word){
                if(!node -> children[c - 'a'])
                    node -> children[c - 'a'] = new Trie();
                node = node -> children[c - 'a'];
            }
            node -> leaf = true;
        }
    }
    void dfs(vector<vector<char>> & board, Trie* node, string build, vector<string> & res, int i, int j)
    {
        if(i < 0 || j < 0 || i >= row || j >= col)
            return;
        if(board[i][j] == 'F'){
            return;
        }
        if(!node -> children[board[i][j] - 'a']){
            return;
        }
                
                build = build + board[i][j];
                node = node -> children[board[i][j] - 'a'];
                if(node -> leaf){
                    node -> leaf = false;
                    res.push_back(build);
                }
                char temp = board[i][j];
                board[i][j] = 'F';
                dfs(board, node, build, res, i + 1, j);
                dfs(board, node, build, res, i - 1, j);
                dfs(board, node, build, res, i, j + 1);
                dfs(board, node, build, res, i, j - 1);
                board[i][j] = temp; 

                

    }
        
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        buildTrie(words);
        vector<string> res;
        row = board.size(), col = board[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++)
            {
                dfs(board, root, "", res, i, j);
            }
        }
        
        return res;
    }
};