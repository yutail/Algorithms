// Looking up data in a trie is faster in the worst case, O(m) time (where m is the length of a search string)

typedef struct trie_node
{
    int count;    /* Used to mark leaf nodes */
    bool is_end;
    trie_node *children[ALPHABET_SIZE];
}trie_node;

class Trie {
private:
    trie_node *root;
    
public:
    Trie();
    void insert(trie_node *, string);
    bool search(trie_node *, string);
};

Trie::Trie() {
    root = new trie_node();
    root->count = 0;
    root->is_end = false;
}

void Trie::insert(trie_node *root, string word) {
    if (root == NULL)
        return;
    trie_node *curr = root;
    curr->count++;
    
    for (int i=0; i<word.length(); i++) {
        int letter = (int)word[i] - (int)'a';
        if (curr->children[letter] == NULL)
            curr->children[letter] = new trie_node();
        curr->children[letter]->count++;
        curr = curr->children[letter];
    }
    curr->is_end = true;
}

bool Trie::search(trie_node *root, string word) {
    if (root == NULL)
        return false;
    
    trie_node *curr = root;
    for (int i=0; i<word.length(); i++) {
        int letter = (int)word - (int)'a';
        if (curr->children[letter] == NULL)
            return false;
        curr = curr->children[letter];
    }
    return curr->is_end;
}