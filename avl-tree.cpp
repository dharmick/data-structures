#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int key, height;
        node *left, *right;
        node(int n){
            key = n;
            height = 1;
            left = NULL;
            right = NULL;
        }
};

class avl{
    public:
        node *root;
        avl(){
            root = NULL;
        }

        node* insert(node *root, int n){

            // normal bst insertion
            if(root == NULL){
                node *temp = new node(n);
                return temp;
            }
            if(n > root->key) root->right = insert(root->right, n);
            else root->left = insert(root->left, n);
            
            
            // rotation
            int left_height = 0;
            if(root->left) left_height = root->left->height;
            int right_height = 0;
            if(root->right) right_height = root->right->height;


            if(left_height - right_height > 1){
                if(n < root->left->key){
                    // case 1: LL
                    return rotateRight(root);
                } else {
                    // case 2: LR
                    root->left = rotateLeft(root->left);
                    return rotateRight(root);
                }
            } else if(right_height - left_height > 1){
                if(n > root->right->key){
                    // case 3: RR
                    return rotateLeft(root);
                } else {
                    // case 4: RL
                    root->right = rotateRight(root->right);
                    return rotateLeft(root);
                }
            }

            int l_height = 0;
            if(root->left) l_height = root->left->height;
            int r_height = 0;
            if(root->right) r_height = root->right->height;

            root->height = max(l_height, r_height) + 1;
            return root;

        }

        node* rotateLeft(node *root){
            node *newRoot = root->right;
            
            // order is imp
            root->right = newRoot->left;
            newRoot->left = root;
            
            // order is imp
            root->height = find_max(root->left, root->right) + 1;
            newRoot->height = find_max(newRoot->left, newRoot->right) + 1;

            return newRoot; 
        }

        node* rotateRight(node *root){
            node *newRoot = root->left;
            
            // order is imp
            root->left = newRoot->right;
            newRoot->right = root;
            
            // order is imp
            root->height = find_max(root->left, root->right) + 1;
            newRoot->height = find_max(newRoot->left, newRoot->right) + 1;

            return newRoot; 
        }

        void levelOrder(){
            queue<node*> q;
            q.push(root);
            q.push(NULL);
            cout<<"\nLevel order traversal (key:height)-\n";
            while(!q.empty()){
                node *curr = q.front();
                q.pop();
                if(curr == NULL){
                    cout<<'\n';
                    if(!q.empty()) q.push(NULL);
                } else {
                    cout<<curr->key<<':'<<curr->height<<' ';
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
            }
        }

        int find_max(node *a, node *b){
            if(a == NULL && b == NULL) return 0;
            if(a == NULL) return b->height;
            if(b == NULL) return a->height;
            return max(a->height, b->height);
        }
};

int main(){


    avl tree;
    int choice = 0;
    int data;
    while(choice != 4){

        cout<<"\n**********Enter choice**********\n";
        cout<<"1: insert"<<'\n';
        cout<<"2: delete"<<'\n';
        cout<<"3: level order traversal"<<'\n';
        cout<<"4: exit"<<'\n';
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter data to insert: ";
            cin>>data;
            tree.root = tree.insert(tree.root, data);
            break;

        // case 2:
        //     cout<<"Enter data to delete: ";
        //     cin>>data;
        //     tree.remove(data);
        //     break;
        
        case 3:
            tree.levelOrder();
            break;

        default:
            break;
        }
    }
}