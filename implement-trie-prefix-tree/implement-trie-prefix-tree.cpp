class Trie {
public:
    Trie * arr[26];
    bool flag;
    Trie() {
        memset(arr,NULL,sizeof(arr));
        flag = false;
    }
    
    bool contains(char ch)
    {
        return (arr[ch-'a']!=NULL);
    }
    
    Trie * getNext(char ch)
    {
        return arr[ch-'a'];
    }
    
    void insert(string word) {
        Trie * temp = this;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->contains(word[i]))
            // if(temp->arr[word[i]-'a']==NULL)
            {
                Trie* newNode = new Trie();
                // temp->put(word[i],newNode);
                temp->arr[word[i]-'a'] = newNode;
            }
            // temp = temp->getNext(word[i]);
            temp = temp->arr[word[i]-'a'];
        }
        temp->flag = true;
        
    }
    
    bool search(string word) {
        Trie * temp = this;
        
        for(int i=0;i<word.size();i++)
        {
            if(temp->contains(word[i]))
            // if(temp->arr[word[i]-'a']==NULL)
            {
                // temp = temp->arr[word[i]-'a'];
                temp = temp->getNext(word[i]);
            }
            else
            {
                return false;
            }
        }
        return temp->flag;
    }
    
    bool startsWith(string word) {
        Trie * temp = this;
        
        for(int i=0;i<word.size();i++)
        {
            if(temp->contains(word[i]))
            // if(temp->arr[word[i]-'a']==NULL)
            {
                // temp = temp->arr[word[i]-'a'];
                temp = temp->getNext(word[i]);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */