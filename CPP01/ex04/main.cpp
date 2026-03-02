#include <iostream>
#include <fstream>
#include <istream>
#include <string>

static int copy(std::ifstream& in, std::ofstream& out, std::string s1, std::string s2) {
	std::string line;
	while (1) {
		std::getline(in, line);
		if (in.eof())
			break;
		if (in.fail() || in.bad()) {
			std::cerr << "Error reading file" << std::endl;
			return 1;
		}
		size_t pos = 0;
		size_t found = 0;
		while ((found = line.find(s1, pos)) != std::string::npos) {
			// Write everything from pos to found
			for (size_t i = pos; i < found; i++) {
				out << line[i];
			}
			// Write the replacement
			out << s2;
			// Move past the found string
			pos = found + s1.size();
		}
		// Write remaining characters
		for (size_t i = pos; i < line.size(); i++) {
			out << line[i];
		}
		out << std::endl;
	}
	return 0;
}


int main(int argc, char** argv) {
	if (argc != 4) {
		std::cout << "Usage: ./copy filename s1 s2" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1], std::ios::in);
	if (!file.is_open()) {
		std::cerr << "Error opening file" << std::endl;
		return 1;
	}
	std::ofstream out((std::string(argv[1]) + ".replace").c_str(), std::ios::out | std::ios::trunc);
	if (!out.is_open()) {
		std::cerr << "Error opening output file" << std::endl;
		return 1;
	}
	int ret = copy(file, out, argv[2], argv[3]);
	file.close();
	out.close();
	return ret;
}
