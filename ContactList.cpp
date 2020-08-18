#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct BTreeNode
{
    char name[128];
    int phone;
    int no;
    struct BTreeNode *left;
    struct BTreeNode *right;
};
typedef struct BTreeNode node;
node *search_node(node *ptr, node input)
{
    node *temp;

    if (ptr != NULL)
    {
        //�b�o�̦L�X�M����L�����
        //printf("%d ", ptr->data);

        if (strcmp(ptr->name, input.name) == 0)
            return ptr;
        else
        {
            temp = search_node(ptr->left, input);

            if (temp != NULL)
            {

                return temp;
            }

            temp = search_node(ptr->right, input);

            if (temp != NULL)
            {

                return temp;
            }
        }
    }
    return NULL;
}
void print_preorder(node *ptr)
{
    if (ptr != NULL)
    {
        printf("Name: %s", ptr->name);
        puts("");
        printf("Phone: %d", ptr->phone);
        puts("");
        printf("No: %d\n\n", ptr->no);

        print_preorder(ptr->left);
        print_preorder(ptr->right);
    }
}

void print_postorder(node *ptr)
{
    if (ptr != NULL)
    {

        print_postorder(ptr->left);
        print_postorder(ptr->right);
        printf("Name: %s", ptr->name);
        puts("");
        printf("Phone: %d", ptr->phone);
        puts("");
        printf("No: %d\n\n", ptr->no);
    }
}

void print_inorder(node *ptr)
{
    if (ptr != NULL)
    {
        print_inorder(ptr->left);
        printf("Name: %s", ptr->name);
        puts("");
        printf("Phone: %d", ptr->phone);
        puts("");
        printf("No: %d\n\n", ptr->no);

        print_inorder(ptr->right);
    }
}

node *insert_node(node *root, node input)
{
    node *new_node;
    node *current;
    node *parent;

    new_node = (node *)malloc(sizeof(node));
    *new_node = input;
    new_node->left = NULL;
    new_node->right = NULL;
    if (root == NULL)
    {
        root = new_node; //return new_node;
    }
    else
    {
        current = root;
        while (current != NULL)
        {
            parent = current;
            if (strcmp(current->name, input.name) > 0)
                current = current->left;
            else
                current = current->right;
        }
        if (strcmp(parent->name, input.name) > 0)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return root;
}

// ��Y�Ȥ����`�I
node *find_parent(node *ptr, node input, int *pos)
{
    node *parent;

    parent = ptr; // �qptr�}�l��
    *pos = 0;
    while (ptr != NULL)
    {

        if (ptr->no == input.no) // ���ؼ�
            return parent;       // �^�Ǧ��`�I�����`�I
        else
        {
            parent = ptr;
            if (ptr->no > input.no)
            {
                *pos = -1;       // ptr�bparent���l��
                ptr = ptr->left; // ������
            }
            else
            {
                *pos = 1;         // ptr�bparent�k�l��
                ptr = ptr->right; // ���k��
            }
        }
    }
    return NULL; // �䤣��
}

// �R���`�I
node *delete_node(node *root, node input)
{
    node *parent;
    node *ptr;
    node *next;
    int pos;

    parent = find_parent(root, input, &pos); // �qroot�}�l,��value�����`�I
    if (parent != NULL)                      // �����, �ǳƧR��
    {
        switch (pos) // �P�_�ثe�`�I�A���`�I����Υk��
        {
        case -1:
            ptr = parent->left;
            break;
        case 1:
            ptr = parent->right;
            break;
        case 0:
            ptr = parent;
            break;
        }
        if (ptr->left == NULL) // ���p1: �`�I�S�����l�� �p�G�n�R���O�ڸ`�I
        {
            if (parent == ptr) // �p�G�n�R���O�ڸ`�I
                root = root->right;
            else // ��L
            {
                if (pos == 1)
                {
                    //�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I���k�`�I
                    parent->right = ptr->right;
                }
                else
                {
                    //�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I���k�`�I
                    parent->left = ptr->right;
                }
            }
            free(ptr);
        }
        else if (ptr->right == NULL) // ���p2: �`�I�S���k�l��
        {
            if (parent != ptr)
            {
                if (pos == 1)
                {
                    //�n�R�����`�I�b���`�I�k��,�ҥH�N���`�I���k�`�I���V�R���`�I�����`�I
                    parent->right = ptr->left;
                }
                else
                {
                    //�n�R�����`�I�b���`�I����,�ҥH�N���`�I�����`�I���V�R���`�I�����`�I
                    parent->left = ptr->left;
                }
            }
            else
                root = root->left;
            free(ptr);
        }
        else // ���p3: �`�I�����k�l��
        {
            parent = ptr;
            next = ptr->left; // ����N�Inext, �qptr����}�l��
            if (next->right != NULL)
            {
                while (next->right != NULL) // �����l�`�I���k�l���̤j�ȷ����N�I
                {
                    parent = next; // parent��next�����`�I
                    next = next->right;
                }

                parent->right = next->left; // ¶�Lnext�`�I
                                            // �R��next (�`�N: ���O�R��ptr)
            }
            else
            {

                ptr->left = next->left;
            }
            strcpy(ptr->name, next->name);
            ptr->phone = next->phone;
            ptr->no = next->no;
            free(next);
        }
    }
    return root; // �^�Ǧ���
}

int main()
{

    node input;
    char op;
    node *root = NULL, *ptr;
    int count = 1;
    while (1)
    {
           	puts("i insert");
           	puts("l list inorder");
           	puts("m list preorder");
           	puts("n list postorder");
           	puts("d delete the input number");
           	puts("f find the input number");
           	puts("q quit");
        scanf(" %c", &op);
        switch (op)
        {
        case 'i':
            scanf("%s", &input.name);
            scanf("%d", &input.phone);
            input.no = count;
            count++;
            root = insert_node(root, input);
            break;
        case 'l':
            print_inorder(root);
            //puts("");
            break;
        case 'm':
            print_preorder(root);
            //puts("");
            break;
        case 'n':
            print_postorder(root);
            //puts("");
            break;
        case 'd':
            scanf("%d", &input.no);
            root = delete_node(root, input);

            if (root != NULL)
            {
                printf("delete No. %d ok\n\n", input.no);
            }
            else
            {
                puts("cannot delete");
            }
            break;
        case 'f':
            scanf("%s", &input.name);

            ptr = search_node(root, input);

            if (ptr != NULL)
            {
                printf("found:\n");
                printf("Name: %s", ptr->name);
                puts("");
                printf("Phone: %d", ptr->phone);
                puts("");
                printf("No: %d\n\n", ptr->no);
            }
            else
            {
                puts("not found");
            }
            break;
        case 'q':
            return 0;
            break;
        }
    }
    return 0;
}
