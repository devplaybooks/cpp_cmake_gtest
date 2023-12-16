[![Build and Test](https://github.com/devplaybooks/cpp_cmake_gtest/actions/workflows/test.yml/badge.svg)](https://github.com/devplaybooks/cpp_cmake_gtest/actions/workflows/test.yml)
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg)](CODE_OF_CONDUCT.md)

# C++ Gtest Playbook

C++ template for CMake and Google Test with a custom GitHub [Action](https://github.com/features/actions) and
[Codespace](https://github.com/features/codespaces).  

## Usage

```
$❯ cmake -S . -B build
$❯ cmake --build build
$❯ cd build
$❯ make test
$❯ cd ..
```

## Dependencies

* [CMake](https://cmake.org/)
* [GoogleTest](https://github.com/google/googletest)
    * [User’s Guide](https://google.github.io/googletest/)

## Resources

* [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md)
* [Your GitHub Codespaces](https://github.com/codespaces)

## Possible Resources

* [Hunter](https://hunter.readthedocs.io/en/latest/) 
  * [GitHub](https://github.com/cpp-pm/hunter)
  * [A Quick introduction to Hunter](https://kxygk.github.io/hunterintro.html)
  * [C++ package managers in CMake: Hunter and Conan](https://www.reddit.com/r/cpp/comments/hjpwd0/c_package_managers_in_cmake_hunter_and_conan/)
* [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake)