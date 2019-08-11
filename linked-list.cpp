#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class linked_list{
    private:
        node *head, *tail;
    public:
        linked_list(){
            head = NULL;
            tail = NULL;
        }

        void insert(int n){
            node *temp = new node;
            temp->data = n;
            temp->next = NULL;

            if(head == NULL){
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
            cout<<"\nElement inserted!\n";
        }

        void remove(int n){
            node *curr = head;
            node *prev;
            while(true){
                if(curr == NULL){
                    cout<<"\nElement not found!\n";
                    break;
                }else if(curr->data == n){
                    if(curr == head && curr == tail){
                        // deleting the only element present in the list
                        head = NULL;
                        tail = NULL;
                    } else if(curr == head){
                        // deleting the first element in the list
                        head = head->next;
                    } else if(curr == tail){
                        // deleting the last element in the list
                        prev->next = curr->next;
                        tail = prev;
                    } else {
                        prev->next = curr->next;
                    }
                    cout<<"\nElement deleted!\n";
                    break;
                } else {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }

        void display(){
            cout<<"\nElements are: ";
            node *curr = head;
            while(curr){
                cout<<curr->data<<" ";
                curr = curr->next;
            }
            cout<<'\n';
        }
};

int main(){
    linked_list ll;
    int choice = 0;
    int data;
    while(choice != 4){

        cout<<"\n**********Enter choice**********\n";
        cout<<"1: insert"<<'\n';
        cout<<"2: delete"<<'\n';
        cout<<"3: view"<<'\n';
        cout<<"4: exit"<<'\n';
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter data to insert: ";
            cin>>data;
            ll.insert(data);
            break;

        case 2:
            cout<<"Enter data to delete: ";
            cin>>data;
            ll.remove(data);
            break;
        
        case 3:
            ll.display();

        default:
            break;
        }
    }
}