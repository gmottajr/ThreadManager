# ThreadManager Class :gear:

## Overview :book:
The `ThreadManager` class, coded in C++, is designed to streamline and optimize thread management across different computing environments with varying hardware capabilities. Its primary function is to determine the optimal number of threads to utilize for a given task, based on the computing resources available, particularly the number of CPU cores.

### Key Features and Problem Solving :bulb:
1. **Adaptability to Different Systems** :computer:
   - Addresses the challenge of running the same application efficiently on systems with different numbers of CPU cores.

2. **Dynamic Thread Allocation** :arrows_clockwise:
   - Dynamically adjusts the number of threads based on the system's capabilities.

3. **Predefined Thread Management Options** :pushpin:
   - Offers predefined options (`All`, `Half`, `Specific`) for simplicity and flexibility.

4. **Handling Invalid Inputs** :no_entry_sign:
   - Robustly handles invalid inputs by defaulting to a safe configuration.

5. **C++ Implementation** :hammer_and_wrench:
   - Efficiently integrated into C++ applications, leveraging the language's performance and system-level capabilities.

6. **Use of Google Test for Robust Testing** :test_tube:
   - Employs Google Test, a widely-used C++ testing framework, to ensure robust and reliable software through comprehensive testing.

7. **Use Cases** :rocket:
   - Ideal for scalable applications across various hardware setups, like distributed systems and cloud-based applications.

8. **Developer-Friendly** :handshake:
   - Simplifies the development process by abstracting thread management complexities.

### Conclusion :checkered_flag:
The `ThreadManager` class is a C++ solution for optimizing multi-threaded applications to run efficiently on diverse hardware. It leads to improved performance, better resource management, and scalable software.

### Advantages in Cohesion, Maintainability, and Scalability :dart:

The design and implementation of the `ThreadManager` class focus on promoting high cohesion, easy maintainability, and excellent scalability. By encapsulating thread management logic within a single, well-defined class, we achieve a high level of cohesion, ensuring that each part of the class is directly related to thread management. This focused approach simplifies understanding and debugging the code, thereby enhancing maintainability. The class's adaptability to different system capabilities, facilitated by clear and manageable options (`All`, `Half`, `Specific`), makes it highly scalable. It seamlessly accommodates a wide range of hardware configurations, from high-performance servers with numerous cores to consumer-grade laptops with fewer cores. Consequently, applications using `ThreadManager` can easily scale up or down based on the available hardware, without requiring significant code changes. This scalability is crucial in today's diverse computing environments, where applications must perform optimally across a spectrum of hardware specifications.

---

## How to Use :wrench:
*Include instructions on how to integrate and use the `ThreadManager` class in a C++ project.*
Integrating and using the `ThreadManager` class in your C++ project is straightforward. Follow these steps to get started:

1. **Include the ThreadManager Class**:
   - Ensure that the `ThreadManager.h` file is included in your project's directory structure, preferably in an `include` or `headers` directory.

2. **Add the ThreadManager to Your Project**:
   - Include the `ThreadManager` header in your source file:
     ```cpp
     #include "ThreadManager.h"
     ```

3. **Instantiate the ThreadManager**:
   - Create an instance of `ThreadManager` using one of the predefined options (`All`, `Half`, `Specific`). For the `Specific` option, also provide the desired number of threads:
     ```cpp
     ThreadManager tmAll(ThreadOption::All);
     ThreadManager tmHalf(ThreadOption::Half);
     ThreadManager tmSpecific(ThreadOption::Specific, 4); // Specify 4 threads
     ```

4. **Use the Optimal Thread Count**:
   - Use the `getOptimalThreadCount()` method to obtain the optimal number of threads for your application:
     ```cpp
     unsigned int optimalThreads = tmAll.getOptimalThreadCount();
     ```

5. **Implement Your Multithreaded Logic**:
   - Utilize the optimal thread count in your application's threading logic, ensuring efficient use of system resources.

6. **Compile and Run**:
   - Compile your project with the `ThreadManager` class included. Ensure your compiler and build system are configured to include the directory where `ThreadManager.h` is located.

By following these steps, you can easily integrate the `ThreadManager` into your C++ projects, enabling efficient and dynamic thread management tailored to the hardware capabilities of the executing system.

---

## Contributing :raising_hand:
We welcome contributions from developers of all skill levels. If you're interested in helping improve the `ThreadManager` project, here's how you can get started:

1. **Fork the Repository**:
   - Start by forking the project repository to your own GitHub account.

2. **Clone Your Fork**:
   - Clone the forked repository to your local machine to start working on the changes.

3. **Set Up Your Development Environment**:
   - Ensure you have the necessary tools installed, including a C++ compiler and any dependencies specified in the project.

4. **Create a New Branch**:
   - Create a new branch in your forked repository for each separate piece of work.

5. **Make Your Changes**:
   - Implement your changes, enhancements, or bug fixes in your branch.
   - Make sure to follow the existing coding style and conventions.
   - Update or add new tests as needed to cover your changes.

6. **Test Your Changes**:
   - Build the project and run all tests to ensure your changes haven't introduced any regressions.
   - Create unit tests in order to assert all changes that you may perform and make sure they all pass.

7. **Document Your Changes**:
   - Update the README or other documentation if necessary, especially if adding new features or changing how the project is used.

8. **Submit a Pull Request**:
   - Once your changes are ready and tested, submit a pull request to the main repository.
   - Provide a clear description of the changes and any relevant issue numbers.

9. **Code Review**:
   - Respond to any feedback or suggestions provided during the code review process.

10. **Stay Open to Feedback**:
    - Be open to and respectful of feedback and suggestions from other project contributors.

By following these guidelines, you can contribute effectively to the `ThreadManager` project and help make it better for everyone. We look forward to your contributions!


---
