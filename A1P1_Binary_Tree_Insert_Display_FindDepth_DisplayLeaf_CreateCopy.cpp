#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        
    node(int value){
        this -> data = value;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* createTreeUsingRecursion(node* root){
    cout << "Data: ";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1){
        return NULL;
    }

    cout << "Date to left of " << data << endl;
    root -> left = createTreeUsingRecursion(root -> left);

    cout << "Date to right of " << data << endl;
    root -> right = createTreeUsingRecursion(root -> right);
    
    return root;
}

node* creatUsingLevelOrder(node* root){
    queue <node*> myQueue;
    cout << "Enter Data for Root: ";
    int data;
    cin >> data;
    root = new node(data);
    myQueue.push(root);

    while(!myQueue.empty()){
        node* temp = myQueue.front();
        myQueue.pop();

        cout << "Enter left node for " << temp->data << ": ";
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            myQueue.push(temp->left);
        }

        cout << "Enter right node for " << temp->data << ": ";
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            myQueue.push(temp->right);
        }
    }
    return root;
}

void levelOrderTraversal(node* root){
    if(root == nullptr){
        return;
    }
    int depth = 0;
    
    queue <node*> myQueue;
    myQueue.push(root);
    myQueue.push(nullptr);
    
    while(!myQueue.empty()){
        node* temp = myQueue.front();
        myQueue.pop();
        
        if(temp == nullptr){
            cout << endl;
            depth++;
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
    cout << endl << "Depth of tree is: " << depth << endl;
}

void inorder(node* root){
    // Traversal Map: Left -> node -> Right
    if(root == NULL){return;}

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(node* root){
    // Traversal Map: node -> Left -> Right
    if(root == NULL) {return;}

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
    // Traversal Map: Left -> Right -> node
    if(root == NULL) {return;}

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

node* copyInOrder(node* root){
    if(root == NULL){return NULL;}
    else{
        node* temp = new node(root->data);
        temp -> data = root -> data;
        temp -> left = copyInOrder(root -> left);
        temp -> right = copyInOrder(root -> right);
        return temp;
    }
}

void inorder_leafcount(node*root,int &count){
    if(root==NULL){
        return;
    }
    inorder_leafcount(root->left, count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    inorder_leafcount(root->right, count);
}

void display_leaf(node* root){
    if(root == NULL){return;}

    display_leaf(root->left);
    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
    }
    display_leaf(root->right);
}

void exit_program() {
    cout << "Exiting the program." << endl;
    exit(0);
}

int main() {
    
    // node* root = NULL;
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    // root = createTreeUsingRecursion(root);
    // cout << "printing" << endl;
    // levelOrderTraversal(root);

    // cout << "Inorder Traversal: ";
    // // Traversal Map: Left -> node -> Right
    // inorder(root);

    // cout << endl;

    // cout << "Preorder Traversal: ";
    // // Traversal Map: node -> Left -> Right
    // preOrder(root);

    // cout << endl;
    
    // cout << "Postorder Traversal: ";
    // // Traversal Map: Left -> Right -> node
    // postOrder(root);

    // node* root = NULL;
    // // root = creatUsingLevelOrder(root);
    // root = createTreeUsingRecursion(root);
    // inorder(root);
    // cout << endl;
    // levelOrderTraversal(root);

    node* root = NULL;
    // node* copyRoot = copyInOrder(root);
    node* copyRoot = NULL;

    while(1) {
        int sw_case;
        cout << "1. Creating Binary Tree" << endl;
        cout << "2. Displaying Binary Tree" << endl;
        cout << "3. Finding Depth Of Tree" << endl;
        cout << "4. Display Leaf Nodes" << endl;
        cout << "5. Creating Copy of Tree" << endl;
        cout << "6. Exit Program" << endl;
        cout << "Input: ";
        cin >> sw_case;

        switch (sw_case) {
        case 1:
            cout << "How do you want to create Binary Tree" << endl;
            cout << "1. Using Recursion" << endl;
            cout << "2. Level Order Traversal" << endl;
            int creatingTree;
            cout << "Input: ";
            cin >> creatingTree;
            switch (creatingTree) {
                case 1:
                    root = createTreeUsingRecursion(root);
                    break;
            
                case 2:
                    root = creatUsingLevelOrder(root);
                    break;
                
                default:
                    cout << "Wrong input" << endl;
                    break;
            }
            break;

        case 2:
            cout << "Display Binary Tree" << endl;
            cout << "Inorder Representation: ";
            inorder(root);
            cout << endl;

            cout << "Preorder Representation: ";
            preOrder(root);
            cout << endl;

            cout << "Postorder Representation: ";
            postOrder(root);
            cout << endl;

            break;

        case 3:
            cout << "Finding Depth of Tree" << endl;
            levelOrderTraversal(root);
            break;

        case 4:
            cout << "Display Leaf Nodes" << endl;
            cout << "Leaf Nodes: ";
            display_leaf(root);
            break;

        case 5:
            cout << "Creating Copy of Binary Tree" << endl;
            // node* copyRoot = NULL;
            copyRoot = copyInOrder(root);
            // node* copyRoot = copyInOrder(root);
            levelOrderTraversal(copyRoot);
            break;
        
        case 6:
            exit_program();
            break;

        default:
            cout << "Wrong input" << endl;
            break;
        }
    }
    return 0;
}