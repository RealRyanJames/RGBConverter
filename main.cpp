#include <fstream>
#include <iostream>
#include <random>


int main() {
    std::random_device colors;
    std::mt19937 rand_num(colors());
    std::uniform_real_distribution<double> colorCode(1, 254 + 1);

    const int r = static_cast<int>(colorCode(rand_num));
    const int g = static_cast<int>(colorCode(rand_num));
    const int b = static_cast<int>(colorCode(rand_num));

    std::cout << "R: " <<  r << std::endl;
    std::cout << "G: " <<  g << std::endl;
    std::cout << "B: " <<  b << std::endl;

    std::cout << std::hex << r << std::hex << g << std::hex << b;

    if (std::ofstream fFile("color.colors.txt"); fFile.is_open()) {
        fFile << "R: " << r << "\n";
        fFile << "G: " << g << "\n";
        fFile << "B: " << b << "\n";
        fFile << "B: " << b << "\n";
        fFile << "#" <<  std::hex << r<< std::hex << g << std::hex << b;

        fFile.close();
    }

    system("pause > 0");
    return 0;
}