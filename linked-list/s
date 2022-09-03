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

ListNode* find_kth(ListNode* head, int k) {
	if (!head) { return nullptr; }
	ListNode* fast = head;
	ListNode* slow = head;
	for (int i = 0; i < k; ++i) {
		fast = fast->next;
	}
	while (fast) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main() {

	ListNode* head;
	head = createList(head, { 1, 2, 7, 15, 102,102, 64 });
	ListNode* temp = head;
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	ListNode* elem = find_kth(head, 4);
	std::cout << elem->data;
	deleteList(head);
}
