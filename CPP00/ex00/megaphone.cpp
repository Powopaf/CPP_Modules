#include <iostream>
#include <cctype>

int	main(int ac, char **av) {
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	while (*++av) {
		for (int i = 0; (*av)[i]; i++)
			std::cout << (char)std::toupper((unsigned char)(*av)[i]);
	}
	return (std::cout << '\n', 0);
}
