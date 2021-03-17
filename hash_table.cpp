#include <iostream>
#include <string>

using namespace std;

struct Table_Elements {
    int label;
    int index_tl;
    int next;
};

class Hash{
private:
    Table_Elements* hash_arr;
    int n;
public:
    Hash()
    {
        n = 500;
        hash_arr = new Table_Elements[n];
        for (int i = 0; i < n; ++i)
        {
            hash_arr[i].label = hash_arr[i].index_tl = -1;
            hash_arr[i].next = 0;
        }
    }
    int hashf(int L) { return L % 100 + 1; }
    int find(int key)//??
    {
        int i = hashf(key);
        while (hash_arr[i].next != 0)
        {
            if (hash_arr[i].label == i)
                return i;
            i = hash_arr[i].next;
        }
    }
    bool add(int l, int itl)
    {
        int i = find(l);
        if(i!=)
    }
};


int main()
{
    
}

