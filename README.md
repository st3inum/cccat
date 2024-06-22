# cccat

This project is an implementation of a custom version of the Unix command line tool `wc`.

## Overview
The challenge is to build your own version of `wc` (word count) which counts lines, words, and characters in a given input.

More details about the challenge can be found at [Coding Challenges - wc Challenge](https://codingchallenges.fyi/challenges/challenge-wc).

## Build Instructions
To build the project, follow these steps:

1. **Clone the repository**:
   ```sh
   git clone git@github.com:st3inum/cccat.git
   cd cccat
   ```

2. **Create a build directory and run CMake**:
   ```sh
   mkdir build
   cd build
   cmake ..
   ```

3. **Build the project**:
   ```sh
   cmake --build .
   ```

## Running the Project
After building the project, you can run the executable:

1. **Navigate to the build directory** (if not already there):
   ```sh
   cd build
   ```

2. **Run the `cccat` executable**:
   ```sh
   ./cccat
   ```

   This will execute the custom `wc` implementation, showing the count of lines, words, and characters for the input.

## Running Tests
Tests are included to ensure the correctness of the `cccat` implementation. To run the tests:

1. **Navigate to the build directory** (if not already there):
   ```sh
   cd build
   ```

2. **Run `ctest`**:
   ```sh
   ctest
   ```

   This will execute all the test cases and show the test results.

## Contributing
Contributions are welcome! Here's how you can contribute to this project:
- Fork the repository
- Create a new branch (`git checkout -b feature-branch`)
- Make your changes
- Commit your changes (`git commit -am 'Add new feature'`)
- Push to the branch (`git push origin feature-branch`)
- Create a new Pull Request

Please make sure to update tests as appropriate.

## License
This project is licensed under the [MIT License](LICENSE).