# jenkins-cpp-example
`jenkins-cpp-example` is an example C++ project demonstrating Jenkins CI/CD integration, primarily by allowing explicit control over its exit status for testing purposes.

## Prerequisites (to build the C++ project)
Before you begin, ensure you have the following installed:
* [Git](https://git-scm.com/)
* [CMake](https://cmake.org/) (version 3.16 or higher recommended)
* A C++ compiler that supports C++11 (GCC, Clang, MSVC)
* (Optional, for documentation) [Doxygen](https://www.doxygen.nl/)

## Building the C++ project
1. Clone the repository: `git clone https://github.com/SavaLione/jenkins-cpp-example.git`
2. Navigate to the project directory: `cd jenkins-cpp-example`
3. Create and enter a build directory: `mkdir build && cd build`
4. Configure the project with CMake: `cmake ..`
5. Compile the project:
    * Linux/BSD: `make`
    * Windows using MSBuild (typically found with Visual Studio): `MSBuild.exe jenkins-cpp-example.sln`
    * Using Ninja: `ninja`

The executable `jenkins-cpp-example` (or `jenkins-cpp-example.exe` on Windows) will be located in the `build` directory (or a subdirectory like `build/Release` depending on your generator and configuration).

## Documentation
This project supports Doxygen for code documentation.

To generate the documentation, navigate to the project's root directory and run:
```bash
doxygen doxyfile
```

## License
`jenkins-cpp-example` is licensed under the terms of [The GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.en.html).
