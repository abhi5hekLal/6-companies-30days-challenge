string encode(string src)
{     
 
  char ch = src[0];
  int curCount = 1;
  string ans;
  
  for(int i = 0; i < src.size() ; i++) {
      if(src[i] != ch) {
        ans += ch + to_string(curCount - 1);
        ch = src[i];
        curCount = 1;
      }
      curCount++;
  }
  
  return ans + ch + to_string(curCount - 1);
}