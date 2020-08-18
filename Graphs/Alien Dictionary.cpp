/*

Ques:- Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
       Note: Many orders may be possible for a particular test case, thus you may return any valid order.
       
Concept:- 1)The idea is to create a graph of characters and then find topological sorting of the created graph. Following are the detailed steps.
          2)Create a graph g with number of vertices equal to the size of alphabet in the given alien language. For example, if the alphabet size is 5, 
          then there can be 5 characters in words. Initially there are no edges in graph.
          3)Do following for every pair of adjacent words in given sorted array.
                  …..a) Let the current pair of words be word1 and word2. One by one compare characters of both words and find the first mismatching characters.
                  …..b) Create an edge in graph from mismatching character of word1 to that of mismatching characters in word 2
          4)Print topological sorting of the above created graph.

*/


void topSort(vector<int> gra[],int inDegree[],string &ans,int K) //standard topological sort algorithm..
{
    queue<int> q1;
    
    for(int i=0;i<K;++i)
    {
        if(inDegree[i] == 0)
        {
            q1.push(i);
        }
    }
    
    while(!q1.empty())
    {
        int vertex = q1.front();
        q1.pop();
        
        ans.push_back(char(vertex)+'a');
        
        for(int i=0;i<gra[vertex].size();++i)
        {
            int child = gra[vertex][i];
            
            --inDegree[child];
            
            if(inDegree[child] == 0)
            q1.push(child);
        }
    }
}

string findOrder(string dict[], int N, int K) {
    // Your code here
    vector<int> gra[K];
    int inDegree[K] = {0};
    
    for(int i=0;i<N-1;++i)
    {
        string t1 = dict[i];
        string t2 = dict[i+1];
        
        for(int j=0;j<min(t1.size(),t2.size());++j)
        {
            if(t1[j] != t2[j])
            {
                gra[t1[j]-'a'].push_back(t2[j]-'a'); //creating the graph of mismatching characters
                ++inDegree[t2[j]-'a'];
                break;
            }
        }
    }
    
    string ans;
    
    topSort(gra,inDegree,ans,K);
    
    return ans;
}
