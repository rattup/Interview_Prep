class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct  trie
    {
        int end;
        struct trie* child[26];
        trie()
        {
            end=0;
            for(int i=0;i<26;i++)
            child[i]=NULL;
        }
    };
    trie *root;
    WordDictionary() {
        root=new trie();
        
    }
    bool dfs(int index,string word,trie *root)
    {
        
        if(index==word.size())
        {
            return root->end>0 ? 1:0;
        }
        if(word[index]=='.')
        {
        for(int i=0;i<26;i++)
        {
            if(root->child[i])
            {
                if(dfs(index+1,word,root->child[i]))
                return true;
            }
        }
        return false;        
        }
        
        else
        {
            if(root->child[word[index]-'a'])
            return dfs(index+1,word,root->child[word[index]-'a']);
            
        }
        return false;
        
        
    }
    
    void addWord(string word) {
        trie *p=root;
        for(int i=0;i<word.size();i++)
        {
            if(p->child[word[i]-'a']==NULL)
            p->child[word[i]-'a']=new trie();
            p=p->child[word[i]-'a'];
        }
        p->end++;
        
        
    }
    
    bool search(string word) {
    return dfs(0,word,root);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
