#include <iostream>

std::string Crypt(std::string input, std::string key) {
	std::string output;
	char toInput;
	while(key.length() < input.length()) {
		key += key;
	}
	for(int i = 0; i < input.length(); i++) {
		if(input[i] <= 122 && input[i] - (key[i]/10) >= 33) {
			toInput = input[i] - (key[i] / 10);
			output = output + toInput;
		} else if(input[i] - (key[i]/10) <= 33 && input[i] + (key[i]/10) <= 122){
			toInput = input[i] + (key[i] / 10);
			output = output + toInput;
		} else {
			toInput = input[i] - 1;
		}

	}
	return output;
}
std::string Decrypt(std::string input, std::string key) {
	std::string output;
	char toInput;
	while(key.length() < input.length()) {
		key += key;
	}
	for(int i = 0; i < input.length(); i++) {
		if(input[i] <= 122 && input[i] - (key[i]/10) >= 33) {
			toInput = input[i] + (key[i] / 10);
			output = output + toInput;
		} else if(input[i] - (key[i]/10) <= 33 && input[i] + (key[i]/10) <= 122){
			toInput = input[i] - (key[i] / 10);
			output = output + toInput;
		} else {
			toInput = input[i] + 1;
		}
	}
	return output;
}

int main() {
	// Usage:
	std::cout << Crypt("string to encrypt", "a") << std::endl;
	std::cout << Decrypt("jki`e^)kf)\\eZipgk", "a") << std::endl;
}