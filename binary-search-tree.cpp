#include<iostream>
using namespace std;

struct node{
    int key;
    node *left, *right;
};

class bst{
    public:
        node *root;
        bst(){
            root = NULL;
        }

        void insert(int n){
            node *curr = root, *prev;
            
            // find a proper place
            while(curr){
                prev = curr;
                if(n > curr->key)
                    curr = curr->right;
                else if(n < curr->key)
                    curr = curr->left;
                else
                    return;
            }

            // create the node
            node *temp = new node;
            temp->key = n;
            temp->left = NULL;
            temp->right = NULL;

            // insert the node
            if(root == NULL)
                root = temp;
            else if(n > prev->key) 
                prev->right = temp;
            else 
                prev->left = temp;

            cout<<"\nElement inserted!\n";
        }

        void remove(int n){
            node *curr = root, *prev;

            // find the element
            while(curr){
                if(n == curr->key)
                    break;
                prev = curr;
                if(n > curr->key)
                    curr = curr->right;
                else if(n < curr->key)
                    curr = curr->left;
            }

            // element not found
            if(curr == NULL){
                cout<<"\nElement not found!\n";
                return;
            }

            // element found
            if(curr->left == NULL && curr->right == NULL){
                // case 1: leaf node
                if(curr == root)
                    root = NULL;
                else if(curr->key > prev->key)
                    prev->right = NULL;
                else 
                    prev->left = NULL;
            } else if(curr->left == NULL){
                // case 2: node with only right child
                if(curr == root)
                    root = root->right;
                else if(curr->key > prev->key)
                    prev->right = curr->right;
                else 
                    prev->left = curr->right;
            } else if(curr->right == NULL){
                // case 3: node with only left child
                if(curr == root)
                    root = root->left;
                else if(curr->key > prev->key)
                    prev->right = curr->left;
                else 
                    prev->left = curr->left;
            } else {
                // case 4: node with two children
                node *predecessor = curr->left, *parent = curr;

                while(predecessor->right){
                    parent = predecessor;
                    predecessor = predecessor->right;
                }

                curr->key = predecessor->key;
                if(parent == curr){
                    parent->left = predecessor->left;
                } else {
                    parent->right = predecessor->left;
                }
            }
            cout<<"\nElement deleted!\n";
        }

        void inorder(node *curr){
            if(curr == NULL) return;
            inorder(curr->left);
            cout<<curr->key<<' ';
            inorder(curr->right);
        }

        void preorder(node *curr){
            if(curr == NULL) return;
            cout<<curr->key<<' ';
            preorder(curr->left);
            preorder(curr->right);
        }

        void postorder(node *curr){
            if(curr == NULL) return;
            postorder(curr->left);
            postorder(curr->right);
            cout<<curr->key<<' ';
        }
};

int main(){
    bst tree;

    // tree.insert(7);
    // tree.insert(3);
    // tree.insert(10);
    // tree.insert(2);
    // tree.insert(5);
    // tree.insert(9);
    // tree.insert(15);
    // tree.insert(1);
    // tree.insert(6);




    int choice = 0;
    int data;
    while(choice != 6){

        cout<<"\n**********Enter choice**********\n";
        cout<<"1: insert"<<'\n';
        cout<<"2: delete"<<'\n';
        cout<<"3: inorder"<<'\n';
        cout<<"4: preorder"<<'\n';
        cout<<"5: postorder"<<'\n';
        cout<<"6: exit"<<'\n';
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter data to insert: ";
            cin>>data;
            tree.insert(data);
            break;

        case 2:
            cout<<"Enter data to delete: ";
            cin>>data;
            tree.remove(data);
            break;
        
        case 3:
            tree.inorder(tree.root);
            break;
        
        case 4:
            tree.preorder(tree.root);
            break;
        
        case 5:
            tree.postorder(tree.root);
            break;

        default:
            break;
        }
    }
}