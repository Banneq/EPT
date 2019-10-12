#include "func.h"



int main() {
	v_alloc_table_add_5(2);

	int** pi_table;
	
	std::cout << "Allocation: " << b_alloc_table_2_dim(pi_table, 5, 5) << std::endl;
	std::cout << "Deallocation: " << b_dealloc_table_2_dim(pi_table, 5, 5) << std::endl;
	return 0;
}