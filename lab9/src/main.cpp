#include <iostream>
#include <vector>
#include <iterator>

#include "../include/QuadraticEquation.h"
#include "../include/Complex.h"

int main()
{	
    int N;
    std::cout << "Введите число уравнений: ";
    std::cin >> N;

    std::vector<QuadraticEquation> equations;
    
    for (int i = 0; i < N; i++) {
        double a_r, a_i, b_r, b_i, c_r, c_i;
        std::cout << "Коэффициенты уравнения " << i + 1 << " (a, b, c) (реальная и мнимая части через пробел):\n";
        std::cin >> a_r >> a_i >> b_r >> b_i >> c_r >> c_i;

        Complex a(a_r, a_i);
        Complex b(b_r, b_i);
        Complex c(c_r, c_i);
        
        equations.emplace_back(a, b, c);
    }

	std::cout << "Корни уравнений:" << std::endl;
	std::copy(equations.begin(), equations.end(), std::ostream_iterator<QuadraticEquation>(std::cout, "\n"));

	double root_real, root_imag;
	std::cout << "Введите число для проверки наличия среди корней (реальная и мнимая части через пробел):" << std::endl;
	std::cin >> root_real >> root_imag;

	Complex user_root(root_real, root_imag);
	for (int i = 0; i < N; i++)
	{
		if (equations[i].has_root(user_root))
			std::cout << "Число " << user_root << " является корнем уравнения " << i + 1 << "." << std::endl;
		else	
			std::cout << "Число " << user_root << " не является корнем уравнения " << i + 1 << "." << std::endl;
	}

    return 0;
}
