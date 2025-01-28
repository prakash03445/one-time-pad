#include <iostream>
#include <fstream>
#include <cstdlib>

void encrypt(std::ifstream& file, std::ofstream& encrypted_file, std::ofstream& key_file) {
    char c;
    while (file.get(c)) {
        int key = rand();
        int encrypted_char = c ^ (key & 0xFF);

        key_file.put(static_cast<char>(key & 0xFF));
        encrypted_file.put(encrypted_char);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file to encrypt> " << std::endl;
        return 1;
    }

    std::ifstream file(argv[1], std::ios::binary);
    std::ofstream encrypted_file("crypt.out", std::ios::binary);
    std::ofstream key_file("key.out", std::ios::binary);

    encrypt(file, encrypted_file, key_file);

    std::cout << "Encryption complete. Files: crypt.out and key.out creatd.\n";

    file.close();
    encrypted_file.close();
    key_file.close();

    return 0;
}