# BitConverter

A C++ port of the C# BitConverter class. Convert bytes to base data types, and base data types to bytes.

## Installation

Copy the header file `include/bit_converter/bit_converter.hpp` to your project.

## Examples

Convert the 32-bit signed integer `943561` to bytes:

```cpp
vector<uint8_t> bytes(sizeof(int32_t));
int32_t value = 94356;
bit_converter::i32_to_bytes(value, true, bytes.begin());
```

Convert the eight bytes to a double-precision floating-point value.

```cpp
vector<uint8_t> bytes{31, 133, 235, 81, 184, 30, 9, 64};
double_t value = bit_converter::bytes_to_f64(bytes.begin(), false);
cout << "value = " << value << endl;
```

## API
```cpp
/**
 * @brief Convert the specified 16-bit signed integer value to bytes.
 */
template <typename OutputIt>
inline OutputIt i16_to_bytes(int16_t value, bool is_big_endian,
                             OutputIt output_it);

/**
 * @brief Convert the specified 16-bit unsigned integer value to bytes.
 */
template <typename OutputIt>
inline OutputIt u16_to_bytes(uint16_t value, bool is_big_endian,
                             OutputIt output_it);

/**
 * @brief Convert the specified 32-bit signed integer value to bytes.
 */
template <typename OutputIt>
inline OutputIt i32_to_bytes(int32_t value, bool is_big_endian,
                             OutputIt output_it);

/**
 * @brief Convert the specified 32-bit unsigned integer value to bytes.
 */
template <typename OutputIt>
inline OutputIt u32_to_bytes(uint32_t value, bool is_big_endian,
                             OutputIt output_it);

/**
 * @brief Convert the specified 64-bit signed integer value to bytes.
 */
template <typename OutputIt>
inline OutputIt i64_to_bytes(int64_t value, bool is_big_endian,
                             OutputIt output_it);

/**
 * @brief Convert the specified 64-bit unsigned integer value to bytes.
 */
template <typename OutputIt>
inline OutputIt u64_to_bytes(uint64_t value, bool is_big_endian,
                             OutputIt output_it);

/**
 * @brief Convert the specified single-precision floating-point value to bytes.
 */
template <typename OutputIt>
inline OutputIt f32_to_bytes(float_t value, bool is_big_endian,
                             OutputIt output_it);

/**
 * @brief Convert the specified double-precision floating-point value to bytes.
 */
template <typename OutputIt>
inline OutputIt f64_to_bytes(double_t value, bool is_big_endian,
                             OutputIt output_it);

/**
 * @brief Returns a 16-bit signed integer converted from two bytes at a
 * specified position in a byte sequence.
 */
template <typename InputIt>
inline int16_t bytes_to_i16(InputIt input_it, bool is_big_endian);

/**
 * @brief Returns a 16-bit unsigned integer converted from two bytes at a
 * specified position in a byte sequence.
 */
template <typename InputIt>
inline uint16_t bytes_to_u16(InputIt input_it, bool is_big_endian);

/**
 * @brief Returns a 32-bit signed integer converted from four bytes at a
 * specified position in a byte sequence.
 */
template <typename InputIt>
inline int32_t bytes_to_i32(InputIt input_it, bool is_big_endian);

/**
 * @brief Returns a 32-bit unsigned integer converted from four bytes at a
 * specified position in a byte sequence.
 */
template <typename InputIt>
inline uint32_t bytes_to_u32(InputIt input_it, bool is_big_endian);

/**
 * @brief Returns a 64-bit signed integer converted from eight bytes at a
 * specified position in a byte sequence.
 */
template <typename InputIt>
inline int64_t bytes_to_i64(InputIt input_it, bool is_big_endian);

/**
 * @brief Returns a 64-bit unsigned integer converted from eight bytes at a
 * specified position in a byte sequence.
 */
template <typename InputIt>
inline uint64_t bytes_to_u64(InputIt input_it, bool is_big_endian);

/**
 * @brief Returns a single-precision floating-point number converted from four
 * bytes at a specified position in a byte sequence.
 */
template <typename InputIt>
inline float_t bytes_to_f32(InputIt input_it, bool is_big_endian);

/**
 * @brief Returns a double-precision floating-point number converted from eight
 * bytes at a specified position in a byte sequence.
 */
template <typename InputIt>
inline double_t bytes_to_f64(InputIt input_it, bool is_big_endian);
```