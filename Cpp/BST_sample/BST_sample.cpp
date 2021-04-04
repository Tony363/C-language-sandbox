
/* 
** Binary Search Tree implementation in C++
** Harish R
*/
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class BST {
    
    struct node {
        char ascii;
        string code;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(char character,string Mcode, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->ascii = character;
            t->code = Mcode;
            t->left = t->right = NULL;
            cout << t << " | "  << t->ascii << " | " << t->code << endl;
        }
        else if((int)character < (int)t->ascii){
            cout << "left " 
                    << (int)character
                    << " | " 
                    << (int)t->ascii
                    << endl;
            t->left = insert(character,Mcode, t->left);
        }
        else if((int)character > (int)t->ascii){
            cout << "left " 
                    << (int)character
                    << " | " 
                    << (int)t->ascii
                    << endl;
            t->right = insert(character,Mcode, t->right);
        }
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(char character, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if((int)character < (int)t->ascii)
            t->left = remove(character, t->left);
        else if((int)character > (int)t->ascii)
            t->right = remove(character, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->ascii = temp->ascii;
            t->code = temp->code;
            t->right = remove(t->ascii, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->ascii << " " << t->code << " | ";
        inorder(t->right);
    }

    node* find(node* t, char character) {
        if(t == NULL)
            return NULL;
        else if((int)character < (int)t->ascii)
            return find(t->left, character);
        else if((int)character > (int)t->ascii)
            return find(t->right, character);
        else
            return t;
    }

public:
    BST() {
        root = NULL;
        ifstream MorseFile;
        MorseFile.open("../PA_6/morseCode.txt");
        if (MorseFile.is_open()){
            parseFile(MorseFile);
        }else {
            cout << "Unable to open file";
        }
        MorseFile.close();
    }
    void parseFile(ifstream &file){
        string line,Mcode;
        while(getline(file,line)){
            char character = line[0];
            stringstream ss;
            ss << line;
            getline (ss,Mcode,character);
            getline (ss,Mcode,character);
            insert(character,Mcode);
        }
        cout << endl;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(char character,string Mcode) {
        root = insert(character,Mcode, root);
    }

    void remove(char character) {
        root = remove(character, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    void search(char character) {
        root = find(root, character);
    }
};

int main() {
    BST t;
    // t.insert('H',"....");
    // t.insert('E',".");
    // t.insert('L',".-..");
    // t.insert('O',"---");
    // t.insert('W',".--");
    // t.insert('R',".-.");
    // t.insert('L',".-..");
    // t.insert('D',"-..");
    // t.display();
    // t.remove('W');
    // t.display();
    // t.remove('H');
    // t.display();
    // t.remove('L');
    // t.display();
    return 0; 
}