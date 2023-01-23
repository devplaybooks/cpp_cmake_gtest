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
* [Your GitHub Conspaces](https://github.com/codespaces)
