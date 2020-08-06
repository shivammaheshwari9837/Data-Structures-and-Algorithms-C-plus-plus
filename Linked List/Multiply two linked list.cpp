/*

Ques :- Multiply two linked list in O(1) space..

*/

long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  Node *p = l1;
  ll n1 = 0,n2 = 0;
  
  while(p!=NULL)
  {
      n1 = ((n1*10)%mod + (p->data)%mod)%mod;
      p = p->next;
  }
  
  p = l2;
  
  while(p!=NULL)
  {
      n2 = ((n2*10)%mod + (p->data)%mod)%mod;
      p = p->next;
  }
  
  ll val = (n1%mod * n2%mod)%mod;
  return val;
}
