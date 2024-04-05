#include <dynalo/dynalo.hpp>

#include <cstdint>
#include <sstream>
#include <iostream>

// usage: loader "path/to/shared/lib/dir"
int main(int argc, char *argv[])
{
    std::cout << "loader" << std::endl;
    if (argc < 2)
    {
        std::cerr << "usage: loader <path/to/shared/lib/dir>" << std::endl;
        return 1;
    }
    auto shared_lib_path = std::string(argv[1]) + "/" + dynalo::to_native_name("dynalo_test_shlib");
    std::cout << "loading shared library: " << shared_lib_path << std::endl;
    dynalo::library lib(shared_lib_path);

    auto add_integers = lib.get_function<int32_t(const int32_t, const int32_t)>("add_integers");
    auto print_message = lib.get_function<void(const char *)>("print_message");

    std::ostringstream oss;
    oss << "it works: " << add_integers(1, 2);
    print_message(oss.str().c_str());
}
