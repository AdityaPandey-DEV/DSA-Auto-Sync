# Bit Manipulation

## Introduction

Bit manipulation involves direct manipulation of bits at the binary level. It's essential for competitive programming and system-level programming.

**Key Operators:**
- **AND (&):** 1 if both bits are 1
- **OR (|):** 1 if either bit is 1
- **XOR (^):** 1 if bits are different
- **NOT (~):** Flips all bits
- **Left Shift (<<):** Multiply by 2
- **Right Shift (>>):** Divide by 2

**When to Use:**
- Efficient arithmetic operations
- Set operations
- Optimizations in algorithms
- Bitmasking for subsets/combinations
- Power of 2 checks
- Counting set bits

**Time Complexity:** Usually O(1) or O(n) where n is number of bits

---

## Basic Bit Operations

### C++ Bit Operations
```cpp
#include <bits/stdc++.h>
using namespace std;

// Basic operations
int a = 5;    // 101 in binary
int b = 3;    // 011 in binary

int andResult = a & b;   // 001 (1)
int orResult = a | b;    // 111 (7)
int xorResult = a ^ b;   // 110 (6)
int notResult = ~a;      // ...11111010 (two's complement)
int leftShift = a << 1;  // 1010 (10) - multiply by 2
int rightShift = a >> 1; // 10 (2) - divide by 2
```

### Python Bit Operations
```python
a = 5  # 0b101
b = 3  # 0b011

and_result = a & b    # 0b001 (1)
or_result = a | b     # 0b111 (7)
xor_result = a ^ b    # 0b110 (6)
not_result = ~a       # Negative number (two's complement)
left_shift = a << 1   # 0b1010 (10)
right_shift = a >> 1  # 0b10 (2)
```

---

## Common Bit Tricks

### Check if Number is Power of 2

#### C++ Implementation
```cpp
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

**Explanation:** Power of 2 has only one set bit. `n & (n - 1)` clears the rightmost set bit, so for power of 2, result is 0.

#### Python Implementation
```python
def is_power_of_two(n):
    return n > 0 and (n & (n - 1)) == 0
```

### Get Rightmost Set Bit

#### C++ Implementation
```cpp
int getRightmostSetBit(int n) {
    return n & (-n);  // Isolates rightmost set bit
}
```

**Explanation:** `-n` is two's complement, which flips bits and adds 1. `n & (-n)` isolates the rightmost set bit.

### Count Set Bits (Population Count)

#### C++ Implementation (Brian Kernighan's Algorithm)
```cpp
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // Clear rightmost set bit
        count++;
    }
    return count;
}

// Using built-in
int countSetBitsBuiltin(int n) {
    return __builtin_popcount(n);  // GCC builtin
    // return __builtin_popcountll(n);  // For long long
}
```

#### Python Implementation
```python
def count_set_bits(n):
    count = 0
    while n:
        n &= (n - 1)  # Clear rightmost set bit
        count += 1
    return count

# Using built-in
def count_set_bits_builtin(n):
    return bin(n).count('1')
```

### Clear Rightmost Set Bit

#### C++ Implementation
```cpp
int clearRightmostSetBit(int n) {
    return n & (n - 1);
}
```

### Toggle nth Bit

#### C++ Implementation
```cpp
int toggleBit(int n, int pos) {
    return n ^ (1 << pos);
}
```

### Set nth Bit

#### C++ Implementation
```cpp
int setBit(int n, int pos) {
    return n | (1 << pos);
}
```

### Clear nth Bit

#### C++ Implementation
```cpp
int clearBit(int n, int pos) {
    return n & ~(1 << pos);
}
```

### Check if nth Bit is Set

#### C++ Implementation
```cpp
bool isBitSet(int n, int pos) {
    return (n >> pos) & 1;
    // Alternative: return (n & (1 << pos)) != 0;
}
```

---

## XOR Tricks

### Find Single Number (All Others Appear Twice)

#### C++ Implementation
```cpp
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}
```

**Explanation:** XOR of same numbers is 0, XOR with 0 is the number itself.

### Swap Without Temporary Variable

#### C++ Implementation
```cpp
void swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;  // b = (a^b)^b = a
    a = a ^ b;  // a = (a^b)^a = b
}
```

### Find Two Single Numbers (All Others Appear Twice)

#### C++ Implementation
```cpp
vector<int> singleNumber3(vector<int>& nums) {
    int xorAll = 0;
    for (int num : nums) {
        xorAll ^= num;
    }
    
    // Find rightmost set bit (difference between two numbers)
    int rightmostSetBit = xorAll & (-xorAll);
    
    int num1 = 0, num2 = 0;
    for (int num : nums) {
        if (num & rightmostSetBit) {
            num1 ^= num;
        } else {
            num2 ^= num;
        }
    }
    
    return {num1, num2};
}
```

---

## Bitmasking

### Generate All Subsets Using Bitmasking

#### C++ Implementation
```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> result;
    
    // Each number from 0 to 2^n - 1 represents a subset
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        result.push_back(subset);
    }
    
    return result;
}
```

### Count Subsets with Sum K (DP with Bitmasking)

#### C++ Implementation
```cpp
int countSubsets(vector<int>& nums, int target) {
    int n = nums.size();
    int count = 0;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += nums[i];
            }
        }
        if (sum == target) {
            count++;
        }
    }
    
    return count;
}
```

---

## Advanced Bit Manipulation

### Reverse Bits

#### C++ Implementation
```cpp
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}
```

### Number of 1 Bits

#### C++ Implementation
```cpp
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}
```

### Power of Four

#### C++ Implementation
```cpp
bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
}
```

**Explanation:** Power of 4 must be power of 2 AND bit must be at even position (0xAAAAAAAA has bits at odd positions).

### Maximum XOR of Two Numbers in Array

#### C++ Implementation (Trie-based)
```cpp
class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = children[1] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    
    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            
            if (node->children[oppositeBit] != nullptr) {
                maxXOR |= (1 << i);
                node = node->children[oppositeBit];
            } else {
                node = node->children[bit];
            }
        }
        
        return maxXOR;
    }
};

