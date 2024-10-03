/* implementation of aho-corasick, as given at: https://www.cs.uku.fi/~kilpelai/BSA05/lectures/slides04.pdf
 * takes input from file.c
*/
#include <bits/stdc++.h>
#define NUM_KEY 10   //number of keywords
#define MAX_SIZE 31   //max length of a keyword string
#define ALPHA 128
#define MAX_FILE_SIZE 1000000  //max file size if actually half of this value

using namespace std;

struct trieNode {
    trieNode* fail;
    trieNode* next[ALPHA];
    int num_matches, matches[NUM_KEY];
    trieNode() : fail(NULL), next(), num_matches(0) {}
};

void trieInsert(trieNode *root, char *str, int kn) {
    for(int i = 0; str[i]; i++) {
        if(!root->next[str[i]])
            root->next[str[i]] = new trieNode();
        root = root->next[str[i]];
    }
    if(root->num_matches==0) {     //to prevent duplicates due to re-insertion in trie
        root->matches[0] = kn;
        root->num_matches = 1;
    }
}

char text[MAX_FILE_SIZE], text_copy[MAX_FILE_SIZE];
int mark[MAX_FILE_SIZE];

int main() {
    trieNode *root = new trieNode();
    char keywords[NUM_KEY][MAX_SIZE] = {"int", "float", "while", "for", "if", "return", "char", "continue", "default", "const"};
    int key_len[NUM_KEY];
    for(int i = 0; i<NUM_KEY; i++) {
        key_len[i] = strlen(keywords[i]);
        trieInsert(root, keywords[i], i);
    }

    queue<trieNode*> myQ;
    for(int i = 0; i<ALPHA; i++) {  //trie structure modified to become a dfa
        if(!root->next[i])
            root->next[i] = root;
        else {
            root->next[i]->fail = root;
            myQ.push(root->next[i]);
        }
    }

    while(!myQ.empty()) {
        trieNode *p = myQ.front(), *g, *f;
        myQ.pop();
        for(int i = 0; i<ALPHA; i++) {
            g = p->next[i];
            if(!g)
                continue;
            myQ.push(g);
            f = p->fail;
            while(!f->next[i])
                f = f->fail;
            g->fail = f->next[i];
            for(int x = 0; x < g->fail->num_matches; x++) {
                g->matches[g->num_matches++] = g->fail->matches[x];
            }
        }
    }

    FILE *fp = fopen("file.c", "r");
    int n = fread(text, sizeof(char), MAX_FILE_SIZE/2, fp);
    fclose(fp);
    trieNode *state = root;
    for(int i = 0; i<n; i++) {
        while(!state->next[text[i]])
            state = state->fail;
        state = state->next[text[i]];
        for(int x = 0; x < state->num_matches; x++) {
            printf("Found \"%s\" at %d\n", keywords[state->matches[x]], i-key_len[state->matches[x]]+2);
            mark[i-key_len[state->matches[x]]+1]++;
            mark[i+1]++;
        }
    }

    int pr = 0;
    for(int i = 0; i<n; i++) {
        while(mark[i]>0) {
            text_copy[pr++] = '|';
            mark[i]--;
        }
        text_copy[pr++] = text[i];
    }
    while(mark[n]>0) {
        text_copy[pr++] = '|';
        mark[n]--;
    }
    fp = fopen("out.c", "w");
    fwrite(text_copy, sizeof(char), pr, fp);
    return 0;
}
