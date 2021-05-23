/*
 * NOTE:
 *
 * This file is meant to only be used with "src/cmm/inlines.cpp", nothing more
 *
 * */

#ifndef CMM__PRIVATE_INLINE_STATE
#define CMM__PRIVATE_INLINE_STATE

#include <string>
#include <sstream>

namespace cmm {

using sz_t = std::string::size_type;

namespace imp {

namespace { // NOLINT

struct inline_state final {
    const std::string &source; // NOLINT
    std::stringstream &result; // NOLINT
    sz_t &             index;  // NOLINT

    // Code spans
    bool in_code_span = false;     // NOLINT
    sz_t number_of_backsticks = 0; // NOLINT

    // Emphasis
    bool in_emphasis = false; // NOLINT

    // Strong emphasis
    bool in_strong_emphasis = false; // NOLINT

    [[nodiscard]] bool is_valid(void) const {
        return index < source.size();
    }

    // Returns the current character
    [[nodiscard]] char current(void) const noexcept {
        return source[index];
    }

    // Returns the next character
    [[nodiscard]] char next(void) const noexcept {
        return source[index + 1];
    }

    [[nodiscard]] bool next_is_in_range(void) const noexcept {
        return (index + 1) < source.size();
    };

    // Writes n characters to the resutl
    void write_n(sz_t n) {
        for (sz_t i = 0; i < n; i++) {
            result << source[index++];
        }
    };

    // Writes str to the result
    void write(const char *const str) {
        result << str;
    }

    void ignore_n(sz_t n) {
        index += n;
    };

    // Counts the times a character is found, from the current position in the
    // source
    [[nodiscard]] sz_t count_ocurrences(char c) const noexcept {
        sz_t count = 0;
        while (source[index + count] == c) {
            ++count;
        }
        return count;
    }
};

} // namespace
} // namespace imp
} // namespace cmm

#endif
