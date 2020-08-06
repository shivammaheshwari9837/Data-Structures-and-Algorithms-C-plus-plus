/*

Ques :- Flattening a linked list...Time=(n*m), where n is total number of liner chain elements while m is different sized bottom chain...

Concept:- 1. take two nodes and merge it...


*/

Node* merge(Node *h1,Node *h2)
{
    //Base...
    if(h1 == NULL)
    return h2;
    if(h2 == NULL)
    return h1;
    
    //Induction..
    if(h1->data < h2->data)
    {
        h1->bottom = merge(h1->bottom,h2);
        return h1;
    }
    else
    {
        h2->bottom = merge(h2->bottom,h1);
        return h2;
    }
}
    
Node *flatten(Node *root)
{
   // Your code here
   Node *a = root;
   Node *b = root->next;
   Node *c;
   
   while(b!=NULL)
   {
       c = b->next;
       a=merge(a,b);
       b = c;
   }
   
   return a;
}
