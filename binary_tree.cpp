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

Node* searchNode(Node* current, int value) {
    if (current == nullptr || current->value == value) {
        return current;
    }
    if (value < current->value) {
        return searchNode(current->left, value);
    } else {
        return searchNode(current->right, value);
    }
}


void printNode(Node* root){
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

int getNodeCount(Node* current){
    if (current == nullptr){
        return 0;
    }

    int left = getNodeCount(current->left);
    int right = getNodeCount(current->right);

    return left + right + 1;
}

int getLeafsCount(Node* root){
    if (root == nullptr) return 0;

    queue<Node*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left != nullptr) {
            q.push(current->left);        
        }
        if (current->right != nullptr) {
            q.push(current->right);      
        }
        if(current->left == nullptr && current->right == nullptr){
            count++;
        }
    }

    return count;
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

int main(){
    int node_count = 12;

    cout<<"Insert nodes quantity: ";
    cin>>node_count;

    Node* nodes = new Node[node_count];
    for(int i=0; i<node_count; i++){
        int value;

        cout<<"Insert "<<i+1<<" Node: ";
        cin>>value;

        nodes[i].value = value;

        if(i != 0 ){
            insert(&nodes[0], &nodes[i]);
        }
    }
    



    Node* findedNode = searchNode(&nodes[0], 140);

    if(findedNode != nullptr){
        cout<<"Node encontrado: "<<findedNode->value<<endl;
    }else{
        cout<<"Node não encontrado"<<endl;
    }

    printTree(&nodes[0], 0);
    cout<<endl;

    cout<<"Quantidade de nos: "<<getNodeCount(&nodes[0])<<endl;
    cout<<"Quantidade de folhas: "<<getLeafsCount(&nodes[0])<<endl;

}