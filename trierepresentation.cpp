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