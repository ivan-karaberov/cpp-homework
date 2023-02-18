#include <iostream>
#include "LinkedList.h"

int main() {
	my::LinkedList<double> lst;
	lst.push_front(1.0);
	lst.push_front(2.0);
	lst.push_front(3.0);
	lst.push_front(4.0);
	lst.push_front(5.0);

	for (int i = 0; i <= lst.size()-1; i++) {
		std::cout << lst[i]->data << " ";
	}

	std::cout << std::endl;
	
	for (int i = 1; i <= lst.size(); i++) {
		std::cout << lst[-i]->data << " ";
	}
	

    return 0;
}
