#include <iostream>
#include <cctype>

static void change(char *ptr, size_t size, int (*func)(int)) {
	for (size_t i = 0; i < size; i++) ptr[i] = static_cast<char>(func(static_cast<unsigned char>(ptr[i])));
}


int	main(int ac, char **av) {
	if (ac == 1) return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	while (*++av) {
		for (int i = 0; i[*av]; i++) change(*av + i, 1, static_cast<int (*)(int)>(std::toupper));
		for (int i = 0; i[*av]; i++) std::cout << i[*av];
	} return (std::cout << '\n', 0);
}
