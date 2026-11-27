#include <print>
#include <random>

int main()
{
    std::println("Hello World");
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < 10; ++i)
    {
        
        std::uniform_real_distribution<float> dist_real(0.0f, 10.0f);
        std::println("{}", dist_real(gen));
    }
    return 0;
}
