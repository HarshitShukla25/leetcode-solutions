Removingadjacentduplicatesinstring


void removeadj(string s)
{
	int i=0;
	while(s[i])
	{
		if(s[i+1]&&s[i]!=s[i+1])
		{
			res+=s[i];
			i++;
		}
		if(s[i+1]&& s[i]==s[i+1])
		{
			while(s[i+1]&& s[i]==s[i+1])
			i++;
			i++;
		}
	}
}