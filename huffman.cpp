//GARVIT GANGWAR
//25/DA/027
#include <iostream>
#include <queue>
using namespace std;

// Node of Huffman Tree
struct Node
{
    char ch;
    int freq;

    Node *left;
    Node *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

// Compare nodes based on frequency
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

// Generate Huffman codes
void generateCodes(Node *root, string code)
{
    if (root == NULL)
        return;

    // If it is a leaf node
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " : " << code << endl;
        return;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

int main()
{
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node *, vector<Node *>, Compare> pq;

    cout << "Enter character and frequency:\n";

    for (int i = 0; i < n; i++)
    {
        char ch;
        int freq;

        cin >> ch >> freq;

        Node *newNode = new Node(ch, freq);
        pq.push(newNode);
    }

    // Build Huffman Tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        Node *newNode = new Node('$', left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Root of Huffman Tree
    Node *root = pq.top();

    cout << "\nHuffman Codes:\n";
    generateCodes(root, "");

    return 0;
}
