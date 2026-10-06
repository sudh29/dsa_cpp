#include <iostream>

int main() {
    std::cout << "=== Compiler and System Details ===" << std::endl;
#if defined(__clang__)
    std::cout << "Compiler: Clang " << __clang_version__ << std::endl;
#elif defined(__GNUC__)
    std::cout << "Compiler: GCC " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << std::endl;
#endif

    std::cout << "C++ Standard (__cplusplus): " << __cplusplus << std::endl;
    std::cout << "Pointer size: " << sizeof(void*) * 8 << "-bit" << std::endl;
    return 0;
}
