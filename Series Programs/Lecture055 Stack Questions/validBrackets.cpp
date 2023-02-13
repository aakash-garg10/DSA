class Solution {
public:
    bool isValid(string expression) {
         stack<char> s;
     for(int i=0; i<expression.length(); i++) {         
         char ch = expression[i];
         
         //if opening bracket, stack push
         //if close bracket, stacktop check and pop
         
         if(ch == '(' || ch == '{' || ch == '['){
             s.push(ch);
         }
         else
         {
             //for closing bracket
             if(!s.empty()) {  //checking whether the stack is empty or not
                  char top = s.top();
                  if( (ch == ')' && top == '(') || 
                     ( ch == '}' && top == '{') || 
                     (ch == ']' && top == '[') ) {
                      s.pop();
                  }
                 else   return false;
             }
             //stack pehle hi empty h toh closing bracket jo mila h woh xtra h
             else   return false;
         }  
     }
    //poori string ko traverse karne k baad
    if(s.empty())   return true;
    else    return false;
    }
};