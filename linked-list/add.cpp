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

void add_lists(ListNode* head1, ListNode* head2, ListNode*& head3) {
	int remain = 0;
	head3 = new ListNode();
	ListNode* temp1 = head1;
	ListNode* temp2 = head2;
	ListNode* temp = head3;
	int m = temp1->data + temp2->data;
	temp1 = temp1->next;
	temp2 = temp2->next;
	temp->data = m > 9 ? m - 10 : m;
	remain = m > 9 ? 1 : 0;
	while (temp1 && temp2) {
		temp->next = new ListNode();
		m = temp1->data + temp2->data + remain;
		temp->next->data = m > 9 ? m - 10 : m;
		remain = m > 9 ? 1 : 0;
		temp = temp->next;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	while (temp1) {
		temp->next = new ListNode(temp1->data);
		temp1 = temp1->next;
	}
	while (temp2) {
		temp->next = new ListNode(temp2->data);
		temp2 = temp2->next;
	}
	if (remain) {
		temp->next = new ListNode(remain);
	}
}

int main() {

	ListNode* head1;
	ListNode* head2;
	head1 = createList(head1, { 2, 1, 2, 7 });
	head2 = createList(head2, { 9, 7, 2 });
	ListNode* head3;
	add_lists(head1, head2, head3);
	ListNode* tempik = head3;
	std::cout << std::endl;
	while (tempik) {
		std::cout << tempik->data << " ";
		tempik = tempik->next;
	}
	deleteList(head1);
	deleteList(head2);
	deleteList(head3);
}
