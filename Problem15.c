#include <stdio.h>

int main()
{	
	long double grid_size = 20;
	long double lattice_path_routes = 1;
	for (int i = 1; i <= grid_size; ++i)
		lattice_path_routes *= ((grid_size + i) / i);

	printf("Lattice route number: %lf\n", lattice_path_routes);

	return 0;
}
