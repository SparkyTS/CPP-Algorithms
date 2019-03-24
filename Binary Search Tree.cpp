#include<iostream>//cout and cin
#include<algorithm>//free();

struct Binary_Node
{
    int data;
    Binary_Node* left;
    Binary_Node* right;
};

Binary_Node* New_Node(int data)
{
    Binary_Node* new_node = new Binary_Node;
    new_node->left = NULL;
    new_node->data = data;
    new_node->right= NULL;
    return new_node;
}

Binary_Node* Min_Value_Node(Binary_Node* Root)
{
    Binary_Node* temp = Root;
    while(temp->left)
        temp = temp->left;
    return temp;
}

Binary_Node* Bin_Delete(Binary_Node* Root , int data)
{
    if(!Root) return NULL;

    else if(data < Root->data)
        Root->left = Bin_Delete(Root->left,data);
    else if(data > Root->data)
        Root->right = Bin_Delete(Root->right,data);
    else
    {
        if(Root->left == NULL)
        {
            Binary_Node* temp = Root->right;
            free(Root);
            return temp;
        }
        else if (Root->right == NULL)
        {
            Binary_Node* temp = Root->left;
            free(Root);
            return temp;
        }
        Binary_Node* temp = Min_Value_Node(Root->right);//Find Minimum Value in the right subtree.
        Root->data = temp->data;
        Root->right = Bin_Delete(Root->right,temp->data);
    }
    return Root;
}
Binary_Node* Bin_Insert(Binary_Node* Root, int data)
{
    // If the tree is empty, return a new node
    if (!Root) return New_Node(data);

    // Otherwise, recur down the tree
    if (data < Root->data)
        Root->left  = Bin_Insert(Root->left, data);
    else if (data > Root->data)
        Root->right = Bin_Insert(Root->right, data);

    // return the (unchanged) node pointer
    return Root;
}

Binary_Node* Bin_Find(Binary_Node* Root,int data)
{
    if(!Root)
        return NULL;
    else if (data < Root->data)
        return Bin_Find(Root->left,data);
    else if(data > Root->data)
        return Bin_Find(Root->right,data);
    return Root;
}

void Bin_Preorder(Binary_Node* Root)
{
    if(Root){
        std::cout << Root->data << " ";
        Bin_Preorder(Root->left);
        Bin_Preorder(Root->right);
    }
}

void Bin_Postorder(Binary_Node* Root)
{
    if(Root){
        Bin_Postorder(Root->left);
        Bin_Postorder(Root->right);
        std::cout << Root->data << " ";
    }
}

void Bin_Inorder(Binary_Node* Root)
{
    if(Root)
    {
        Bin_Inorder(Root->left);
        std::cout << Root->data << " ";
        Bin_Inorder(Root->right);
    }
}

main()
{
    Binary_Node* Root = NULL;
    Root = Bin_Insert(Root,10);
    Bin_Insert(Root,20);
    Bin_Insert(Root,30);
    Root = Bin_Delete(Root,10);
    std::cout << "In Order : " ;
    Bin_Inorder(Root);

    if(Bin_Find(Root,20))
        std::cout << "Found";
    else
        std::cout << "Not Found";
}
