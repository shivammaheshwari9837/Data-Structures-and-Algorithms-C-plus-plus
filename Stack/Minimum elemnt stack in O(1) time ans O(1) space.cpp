/*

Ques :- Minimum elemnt stack in O(1) time ans O(1) space

Concept:- 1.)  Push(x) : Inserts x at the top of stack.

If stack is empty, insert x into the stack and make minEle equal to x.
If stack is not empty, compare x with minEle. Two cases arise:
If x is greater than or equal to minEle, simply insert x.
If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x.


	2.)   Pop() : Removes an element from top of stack.
    Remove element from top. Let the removed element be y. Two cases arise:
  If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
  If y is less than minEle, the minimum element now becomes (2*minEle – y), update (minEle = 2*minEle – y). Now retrieve previous minimum from current minimum 
  and its value in stack.


*/

int minEle;

int _stack :: getMin()
{
   //Your code here
   if(s.size() == 0)
   return -1;
   
   return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.size() == 0)
   return -1;
   else
   {
       int temp1;
       if(s.top()<minEle)
       {
           temp1 = minEle;
           minEle = 2*minEle - s.top();
           s.pop();
       }
       else 
       {
           temp1 = s.top();
           s.pop();
       }
       return temp1;
   }
   
}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.size() == 0)
   {
       minEle = x;
       s.push(x);
   }
   else
   {
       if(x>=minEle)
       s.push(x);
       else
       {
           s.push(2*x - minEle);
           minEle=x;
       }
   }
}
