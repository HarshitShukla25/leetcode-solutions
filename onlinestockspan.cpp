//basic intuition is having the previous greater element 
// jb bhi ese previous greater ki baat aae mn me stack click krna chahie
//maintain the stack in decreasing order
//isse O(n) me hone ka bhut chance ho jata h 
class StockSpanner {
	stack<pair<int,int>> s; //{index,value}
	int index;
public:
    StockSpanner() {
        index=-1;
    }
    
    int next(int price) {
        index+=1;
        while(!s.empty() && s.top().second <= price) 
        	s.pop();
        if(s.empty())
        {
        	s.push({index,price});
        	return index+1;
        }
        int result = s.top().first;
        s.push({index,price});
        return index-result;   
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */