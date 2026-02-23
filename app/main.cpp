#include <bits/stdc++.h>
#include "my_lib.h"
#include "config.hpp"

#include <nlohmann/json.hpp>

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

    print_hello_world();
    return 0;
}