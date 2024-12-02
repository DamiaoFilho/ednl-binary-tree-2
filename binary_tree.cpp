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

int main(){
    int node_count = 12;

    // cout<<"Insert nodes quantity"<<"\n";
    // cin>>node_count;

    // Node* nodes = new Node[node_count];
    // for(int i=0; i<node_count; i++){
    //     int value;

    //     cout<<"Insert the "<<i+1<<" Node"<<endl;
    //     cin>>value;

    //     nodes[i].value = value;

    //     if(i != 0 ){
    //         insert(&nodes[0], &nodes[i]);
    //     }
    // }
    
    
    Node* testing[] = {
        new Node(100),
        new Node(50),
        new Node(200),
        new Node(70),
        new Node(140),
        new Node(30),
        new Node(350),
        new Node(117),
        new Node(400),
        new Node(42),
        new Node(80),
        new Node(65),
    };

    for(int i=0; i<node_count; i++){
        if(i != 0 ){
            insert(testing[0], testing[i]);
        }
    }


    Node* findedNode = searchNode(testing[0], 140);

    if(findedNode != nullptr){
        cout<<"Node encontrado: "<<findedNode->value<<endl;
    }else{
        cout<<"Node não encontrado"<<endl;
    }

    printNode(testing[0]);
    cout<<endl;

    cout<<"Quantidade de nos: "<<getNodeCount(testing[0])<<endl;
    cout<<"Quantidade de folhas: "<<getLeafsCount(testing[0])<<endl;

}