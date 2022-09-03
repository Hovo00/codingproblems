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

ListNode* intersecNode(ListNode* headA, ListNode* headB) {

	ListNode* Node = headA;
	ListNode* temp = headB;
	while (Node != nullptr) {
		temp = headB;
		while (temp != nullptr) {
			if (Node == temp) {
				return Node;
			}
			temp = temp->next;
		}
		Node = Node->next;
	}
	return nullptr;
}

int main() {

	ListNode* head1;
	ListNode* head2;
	head1 = createList(head1, { 9, 7, 2 });
	head2 = createList(head2, { 4, 5});
	head2->next->next = head1->next;
	ListNode* som = intersecNode(head1, head2);
	std::cout << som->data;
	head2->next->next = nullptr;
	deleteList(head1);
	deleteList(head2);
}
