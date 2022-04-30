#include <iostream>
#include <vector>
#include <algorithm>

struct node
{
    size_t number;
    node* next;
};


int main() {
    size_t count;
    std::cin >> count;
    
    std::vector<node*> queue(count, nullptr);
    node* head = nullptr;
    
    size_t after = 0;
    for(size_t idx = 0; idx < count; ++idx){
        std::cin >> after;
        node* n = new node();
        n->number = idx + 1;
        queue[idx] = n;
        if(after == 0) {
            n->next = head;
            head = n;
            continue;
        }
        
        after--;
        node* after_node = queue[after];
        n->next = after_node->next;
        after_node->next = n;
    }

    while (head != nullptr){
        std::cout << head->number << " ";
        head = head->next;
    }
}