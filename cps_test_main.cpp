#define CATCH_CONFIG_FAST_COMPILE
// Disable some features for faster compile
#define CATCH_CONFIG_RUNNER  // We write our own main
#include "catch.hpp"         // For the "Catch" unit-testing framework

int main(int argc,
         char *argv[])
{
    const std::string tname = "CPS"
                              " - CS 372 Project 2";
    // Printable name for this test suite
    Catch::Session session;  // Primary Catch object
    int catchresult;         // Catch return code; for return by main

    // Handle command line
    catchresult = session.applyCommandLine(argc, argv);

    if (!catchresult)  // Continue only if no command-line error
    {
        // Run test suites
        std::cout << "BEGIN tests for "
                  << tname << std::endl << std::endl;
        catchresult = session.run();
        std::cout << "END tests for "
                  << tname << std::endl << std::endl;
    }

    // Program return value is return code from Catch
    return catchresult;
}
