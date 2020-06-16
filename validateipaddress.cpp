class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.size()>39) return "Neither";
        int v4=0,v6=0;
        for(int i=0;i<IP.size();i++)
        {
            if(IP[i]=='.') v4++;
            else if(IP[i]==':') v6++;
        }
        if(v4==3 && v6==0)
        {   vector<string> v;
            string temp="";
          unordered_set<char> ss = {'0','1','2','3','4','5','6','7','8','9'};
            for(int i=0;i<IP.size();i++)
            {   
                if(IP[i]=='.')
                {
                    v.push_back(temp);
                    temp ="";
                }
                else
                temp=temp+IP[i];
            }
            v.push_back(temp);
            bool flag=1;
            if(v.size()!=4) return "Neither";
            for(int i=0;i<v.size();i++)
            {
                if(v[i].size()==0) return "Neither";
                if(v[i][0]=='0' && v[i].size()>1)
                    return "Neither";
                for(int j=0;j<v[i].size();j++)
                {
                    if(!(ss.count(v[i][j])))
                    {
                        return "Neither";
                    }
                }
                int t = stoi(v[i]);
                if(t<0 || t>255) {return "Neither";}
            }
            
            return "IPv4";
        }
         else if(v6==7 && v4==0)
        {
            unordered_set<char> s = {'a','A','b','B','c','C','d','D','e','E','f','F','0','1','2','3','4','5','6','7','8','9'};
             vector<string> v;
            string temp="";
            for(int i=0;i<IP.size();i++)
            {   
                if(IP[i]==':')
                {
                    v.push_back(temp);
                    temp ="";
                }
                else
                temp=temp+IP[i];
            }
             v.push_back(temp);
            if(v.size()!=8) return "Neither";
            bool flag=1;
             
            for(int i=0;i<v.size();i++)
            {
                
                if(v[i].size()==0 || v[i].size()>4) return "Neither";
                
                for(int j=0;j<v[i].size();j++)
                {
                    if(!(s.count(v[i][j])))
                    {flag=0;break;} 
                }
                if(flag==0) return "Neither";
           
            }
              return "IPv6";
        }
        
        return "Neither";
      
    }
    
};