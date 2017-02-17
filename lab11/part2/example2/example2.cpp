#include <iostream>
#include "linkedList.h"

int main() {
	LinkedList<std::string> dwarfs;
	dwarfs.add("Grumpy");
	dwarfs.add("Sneezy");
	dwarfs.add("Dopey");
	dwarfs.add("Sleepy");
	dwarfs.add("Bashful");
	dwarfs.add("Happy");
	dwarfs.add("Doc");

	for(int i = 0; i < 8; i++) {
		try {
 			 std::cout << dwarfs.get(i) << std::endl;
		} catch (OutOfBounds & o) {
 			 std::cout << o.what() << std::endl;
		}
	}


	return 0;
}