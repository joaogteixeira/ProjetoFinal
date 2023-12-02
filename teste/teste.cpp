#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Locadora.hpp"

TEST_CASE("Teste cadastrarFilme") {
    Locadora locadora;

    CHECK_NOTHROW(locadora.cadastrarFilme(1, "Filme1", 10.0, 5));

    CHECK_THROWS_AS(locadora.cadastrarFilme(0, "Filme2", 15.0, 3), std::invalid_argument);

    CHECK_THROWS_AS(locadora.cadastrarFilme(2, "", 20.0, 8), std::invalid_argument);
}
