#include "randompass.h"
#include <argparse/argparse.hpp>

int main(int argc, char *argv[])
{
    argparse::ArgumentParser program("randpass");

    program.add_argument("-L", "--length")
        .help("length of the password string")
        .default_value(10)
        .action([](const std::string &value) { return std::stoi(value); });

    program.add_argument("-p", "--pass")
        .help("number of passwords to be generated")
        .default_value(1)
        .action([](const std::string &value) { return std::stoi(value); });

    program.add_argument("-u")
        .help("include uppercase characters in password")
        .default_value(false)
        .implicit_value(true);

    program.add_argument("-l")
        .help("include lowecase characters in password")
        .default_value(false)
        .implicit_value(true);

    program.add_argument("-s")
        .help("include symbols in password")
        .default_value(false)
        .implicit_value(true);

    program.add_argument("-n")
        .help("include numbers in password")
        .default_value(false)
        .implicit_value(true);

    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err)
    {
        std::cout << err.what() << std::endl;
        std::cout << program;
        exit(0);
    }
    auto length = program.get<int>("--length");
    auto pass = program.get<int>("--pass");
    auto lower = program.get<bool>("-l");
    auto upper = program.get<bool>("-u");
    auto symbol = program.get<bool>("-s");
    auto number = program.get<bool>("-n");

    if ((lower || upper || symbol || number) == false)
    {
        lower = true, upper = true, symbol = true, number = true;
    }

    auto passwords = randpass::generatePass(length, pass, lower, upper, symbol, number);
    for (auto password : passwords)
    {
        std::cout << "\n" << password;
    }

    return 0;
}