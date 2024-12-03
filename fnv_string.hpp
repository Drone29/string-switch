
#ifndef FNV_STRING
#define FNV_STRING

#include <cstddef>

// BUF_LEN - max string size
template<size_t BUF_LEN = 16>
class FNVString {
    static const size_t offset_basis = sizeof(size_t) > 4 
        ? /*64-bit*/ 0xcbf29ce484222325 
        : /*32-bit*/ 0x811c9dc5;
    static const size_t fnv_prime = sizeof(size_t) > 4
        ? /*64-bit*/ 0x00000100000001B3
        : /*32-bit*/ 0x01000193;

    size_t m_hash = offset_basis;
    char m_string_buf[BUF_LEN] = {0};

public:
    FNVString() = delete;
    constexpr FNVString(const char *rhs){
        size_t idx = 0;
        while (rhs && *rhs) {
            if(idx < BUF_LEN - 1)
                m_string_buf[idx++] = *rhs;
            m_hash ^= (unsigned char)*rhs++;
            m_hash *= fnv_prime;
        }
    }
    constexpr size_t get_hash() const {
        return m_hash;
    }
    constexpr const char *get_str() const {
        return m_string_buf;
    }
    constexpr operator size_t() const {
        return m_hash;
    }     
};

#endif