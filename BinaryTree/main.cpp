#include <iostream>

using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int p_data):  data(p_data), left(nullptr), right(nullptr)
    {

    }
};

class BST {

    Node* root;

public:
    BST() : root(nullptr) {}
    ~BST()
    {
        deleteTree();
    }

    void deleteTree()
    {
        deleteTreeHelper(root);
    }

    void deleteTreeHelper(Node* p_node)
    {
        if (p_node ==nullptr)
            return;
        deleteTreeHelper(p_node->left);
        deleteTreeHelper(p_node->right);
        cout<<"deleted:"<<p_node->data<<endl;
        delete p_node;
    }
    /*void insert(int p_data)
    {
        if (root == nullptr)
        {
            root = new Node(p_data);
        }
        else
        {
            insert(root,p_data);
        }
    }

    void insert(Node* p_workNode, int p_data)
    {
        if (p_data < p_workNode->data ) {
                if (p_workNode->left != nullptr)
                    insert(p_workNode->left, p_data);
                else
                    p_workNode->left = new Node(p_data);
        }
        else
        {
                if (p_workNode->right != nullptr)
                    insert(p_workNode->right, p_data);
                else
                    p_workNode->right = new Node(p_data);
        }
    }*/

    void insert(int p_data)
    {
        root = insertHelper(root,p_data);
    }

    Node* insertHelper(Node* p_workNode, int p_data)
    {
        if (p_workNode == nullptr)
            return new Node(p_data);
        if (p_data < p_workNode->data)
            p_workNode->left = insertHelper(p_workNode->left, p_data);
        else
            p_workNode->right = insertHelper(p_workNode->right, p_data);
    }

    void print()
    {
        printHelper(root);
        cout<<endl;
    }

    void printHelper(Node* p_node)
    {
        if (p_node == nullptr)
            return;

        printHelper(p_node->left);
        cout<<" "<<p_node->data<<" ";
        printHelper(p_node->right);
    }

    int height()
    {
        return heightHelper(root);
    }

    int heightHelper(Node* node)
    {
        if (node == nullptr)
            return 0;
        else return 1+max(heightHelper(node->right), heightHelper(node->left));
    }

    int size()
    {
        return sizeHelper(root);
    }

    int sizeHelper(Node* p_node)
    {
        if (p_node == nullptr)
            return 0;
        return 1+sizeHelper(p_node->left) + sizeHelper(p_node->right);
    }

    void deleteNode(int p_data)
    {
        deleteNodeHelper(nullptr,root, p_data);
    }

    void deleteNodeHelper(Node* parent, Node* current, int p_data)
    {
        if (current == nullptr)
            return;
        cout<<"deleting "<<current->data<<endl;

        if (p_data < current->data)
            return deleteNodeHelper(current,current->left,p_data);
        else if (p_data > current->data)
            return deleteNodeHelper(current,current->right,p_data);
        else
        {
            //Match found
            //case either left or right leaf is null
            if (current->left == nullptr || current->right == nullptr)
            {
                cout<<"match found one side is null:"<<endl;
                Node* temp = current->left;
                if (current->right) temp = current->right;

                if (parent)
                {
                    if (parent->right == current)
                    {
                        parent->right = temp;
                    }
                    else
                    {
                        parent->left = temp;
                    }
                }
                else
                    root = temp;
            }
            else
            {
                cout<<"match found two sides are there:"<<endl;
                //it has two child nodes
                //find the least node in the right node and swap it to the current val

                Node* leastLeaf = current->right;

                while (leastLeaf->left)
                {
                    leastLeaf=leastLeaf->left;
                }

                //now swap
                int temp = current->data;
                current->data = leastLeaf->data;
                leastLeaf->data = temp;
                //now delete the current value
                deleteNodeHelper(current,current->right, temp);
            }
            return;
        }
        cout<<"actual deleted-->:"<<current->data<<endl;
        delete current;
        return;
    }

};

int main()
{
    BST bst;
    bst.insert(100);
    bst.insert(10);
    bst.insert(1);
    bst.insert(20);
    bst.insert(200);
    bst.insert(400);
    bst.insert(500);
    bst.insert(150);

    bst.print();

    bst.deleteNode(200);
    bst.print();

    cout<<"height:"<<bst.height()<<endl;
    cout<<"size:"<<bst.size()<<endl;
    return 0;
}
