
#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        this->data = 0;
        this->left = nullptr;
        this->right = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = NULL;
    }
};
class tree
{

public:
   
    void create(node *&root)
    {
        int n, k;
        cout << "Enter no of nodes: ";
        cin >> n;
        cout << "Enter value of root" << endl;
        cin >> k;
        root = new node(k);
        queue<node *> q;
        node *temp = root;
        for (int i = 1; i < n; i++)
        {
            cout << "Enter data: ";
            cin >> k;
            temp->left = new node(k);
            q.push(temp->left);
            i++;
            if (i < n)
            {
                cout << "Enter data: ";
                cin >> k;
                temp->right = new node(k);
                q.push(temp->right);
            }
            temp = q.front();
            q.pop();
        }
    }
    // recursive inorder tree  traversal
    void inorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // non recursive function for tree inorder traversal
    void inorder_1(node *root)
    {
        if (!root)
        {
            return;
        }
        stack<node *> s1;
        node *temp = root;

        while (temp != NULL || !s1.empty())
        {
            while (temp != NULL)
            {
                s1.push(temp);
                temp = temp->left;
            }
            temp = s1.top();
            s1.pop();
            cout << temp->data << " ";

            temp = temp->right;
        }

        cout << endl;
    }
    // non recursive function for preorder tree traversal
    void preorder_1(node *root)
    {
        if (!root)
        {
            return;
        }
        stack<node *> s1;
        node *temp = root;
        s1.push(temp);
        while (!s1.empty())
        {
            temp = s1.top();
            s1.pop();

            // dislapy the data
            cout << temp->data << " ";
            if (temp->right)
            {
                s1.push(temp->right);
            }
            if (temp->left)
            {
                s1.push(temp->left);
            }
        }

        cout << endl;
    }
    // non recursive function for postorder traversal
    void postorder_1(node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        stack<node *> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            node *temp = s1.top();
            s1.pop();
            s2.push(temp);

            if (temp->left)
            {
                s1.push(temp->left);
            }
            if (temp->right)
            {
                s1.push(temp->right);
            }
        }
        while (!s2.empty())
        {
            node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
        }
        cout << endl;
    }

    // recursive preorder tree  traversal
    void preorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);

        preorder(root->right);
    }
    // recursive postorder tree  traversal
    void postorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }

        postorder(root->left);

        postorder(root->right);
        cout << root->data << " ";
    }

    void display(node *root)
    {

        cout << "Displaying BFS of tree" << endl;
        if (root == NULL)
        {
            cout << "Empty tree" << endl;
            return;
        }
        queue<node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                cout << endl;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                cout << temp->data << " ";
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }
    int count(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = count(root->left);
        int right = count(root->right);
        return left + right + 1;
    }
    int leaf_cnt(node *root)
    { // leaf nodes dont have left or right child
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        int left = leaf_cnt(root->left);
        int right = leaf_cnt(root->right);
        return left + right;
    }
    int internal_nodes(node *root)
    {
        if (root == NULL || !root->left && !root->right)
        {
            return 0;
        }
        return count(root) - leaf_cnt(root) - 1;
    }
    int height(node *root)
    {
        if (root->right == NULL && root->left == NULL)
        {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        // height is max of left or right height
        int maxi = max(left, right);
        return maxi + 1;
    }
    node *swap_tree(node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        node *temp = root->left;
        root->left = root->right;
        root->right = temp;
        swap_tree(root->left);
        swap_tree(root->right);
        return root;
    }
    // recursive function for coping the tree
    void copy_tree1(node *root1, node *&root2)
    {
        if (root1 == NULL)
        {
            root2 = NULL;
            return;
        }
        root2 = new node(root1->data);
        copy_tree1(root1->left, root2->left);
        copy_tree1(root1->right, root2->right);
    }

    // recursive function for erase
    void erase(node *&root)
    {
        if (root == NULL)
        {
            return; // already having no value
        }
        erase(root->left);
        erase(root->right);
        delete root;
        root = NULL;
    }
    // non recursive for erasing nodes tree
    void non_rec_erase(node *&root)
    {
        if (root == NULL)
        {
            return; // alreday empty
        }
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *curr = q.front();
            q.pop();
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            delete curr;
        }
        root = NULL;
    }
};

int main()
{
    cout << "Binary tree operations: " << endl;
    tree obj;
    node *root = NULL;
    obj.create(root);
    node *root1 = NULL;
    obj.display(root);
    for (int i = 0; i < 20; i++)
    {
        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "1.Inorder traversal\n2.preorder Traversal\n3.postorder traversal\n4.Count no of nodes and height\n5.count internal and leaf nodes\n6.swap tree\n7.copy tree\n8.erase tree\n9.exit" << endl;
        cout << "Enter your choice: ";
        int k;
        cin >> k;
        if (k == 1)
        {
            cout << "\nInoder traversal" << endl;
            cout << "using recursive and non-recursive both" << endl;
            obj.inorder(root);
            cout << endl;
            obj.inorder_1(root);
            cout << endl;
        }
        else if (k == 2)
        {

            cout << "\nPreorder Traversal" << endl;
            cout << "using recursive and non-recursive both" << endl;
            obj.preorder(root);
            cout << endl;
            obj.preorder_1(root);
            cout << endl;
        }
        else if (k == 3)
        {
            cout << "\nPostorder traversal" << endl;
            cout << "using recursive and non-recursive both" << endl;
            obj.postorder(root);
            cout << endl;
            obj.postorder_1(root);
            cout << endl;
        }
        else if (k == 4)
        {
            cout << "\nheight of tree is: " << obj.height(root) << endl;
            cout << "\nTotal nodes in the root are " << obj.count(root) << endl;
        }
        else if (k == 5)
        {
            cout << "\nNo of leaf node are : " << obj.leaf_cnt(root) << endl;

            cout << "\nInternal Nodes are: " << obj.internal_nodes(root) << endl;
        }
        else if (k == 6)
        {
            cout << "\nswpping the tree" << endl;
            node *temp = obj.swap_tree(root);
            obj.display(temp);
        }
        else if (k == 7)
        {
            cout << "\nCopying original tree" << endl;
            obj.copy_tree1(root, root1);
            cout << "address of original tree root:  " << &root << endl;
            cout << "address of copied tree root: " << &root1 << endl;
            cout << "New tree is: " << endl;
            obj.display(root1);
        }
        else if (k == 8)
        {
            cout << "\n----------------------------------------------------------------" << endl;
            cout << "\nerasing all the nodes in tree using recursive function" << endl;
            obj.erase(root);
            obj.display(root);
            cout << "\nerasing all the nodes of tree 2 using non-recursive function " << endl;
            obj.non_rec_erase(root1);
            obj.display(root1);
        }
        else if (k == 9)
        {
            break;
        }
        else
        {
            cout << "invalid choice" << endl;
        }
    }

    return 0;
}


//—----------------------------------------------------------------------------------
Another approach for postorder 
/*
    void postorder(node* root) {
        if (root == NULL) {
            cout << "\nTree is empty\n";
            return;
        }

        stack<node*> st;
        node* current = root;
        node* lastVisited = NULL;

        while (current != NULL || !st.empty()) {
            if (current != NULL) {
                st.push(current);
                current = current->left;  // Move to leftmost node
            } else {
                node* topNode = st.top();
                // If right child exists and is unvisited, go to it
                if (topNode->right != NULL && topNode->right != lastVisited) {
                    current = topNode->right;
                } else {
                    cout << " " << topNode->data;
                    lastVisited = topNode;
                    st.pop();
                }
            }
        }
    }
};

*/

