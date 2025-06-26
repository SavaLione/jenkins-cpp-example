/* SPDX-License-Identifier: GPL-3.0-or-later */
/*
 * Copyright (C) 2025 Savelii Pototskii (savalione.com)
 *
 * Author: Savelii Pototskii <savelii.pototskii@gmail.com>
 *
 * This file is part of jenkins-cpp-example.
 *
 * jenkins-cpp-example is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * jenkins-cpp-example is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with jenkins-cpp-example. If not, see <https://www.gnu.org/licenses/>.
*/
/**
 * @file jenkins-cpp-example.cpp
 * @brief The application implementation.
 * @details
 *
 * jenkins-cpp-example is an example C++ project demonstrating Jenkins CI/CD integration, primarily by allowing explicit control over its exit status for testing purposes.
 *
 * @author Savelii Pototskii
 * @date 2025-06-25
 * @copyright Copyright (C) 2025 Savelii Pototskii (savalione.com)
 * @copyright SPDX-License-Identifier: GPL-3.0-or-later
*/
#include "jenkins-cpp-example.h"

#include <iostream>
#include <string>
#include <array>

#include "xgetopt/xgetopt.h"
#include "config.h"

int main(int argc, char **argv)
{
    std::string const short_opts = "sfhv";

    // clang-format off
    std::array<xoption, 4> long_options =
        {{
            {"exit-success", xno_argument, nullptr, 's'},
            {"exit-fail",    xno_argument, nullptr, 'f'},
            {"help",         xno_argument, nullptr, 'h'},
            {"version",      xno_argument, nullptr, 'v'}
        }};
    // clang-format on

    while(true)
    {
        auto const opt = xgetopt_long(argc, argv, short_opts.c_str(), long_options.data(), nullptr);

        if(opt == -1)
        {
            break;
        }

        switch(opt)
        {
            case 's':
                exit(0);
                break;
            case 'f':
                exit(1);
                break;
            case 'h':
                print_help();
                exit(0);
                break;
            case 'v':
                std::cout << JCE_VERSION << std::endl;
                exit(0);
                break;
            default:
                exit(0);
                break;
        }
    }

    return 0;
}

void print_help()
{
    std::string help =
        R"(jenkins-cpp-example is an example C++ project demonstrating Jenkins CI/CD integration,
primarily by allowing explicit control over its exit status for testing purposes.

usage: jenkins-cpp-example [options...]

Options:
  --exit-success    Exit immediately with a success code (0).
  --exit-fail       Exit immediately with a failure code (e.g., 1).
  --version         Print the application version and exit.
  -h, --help        Show this help message and exit.

Examples:
  jenkins-cpp-example --exit-success
  jenkins-cpp-example --version
)";
    std::cout << help << std::endl;
}