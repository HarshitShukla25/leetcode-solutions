REmove duplicates so abacd becomes abcd preserving the order

use hash
int i=0;
while(i<s.size())
{
	if(hash[s[i]]==false)
{
	hash[s[i]]=true;
	result+=s[i];
}
i++;
}
