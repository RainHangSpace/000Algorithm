#include <iostream>
#include <sstream>

int main() {
	std::string hexString;
	std::cout << "Enter a hexadecimal number (e.g., 0xAB): ";
	std::cin >> hexString;

	// 从字符串转换为整数
	std::stringstream ss(hexString);
	int value = 0;
	ss >> std::hex >> value;

	std::cout << "Hex " << hexString << " in decimal is: " << std::dec << value << std::endl;

	// 以下是你想要进行变长编码的地方
	// 你可以根据之前提供的编码例子进行编码

	return 0;
}
