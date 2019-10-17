#include "pch.h"
#include "func.h"

int main() {
	v_alloc_table_add_5(5);

	int** pi_table;
	std::cout << "Allocation: " << b_alloc_table_2_dim(&pi_table, 5, 5) << std::endl;
	/*for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			pi_table[i][j] = 5;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << pi_table[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << **pi_table << std::endl;*/
	std::cout << "Deallocation: " << b_dealloc_table_2_dim(&pi_table, 5) << std::endl;
	//std::cout << pi_table;


	int *ptr;
	std::cout << v_alloc_change_pointer_add_5(&ptr, 5);
	showArray(ptr, 5);
	dealloc(&ptr);
	std::cout << ptr;
	return 0;
}
