//XOr without using XOR

int xor(int a, int b)
{
	for(i=31;i>=0;i--)
	{
		bool b1= a & (1<<i);
		bool b2= b & (1<<i);
		bool xorbit = (b1&b2)?0:(b1|b2);
		result <<= 1;
		result |= xorbit;
	}
	return result;
	//better solution;
	return (~x|~y) & (x|y);
}