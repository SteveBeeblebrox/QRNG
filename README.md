# QRNG
An Arduino Quantum Random Number Generator
# Output
The example script continuously prints out random 0/1 bits to the serial monitor obtained from the `Quantum::rand_bit()` function.

Example:
```c
10101001010100010011100011110101...
```

By adapting the call to be `Quantum::rand<T>()` where `T` is a C++ integral type (e.g. `int`, `long`, `unsigned int`, etc...) or a `bool`, values of type `T` made up of random bits may also be obtained. Note that this method works for obtaining random `char`'s; however, they can take any ASCII value and are not guaranteed to be printable characters. To generate random strings, it is advised to take a series of random integers scaled to the indices of a `const char*` containing acceptable characters and use the values at those scaled integers to select resulting values.
