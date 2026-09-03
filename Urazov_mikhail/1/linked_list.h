typedef struct Node {
    void* data;
    struct Node* next;
} Node;

Node* create_list();

void* get(Node* list, int index);

void push_back(Node* list, void* data);

void delete_list(Node* list);
