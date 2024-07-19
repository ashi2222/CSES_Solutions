
class Node 
{

    public : 
    
    Node* links[2];
    //bool flag = false;
    bool containsKey(int num)
    {
        return (links[num] != NULL);
    }

    void put(int num , Node*node)
    {
        links[num] = node;
    }
    Node *get(int num) { return links[num]; }
};


class Trie 
{
    private : Node * root;
    public : 
    Trie()
    {
        root = new Node();
    }

    // tc - O(n)
    void insert(int number)
    {
        Node*node = root;
        int tempnum = number;
        for(int i = 31 ; i >=0 ; i--)
        {
            int bit = (tempnum >> i) & 1;
            if(!node->containsKey(bit))
            {
                node->put(bit , new Node());
            }
            node = node->get(bit);
        }
        //node->setEnd();
    }

    int search(int number)
    {
        Node*node = root;
        int tempnum = number;
        int ans =0 ;
        for(int i = 31 ; i>=0 ; i--)
        {
            int bit = (tempnum >> i) & 1;
            if(node->containsKey(1-bit))
            {
                ans = ans | (1<<i);
                node = node->get((1-bit));
            }
            else{
                node = node->get(bit);
            } 
        }
        return ans;
       
    }
};

