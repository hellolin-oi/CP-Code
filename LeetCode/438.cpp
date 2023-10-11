/*
 * |-| [- |_ |_ () |_ | |\| 's LeetCode Template v1.3.1
 * Recommended standard: C++20.
 * In general, this source code can be found archived here:
 *     https://github.com/hellolin-oi/CP-Code/tree/main/LeetCode
 */
#ifndef ONLINE_JUDGE
#pragma GCC optimize(2, "inline", "unroll-loops", "no-stack-protector", "fast-math")
#endif
#include <bits/stdc++.h>
#include <emmintrin.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <immintrin.h>
// #include "atcoder/all"
#if defined(_WIN64) || defined(__x86_64__) || __WORDSIZE == 64
#define ARCH64
#endif

namespace hellolin {
using namespace std;
#define pq __gnu_pbds::priority_queue
using i8 = signed char;
using u8 = unsigned char;
using i16 = short;
using u16 = unsigned short;
using i64 = long long;
using u64 = unsigned long long;
#ifdef ARCH64
using i128 = __int128_t;
using u128 = __uint128_t;
#else
#warning The int128 type has been fallbacked to int64.
using i128 = i64;
using u128 = u64;
#endif
using ld = long double;
#define rdecltype(x) std::decay_t<decltype(x)>
#define _rep1(x) for (rdecltype(x) i = 1, i##end = x; i <= i##end; ++i)
#define _rep2(i, x) for (rdecltype(x) i = 1, i##end = x; i <= i##end; ++i)
#define _rep3(i, x, y) for (auto i = x, i##end = y; i <= i##end; ++i)
#define _rep4(i, x, y, z) for (auto i = x, i##end = y; i <= i##end; i += (z))
#define _per1(x) for (rdecltype(x) i = x, i##end = 1; i >= i##end; --i)
#define _per2(i, x) for (rdecltype(x) i = x, i##end = 1; i >= i##end; --i)
#define _per3(i, x, y) for (auto i = x, i##end = y; i >= i##end; --i)
#define _per4(i, x, y, z) for (auto i = x, i##end = y; i >= i##end; i -= (z))
#define ovld(_1, _2, _3, _4, x, ...) x
#define rep(...) ovld(__VA_ARGS__, _rep4, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define per(...) ovld(__VA_ARGS__, _per4, _per3, _per2, _per1)(__VA_ARGS__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define fi first
#define se second
#define ps emplace
#define pb emplace_back
constexpr char newl = '\n';
template <class T1, class T2>
inline bool chmax(T1 &x, T2 y) { return x < y ? x = y, 1 : 0; }
template <class T1, class T2>
inline bool chmin(T1 &x, T2 y) { return x > y ? x = y, 1 : 0; }

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (m > n) return vector<int>{};
        // unordered_map<char, int> buc1, buc2;
        vector<int> buc1(200), buc2(200);
        vector<int> res;
        rep(i, 0, m - 1) {
            ++buc1[s[i]];
            ++buc2[p[i]];
        }
        if (buc1 == buc2) res.pb(0);
        rep(i, 0, n - m - 1) {
            --buc1[s[i]];
            ++buc1[s[i + m]];

            if (buc1 == buc2) res.pb(i + 1);
        }
        return res;
    }
};

} // namespace hellolin

using namespace hellolin;