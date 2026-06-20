#include <fstream>
#include <iostream>
#include <random>

namespace {
    class GetInit {

        int r = 0;
        int g = 0;
        int b = 0;

    public:

        virtual ~GetInit() = default;

        GetInit(const int r, const int g, const int b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }

        virtual void PrintColorCodes() {
            std::println("R: {}", this->r);
            std::println("G: {}", this->g);
            std::println("B: {}", this->b);
        }
    };
}

int main() {
    std::random_device colors;
    std::mt19937 rand_num(colors());
    std::uniform_real_distribution<double> colorCode(1, 254 + 1);


    const int r = static_cast<int>(colorCode(rand_num));
    const int g = static_cast<int>(colorCode(rand_num));
    const int b = static_cast<int>(colorCode(rand_num));

    GetInit color(r,g, b);

    color.PrintColorCodes();

    std::cout << std::hex << r << std::hex << g << std::hex << b;

    if (std::ofstream fFile("color.colors.txt"); fFile.is_open()) {
        fFile << "R: " << r << "\n";
        fFile << "G: " << g << "\n";
        fFile << "B: " << b << "\n";
        fFile << "B: " << b << "\n";
        fFile << "#" <<  std::hex << r<< std::hex << g << std::hex << b;

        fFile.close();
    }


    return 0;
}
