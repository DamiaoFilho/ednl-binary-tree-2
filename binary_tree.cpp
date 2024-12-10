#include <iostream>
#include <queue>

using namespace std;


class Node {

    public:

        Node* left;
        Node* right;
        int value;

        Node() : value(0), left(nullptr), right(nullptr) {}
        Node(int value) : value(value), left(nullptr), right(nullptr) {}
};


void insert(Node* root, Node* new_node){
    Node* current = root;
    
    while(current != nullptr){
        if(new_node->value < current->value){

            if(current->left == nullptr){
                current->left = new_node;
                break;

            }else{
                current = current->left;

            }

        }else if(new_node->value > current->value){

            if(current->right == nullptr){
                current->right = new_node;
                break;

            }else{
                current = current->right;

            }

        }else{
            break;
        }
    }
}

void printByLevel(Node* root){
    if (root == nullptr) return;

    int aux = 0;
    int itemsInLine = 1;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if(aux == itemsInLine){
            cout<<endl;
            cout << current->value<<" ";
            itemsInLine = aux * 2; 
            aux = 0;   
        }else{
            cout << current->value << " ";
        }

        if (current->left != nullptr) {
            q.push(current->left);        
        }
        if (current->right != nullptr) {
            q.push(current->right);      
        }
        aux++;
    }
}

Node* findMin(Node* root){
    queue<Node*> q;
    q.push(root);
    Node* min = q.front();

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if(current->value < min->value){
            min = current;
        }

        if (current->left != nullptr) {
            q.push(current->left);        
        }
        if (current->right != nullptr) {
            q.push(current->right);      
        }
    }

    return min;
}

void remove_node(int remove_value, Node*& root){
    Node* aux;

    if(root == nullptr) return;

    else if (remove_value < root->value) remove_node(remove_value, root->left);
    else if (remove_value > root->value) remove_node(remove_value, root->right);

    else if (root->left != nullptr && root->right != nullptr){
        aux = findMin(root->right);
        root->value = aux->value;
        remove_node(root->value, root->right);
    }else{
        if (root->left != nullptr){
            root = root->left;
        }else{
            root = root->right;
        }
    }

}

void printPreOrder(Node* current){
    cout<<current->value<<" ";

    if(current->left != nullptr){
        printPreOrder(current->left);
    }
    if(current->right != nullptr){
        printPreOrder(current->right);
    }
}

void printSimetricOrder(Node* current){
    if (current->left != nullptr){
        printSimetricOrder(current->left);
    }
    cout<<current->value<<" ";
    if (current->right != nullptr){
        printSimetricOrder(current->right);
    }
}

void printPostOrder(Node* current){
    if (current->left != nullptr){
        printSimetricOrder(current->left);
    }
    if (current->right != nullptr){
        printSimetricOrder(current->right);
    }
    cout<<current->value<<" ";
}

void printTree(Node* current, int space){
    if (current == nullptr){
            return;
    }
 
    space += 5;
 
    printTree(current->right, space);
 
    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";
    cout << current->value << "\n";
 
    printTree(current->left, space);

}


void test(){
    Node* nodes[] = {
        new Node(8),
        new Node(3),
        new Node(11),
        new Node(1),
        new Node(5),
        new Node(9),
        new Node(14),
        new Node(6),
        new Node(10),
        new Node(12),
        new Node(15),
        new Node(7),
        new Node(13),
    };

    for(int i=0; i<13; i++){
        insert(nodes[0], nodes[i]);
    }
}


int main(){

    int op = 1;
    int node_count;

    cout<<"--Welcome to binary tree printer--"<<endl;
    Node** nodes = nullptr;

    while( op != 8 ){
        switch (op)
        {
        case 1:
            cout<<"Type nodes quantity: ";
            cin>>node_count;

            nodes = new Node*[node_count];

            for (int i=0; i<node_count; i++){
                cout<<"Type node "<<i+1<<" value: ";
                nodes[i] = new Node();
                cin >> nodes[i]->value;
                insert(nodes[0], nodes[i]);
            }
            break;

        case 2:
            printPreOrder(nodes[0]);
            cout<<endl<<endl;
            break;

        case 3:
            printSimetricOrder(nodes[0]);
            cout<<endl<<endl;
            break;

        case 4:
            printPostOrder(nodes[0]);
            cout<<endl<<endl;
            break;

        case 5:
            printByLevel(nodes[0]);
            cout<<endl<<endl;
            break;

        case 6:
            cout<<"Type value to be removed: ";
            int value;
            cin>>value;
            remove_node(value, nodes[0]);
            break;

        case 7:
            printTree(nodes[0], 0);
            cout<<endl;
            break;
        }

        cout<<"What would you like to do?"<<endl;
        cout<<"1 - Create new tree\n2 - Print Pre Order\n3 - Print Simetric Order\n4 - Print Post Order\n5 - Print by Level\n6 - Remove a Node\n7 - Print Tree\n8 - Quit"<<endl;
        cin>>op;
    }
}