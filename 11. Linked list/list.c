#include "list.h"

Node *CreateNode(int val)
{
    Node *node = (Node *)malloc(sizeof(Node)); 
    node->next = NULL;
    node->val = val;
    return node;
}
bool empty(Node *head)
{
    return (head == NULL);
}
void printNode(Node *head)
{
    if(empty(head)){
        printf("empty list\n");
        return;
    }
    Node *current = head;
    while(current != NULL){
        printf("%d\t",current->val);
        current = current->next;

    }
    printf("\n");
    
}
void push_back(Node **head, int value)
{
    //tạo node mới
    Node *node = CreateNode(value);    

    //kiểm tra và cập nhật node đầu nếu danh sách rỗng
    if (empty(*head))
    {
        *head = node;
        return;
    }

    //gán địa chỉ node đầu 
    Node *current = *head; 

    //duyệt cho đến khi gặp node cuối 
    while (current->next != NULL)
    {
        current = current->next; 
    }

    //cập nhật node cuối
    current->next = node;
}
void pop_back(Node **head)
{
    //nếu danh sách rỗng thì dừng xử lý
    if (empty(*head))   printf("no node in linked list\n");
    
    else{
        Node *current = *head;

        //xử lý nếu chỉ có 1 node
        if (current->next == NULL){
            free(current);
            *head = NULL;
            return;
        }

        //xử lý nếu có 2 node trở lên
        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node *last_node = current->next; //lưu node cuối
        free(last_node);                 //giải phóng node cuối cũ
        current->next = NULL;             //cập nhật node cuối mới
    }
}
int size(Node *head){
    if(empty(head)) return 0;
    else{
        Node* current = head;
        int size = 1;
        while(current->next != NULL){
            current = current->next;
            size++;
        }
        return size;
    }
}
int front(Node *head){
    if(empty(head)) return EMPTY_LIST;
    else{
        int front = head->val;
        return front;
    }
}
int back(Node *head){
    if(empty(head)) return EMPTY_LIST;
    else{
        Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        int back = current->val;
        return back;
    }
}
int get(Node *head, int pos){
    
    if(empty(head)) return EMPTY_LIST;

    int last_position = size(head) - 1;

    //kiểm tra vị trí pos có hợp lệ
    if(pos >= 0 && pos <= last_position){
        Node* current = head;
        int index = 0;

        //duyệt qua tửng node đến vị trí pos
        while(index < pos){
            current = current->next;
            index++;
        }
        int get_value = current->val;
        return get_value;
    }
    else 
        return INVALID_VALUE; // có giá trị -1
}
void push_front(Node **head, int value){
    //tạo node mới
    Node *node = CreateNode(value);    

    //kiểm tra và cập nhật node đầu nếu danh sách rỗng
    if (empty(*head))
    {
        *head = node;
        return;
    }
    //cập nhật node đầu của list
    node->next = *head;
    *head = node;
}
void pop_front(Node **head){
    //nếu danh sách rỗng thì dừng xử lý
    if (empty(*head))   printf("no node in linked list\n");
    else{
        Node* current = *head;
        //xử lý nếu chỉ có 1 node
        if (current->next == NULL){
            free(current);
            *head = NULL;
            return;
        }
        //xử lý nếu có 2 node trở lên
        *head = (*head)->next;
        free(current);
    }
}
void insert(Node **head, int value, int position){
    int last_position = size(*head) - 1;
    
    //kiểm tra vị trí insert có hợp lệ
    if(position > last_position || position < 0){
        printf("vị trí insert không hợp lệ");
        return;
    }
    //xủ lý chèn ở đầu list
    if(position == 0)                  push_front(head,value);
    //xử lý chèn ở cuối list
    else if(position == last_position) push_back(head,value);
    //xủ lý chèn ở các vị trí insert còn lại
    else{
        Node* new_node = CreateNode(value);

        Node* current = *head;
        int index = 0;

        //duyệt qua từng node đến vị trí trước node cần xóa
        while(index < position - 1){
            current = current->next;   
            index++;
        }
        //cập nhật node mới tại vị trí insert
        new_node->next = current->next;
        current->next = new_node;
    }
}

void erase(Node **head, int position){
    if(empty(*head)){
        printf("empty linked list\n");
        return;
    }
    
    int last_position = size(*head) - 1;

    if(position > last_position || position < 0){
        printf("vị trí erase không hợp lệ (0 - %d)",last_position);
        return;
    }
    else if(position == 0)               pop_front(head);
    else if(position == last_position)   pop_back(head);
    else{
        Node* current = *head;
        int index = 0;

        while(index < position - 1){
            current = current->next;
            index++;
        }

        //lưu trữ node cần xóa
        Node* temp = current->next;

        //cập nhật node hiện tại trỏ đến địa chỉ sau node cần xóa
        current->next = current->next->next;

        //xóa node đã lưu 
        free(temp);
    }

}
void clear(Node **head){
    if(empty(*head)){
        printf("empty linked list");
        return;
    }
    Node* temp = NULL;
    while(*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
}