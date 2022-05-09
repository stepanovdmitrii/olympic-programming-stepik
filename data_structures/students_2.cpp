#include <iostream>
#include <vector>
#include <algorithm>

//0.75 of 3.00

struct node
{
    size_t number;
    node* next;
    node* prev;
};


int main() {
    size_t count;
    std::cin >> count;
    
    std::vector<node*> queue;
    queue.reserve(count);
    node* head = nullptr;
    
    int s = 0;
    size_t deleted = 0;
    for(size_t k = 1; k <= count; ++k){
        std::cin >> s;

        if(s < 0) {
            s = -s;
            node* to_drop = queue[s - 1];
            queue[s - 1] = nullptr;

            if(to_drop->prev == nullptr) { //head
                head = to_drop->next;
            } else {
                to_drop->prev->next = to_drop->next;
            }
            delete to_drop;
            ++deleted;
        } else if (s == 0) {
            node* n = new node();
            n->number = k - deleted;
            n->prev = nullptr;
            n->next = head;
            if(head != nullptr) {
                head->prev = n;
            }
            head = n;
            queue.push_back(n);
        } else {
            node* n = new node();
            n->number = k - deleted;
            node* after = queue[s - 1];
            node* after_next = after->next;
            n->next = after_next;
            n->prev = after;
            after->next = n;
            if(after_next != nullptr) {
                after_next->prev = n;
            }
            queue.push_back(n);
        }
    }
    size_t left = queue.size();
    while (head != nullptr && left != 0){
        std::cout << head->number << " ";
        head = head->next;
        --left;
    }
}