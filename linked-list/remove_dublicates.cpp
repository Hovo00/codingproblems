#include <iostream>


struct ListNode {
	int data;
	ListNode* prev;
	ListNode* next;
	ListNode(int data = 0, ListNode* prev = nullptr, ListNode * next = nullptr) :
		data(data), next(next), prev(prev) {}
};

ListNode* createList(ListNode*& head, std::initializer_list<int> init_l) {
	auto it = init_l.begin();
	head = new ListNode(*it);
	ListNode* temp = head;
	++it;
	for (; it != init_l.end(); ++it) {
		head->next = new ListNode(*it, head);
		head = head->next;
	}
	return temp;
}

void deleteList(ListNode* head) {
	while (head -> next) {
		head = head->next;
		delete head->prev;
	}
	delete head;
}

int main() {
	
	ListNode* head;
	head = createList(head, {1, 2, 7, 15, 102,102, 64});
	ListNode* temp = head;
	while (temp) {
		ListNode* temp2 = temp->next;
		while (temp2) {
			if (temp2->data == temp->data) {
				ListNode* del = temp2;
				temp2->prev->next = temp2 -> next;
				temp2 = del->next;
				delete del;
			}
			else {
				temp2 = temp2->next;
			}
		}
		temp = temp->next;
	}
	temp = head;
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	deleteList(head);
}