int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    int maxXOR = 0;
    
    for (int num : nums) {
        trie.insert(num);
        maxXOR = max(maxXOR, trie.findMaxXOR(num));
    }
    
    return maxXOR;
}
```

---

## Bitwise Operations for Optimization

### Fast Multiplication/Division by Powers of 2

#### C++ Implementation
```cpp
int multiplyByPowerOf2(int n, int power) {
    return n << power;  // n * 2^power
}

int divideByPowerOf2(int n, int power) {
    return n >> power;  // n / 2^power
}
```

### Check if Two Numbers Have Opposite Signs

#### C++ Implementation
```cpp
bool oppositeSigns(int a, int b) {
    return ((a ^ b) < 0);
}
```

### Absolute Value Without Branching

#### C++ Implementation (for 32-bit integers)
```cpp
int abs(int n) {
    int mask = n >> 31;  // All 1s if negative, all 0s if positive
    return (n ^ mask) - mask;
}
```

---

## Complexity Analysis

### Time Complexity
- **Basic operations:** O(1)
- **Count set bits:** O(number of set bits)
- **Subset generation:** O(n × 2^n) where n is number of elements
- **Bit reversal:** O(number of bits)

### Space Complexity
- **Most operations:** O(1)
- **Subset generation:** O(2^n) for storing results
- **Trie-based XOR:** O(n × 32) for trie

---

## Quick Reference

### Common Bit Operations
- **Set bit at position i:** `n | (1 << i)`
- **Clear bit at position i:** `n & ~(1 << i)`
- **Toggle bit at position i:** `n ^ (1 << i)`
- **Check bit at position i:** `(n >> i) & 1`
- **Clear rightmost set bit:** `n & (n - 1)`
- **Get rightmost set bit:** `n & (-n)`
- **Power of 2 check:** `n > 0 && (n & (n - 1)) == 0`

### XOR Properties
- `a ^ 0 = a`
- `a ^ a = 0`
- `a ^ b = b ^ a` (commutative)
- `(a ^ b) ^ c = a ^ (b ^ c)` (associative)

### Useful Bit Masks
- **All bits set:** `-1` or `~0`
- **Even positions:** `0xAAAAAAAA`
- **Odd positions:** `0x55555555`
- **Last 4 bits:** `0xF` or `(1 << 4) - 1`

---

## Practice Problems

### Easy
- Number of 1 Bits
- Power of Two
- Missing Number (using XOR)
- Reverse Bits

### Medium
- Single Number
- Single Number II
- Single Number III
- Maximum XOR of Two Numbers
- Counting Bits
- Total Hamming Distance

### Hard
- Maximum XOR of Two Numbers in Array
- Maximum Product of Word Lengths
- Number of Valid Words for Each Puzzle

---

## External Resources

- [GeeksforGeeks Bit Manipulation](https://www.geeksforgeeks.org/bits-manipulation-important-tactics/)
- [LeetCode Bit Manipulation Explore](https://leetcode.com/tag/bit-manipulation/)
- [CP Algorithms Bit Tricks](https://cp-algorithms.com/algebra/bit-manipulation.html)

---

_Last updated: January 2026_

