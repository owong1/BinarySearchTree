#include <iostream>
#include "Btree.h"

int main(){
	int values[12] = { 55, 27, 68, 19, 32, 70, 105, 3, 21, 93, 5, 34 };
	btree B;

	//print btree
	std::cout << "Key values: " << std::endl;		//no tree yet
	B.inOrder();
	std::cout << "Values to be inserted: " << std::endl;
	for (int i = 0; i < 12; i++){
		std::cout << values[i] << " ";
		B.insert(values[i]);
	}
	std::cout << "\nKey values in order: " << std::endl;
	B.inOrder();

	std::cout << "\nKey values pre order: " << std::endl;
	B.preOrder();

	std::cout << "\nKey values post order: " << std::endl;
	B.postOrder();

	//run search
	std::cout << "\nValue to search: 8" << std::endl;		//not in array: should not be found
	B.search(8);
	std::cout << "Value to search: 32" << std::endl;		//in array: should be found
	B.search(32);

	getchar();
	return 0;
}