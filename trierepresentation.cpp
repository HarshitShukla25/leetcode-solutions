class TrieNode {
	public:
	bool end;
	TrieNode* children[27];
	TrieNode()
	{
	end= false;
	memset(children,NULL,sizeof(children));
	}
}
TrieNode* root =new TrieNode();
void insert(string word)
{
	TrieNode* node = root;
	for(char c: word)
	{
		if(!node -> children[c-'a'])
		{
			node -> children[c-'a'] = new TrieNode();
		}
	}
	node -> end  =true;
}
bool search(string word)
{
	TrieNode* node = root;
	for(char c: word)
	{
		if(!node -> children[c-'a'])
			return false;
		node = node -> children[c-'a'];
	}
	return node->end;
}