#include <bits/stdc++.h>
#include "my_lib.h"
#include "config.hpp"

#include <cxxopts.hpp>
#include <nlohmann/json.hpp>
#include <fmt/format.h>
#include <spdlog/spdlog.h>

using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
int main() {
    cout << project_name << "\n";
    cout << project_version << "\n";

    cout << "JSON Lib Version:"
        << NLOHMANN_JSON_VERSION_MAJOR << "."
        << NLOHMANN_JSON_VERSION_MINOR << "."
        << NLOHMANN_JSON_VERSION_PATCH << "\n";

    cout << "FMT:"
        << FMT_VERSION << "\n";

    cout << "CXXOPTS:"
        << CXXOPTS__VERSION_MAJOR << "."
        << CXXOPTS__VERSION_MINOR << "."
        << CXXOPTS__VERSION_PATCH << "\n";

    cout << "SPDLOG:"
        << SPDLOG_VER_MAJOR << "."
        << SPDLOG_VER_MINOR << "."
        << SPDLOG_VER_PATCH << "\n";

    print_hello_world();
    return 0;
}