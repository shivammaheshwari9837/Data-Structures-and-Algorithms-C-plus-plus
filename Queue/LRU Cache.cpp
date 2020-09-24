/*

Concept:- 1)Simple intutive solution using a hashmap and a doubly linked list. Use stl to create both.
          2)Now we can do insertion, deletion in doubly linked list in 0(1). So our put function will work find.
          3)But to search an element, doubly linked list will take 0(n) time.
          4)In order to reduce it, we will use a hash map to find the element. So our get will also work in 0(1).
          5)Hashmap has <int, iterator> as the argument. So basically for each key,
          6)we will store its corresponding pointer in the doubly linked list.
          7)Which will help us to update the linked list in 0(1) as we have the iterator. 
          
Time - O(1) of both get and set function

*/

class LRUCache
{
private:
    int size;
    list<pair<int, int>>dll;   //A doubly linked list
    unordered_map<int, list<pair<int, int>>::iterator>mp; //A hashmap

public:
    LRUCache(int cap)
    {
        // constructor for cache
        size = cap;    //Initializing size with capacity.
    }
    
    int get(int key)
    {
        // this function should return value corresponding to key
        if(mp.find(key) != mp.end())  //If the element is alreday present. We must make it the most recent element and return the value.
        {
            auto ptr = mp[key];         //We have to update our doubly linked list. 
            int value = ptr->second;
            dll.erase(ptr);             //Removing the element from dll. 
            dll.push_front({key, value});  //And now making it the most recently called.
            mp[key] = dll.begin();        //Updating the pointer in the map. 
            
            return value;
        }else
            return -1;
    }
    
    void set(int key, int value)
    {
        // storing key, value pair
        if(mp.find(key) == mp.end())     //check if the elem is not present in the dll
        {
            if(dll.size() == size)       //If the size of dll has reached the capacity, remove the lru elem. 
            {
                auto ptr = dll.end();
                ptr--;   //since end() points to after the last element
                mp.erase(ptr->first);
                dll.pop_back();
            }
        }else{                            //If the elem is already present, then again remove it from dll
            dll.erase(mp[key]);
        }
        
        dll.push_front({key, value});       //Add the elem to start of the dll(most recently used elem).
        mp[key] = dll.begin();           
    }
};
