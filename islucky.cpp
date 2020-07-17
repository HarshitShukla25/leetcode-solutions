bool isLucky(int n)
{
	static int count=2; //ek baar define ho gya to fir nhi hota define bhale hi recursive ho skip ho jata hai
	if(count>n)
		return 1;
	if(n%counter==0)
		return 0;
		np = n; //nextposition
		np -= np/counter;
		counter++;
		return islucky(np);
}