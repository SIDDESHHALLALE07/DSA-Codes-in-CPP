extern "C" int printf(const char*, ...);
extern "C" int scanf(const char*, ...);

struct Node
{
    int data;
    Node *left, *right;
};

// Function to create a binary tree
Node *root = nullptr;
class Tree
{
    public:
    void insert(Node *&temp, int value)
{
    if (temp == nullptr)
    {
        temp = new Node;
        temp->data = value;
        temp->left = nullptr;
        temp->right = nullptr;
        return;
    }

    if (temp->left == nullptr)
    {
        insert(temp->left, value);
    }
    else if (temp->right == nullptr)
    {
        insert(temp->right, value);
    }
    else
    {
        // Continue searching (example: go to left subtree first)
        insert(temp->left, value);
    }
}



// Inorder Traversal
void inorder(Node *temp)
{
     if (temp == nullptr)
                return;
    else
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

// Preorder Traversal
void preorder(Node *temp)
{
     if (temp == nullptr)
                return;
    else
    {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

// Postorder Traversal
void postorder(Node *temp)
{
     if (temp == nullptr)
                return;
    else
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}
};
int main()
{
   Tree t;
    int choice,value;

    do
    {
        printf("\n===== Binary Tree Menu =====");
        printf("\n1.  Insert Node Binary Tree");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to be inserted");
            scanf("%d", &value);
                t.insert(root,value);

            break;

        case 2:
 if(root == nullptr)
        printf("Tree is empty!");
    else
    {


                printf("Inorder Traversal: ");
                t.inorder(root);
                printf("\n");
    }
            break;

        case 3:
             if(root == nullptr)
        printf("Tree is empty!");
    else
    {
                printf("Preorder Traversal: ");
                t.preorder(root);
                printf("\n");
    }
            break;

        case 4:
 if(root == nullptr)
        printf("Tree is empty!");
    else
    {
                printf("Postorder Traversal: ");
                t.postorder(root);
                printf("\n");
    }
            break;

        case 5:
            printf("Program Exited.");
            break;

        default:
            printf("Invalid Choice!");
        }

    } while (choice != 5);

    return 0;
}