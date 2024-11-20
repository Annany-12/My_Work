#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insertIntoBST(node* root, int data) {
    if (data == -1) {
        return NULL;
    }

    if (root == NULL) {
        root = new node(data);
    } 
    else if (data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } 
    else if (data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } 
    else {
        cout << "Duplicate values are not allowed in BST" << endl;
    }

    return root;
}

node* createBST() {
    node* root = NULL;
    while (true) {
        int data;
        cout << "Enter data (-1 to stop): ";
        cin >> data;
        
        if (data == -1) {
            break;
        }
        root = insertIntoBST(root, data);
    }
    return root;
}

int search(node* root, int key, int level = 0) {
    if (root == NULL)
        return -1;
    
    if (root->data == key)
        return level;
    
    if (key < root->data)
        return search(root->left, key, level + 1);
    
    return search(root->right, key, level + 1);
}

node* findMin(node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

node* deleteNode(node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data){
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->data){
        root->right = deleteNode(root->right, key);
    }

    else {
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void levelOrderTraversal(node* root) {
    if(root == nullptr){
        return;
    }
    
    queue <node*> myQueue;
    myQueue.push(root);
    myQueue.push(nullptr);
    
    while(!myQueue.empty()){
        node* temp = myQueue.front();
        myQueue.pop();
        
        if(temp == nullptr){
            cout << endl;
            if(!myQueue.empty()){
                myQueue.push(nullptr);
            }
        }
        else{
            cout << temp->data <<" ";
            if(temp->left){
                myQueue.push(temp->left);
            }
            if(temp->right){
                myQueue.push(temp->right);
            }
        }
    }
}

void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void exit_program(){
    cout << "Exiting the program" << endl;
    exit(0);
}

int main() {
    node* root = createBST();
    
    int input;
    int key_to_search;
    int result;
    int key_to_delete;
    node* dRoot = NULL;
    
    while(1) {
        cout << " 1. Delete" << endl << " 2. Display" << endl << " 3. Search" << endl << " 4. BFS (Level wise print)" << endl << " 5. Exit" << endl;
        cout << "Input: ";
        cin >> input;
        
        switch(input){
            case 1:
                int key_to_delete;
                cout << "Enter a key to delete: ";
                cin >> key_to_delete;
                
                root = deleteNode(root, key_to_delete);
                cout << "BST after deletion:" << endl;
                inorderTraversal(root);
                break;

            case 2:
                cout << "Display" << endl;
                cout << "Inorder Traversal of BST: ";
                inorderTraversal(root);
                cout << endl;
                break;
                
            case 3:
                cout << "Search" << endl;
                cout << "Enter the key to search for: ";
                cin >> key_to_search;
            
                result = search(root, key_to_search);
            
                if (result != -1) {
                    cout << "Key " << key_to_search << " found at level " << result << endl;
                } else {
                    cout << "Key " << key_to_search << " not found." << endl;
                }
                break;
                
            case 4:
                cout << "Level Wise Print" << endl;
                levelOrderTraversal(root);
                break;
                
            case 5:
                exit_program();
                break;
                
            default:
                cout << "Wrong Input" << endl;
                break;
        }
    }
    return 0;
}