#include <iostream>


struct ListNode {
	int data;
	ListNode* next;
	ListNode(int data = 0,  ListNode* next = nullptr) :
		data(data), next(next) {}
};

ListNode* createList(ListNode*& head, std::initializer_list<int> init_l) {
	auto it = init_l.begin();
	head = new ListNode(*it);
	ListNode* temp = head;
	++it;
	for (; it != init_l.end(); ++it) {
		head->next = new ListNode(*it);
		head = head->next;
	}
	return temp;
}

void deleteList(ListNode* head) {
	while (head->next) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
}

ListNode* reverse_list(ListNode* head) {
	if (!head) {
		return nullptr;
	}
	if (!head->next) {
		return head;
	}
	ListNode* tail = reverse_list(head->next);
	head->next->next = head;
	head->next = nullptr;
	return tail;
}

int main() {

	ListNode* head;
	head = createList(head, { 9, 7, 2 });
	ListNode* newhead = reverse_list(head);
	ListNode* temp1 = newhead;
	while (temp1) {
		std::cout << temp1->data << " ";
		temp1 = temp1->next;
	}
	deleteList(head);
}
