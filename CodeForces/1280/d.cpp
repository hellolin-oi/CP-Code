// * HELLOLIN'S CP CODE TEMPLATE v2.5.0
#ifndef ONLINE_JUDGE
#pragma GCC optimize(2, "inline", "unroll-loops", "no-stack-protector", "-ffast-math")
#endif
#define _EXT_CODECVT_SPECIALIZATIONS_H 0
#define _EXT_ENC_FILEBUF_H 0
#include <bits/extc++.h>
#ifdef LOCAL
#include <windows.h>
#include <psapi.h>
#endif

namespace hellolin {
namespace lib {
using ll = long long;
using ull = unsigned long long;
using lll = __int128;
using ulll = __uint128_t;
const static std::string yesno_str[2][3] = {{"no", "No", "NO"}, {"yes", "Yes", "YES"}};
inline std::string yesno(bool x, int y) { return yesno_str[x][y] + '\n'; }
template <class T> inline T fpow(T x, ull y) { T res = 1; for(; y; y >>= 1, x = x * x) if(y & 1) res = res * x; return res; }
template <class T> inline T fpow(T x, ull y, T mod) { T res = 1; for(; y; y >>= 1, x = x * x % mod) if(y & 1) res = res * x % mod; return res; }
template <class T, class U> inline bool chmax(T &x, U y) { return y > x ? (x = y, 1) : 0; }
template <class T, class U> inline bool chmin(T &x, U y) { return y < x ? (x = y, 1) : 0; }
#define rep(l, x, a, b) for (l x = a, x##END = b; x <= x##END; ++x)
#define per(l, x, a, b) for (l x = a, x##END = b; x >= x##END; --x)
#define fi first
#define se second
#define allof(x) x.begin(), x.end()
#define alof(x) x.begin() + 1, x.end()
#define allnof(x, n) x.begin(), x.begin() + n + 1
#define alnof(x, n) x.begin() + 1, x.begin() + n + 2
#define lowbit(x) (x & -x)
#define mp make_pair
#define pb emplace_back
#define nl '\n'
} // namespace lib
using namespace lib;

// * CORE CODE BEGIN * //
constexpr static int N = 3e3+114;
int T, n, m;
int b[N], w[N], u, v;
std::vector<std::vector<int>> g;
int dp[N][N];
ll q[N][N], len[N];
std::pair<int, ll> tr[N];
void solve() {
    auto dfs = [&](auto fun, int x, int fa) -> void {
        len[x] = 1;
        q[x][1] = w[x];
        rep(int, i, 2, n) dp[x][i] = q[x][i] = -1;
        dp[x][1] = 0;
        for(auto y : g[x]) {
            if(y != fa) {
                fun(fun, y, x);
                rep(int, i, 1, std::min((ll)m, len[x] + len[y])) tr[i] = {-1, -1};
                rep(int, i, 1, len[x])
                    rep(int, j, 1, len[y]) {
                        int k = i + j;
                        if(k > m) break;
                        int p = dp[x][i] + dp[y][j], pp = q[x][i] = q[y][j];
                        if(p > tr[k].fi) {
                            tr[k] = {p, pp};
                        } else if(p == tr[k].fi) {
                            chmax(tr[k].se, pp);
                        }
                    }
                rep(int, i, 1, std::min((ll)m, len[x] + len[y])) std::tie(dp[x][i], q[x][i]) = tr[i];
                len[x] += len[y];
            }
        }
        per(int, i, std::min((ll)m, len[x]), 1) {
            ll tp = dp[x][i] + (q[x][i] > 0);
            if(chmax(dp[x][i+1], tp))
                q[x][i+1] = 0;
            else if(dp[x][i+1] == tp && q[x][i+1] < 0)
                q[x][i+1] = 0;
        }
    };
    for(std::cin >> T; T--; ) {
        std::cin >> n >> m;
        g = std::vector<std::vector<int>> (n+1, std::vector<int> ());
        rep(int, i, 1, n) std::cin >> b[i];
        rep(int, i, 1, n) {
            std::cin >> w[i];
            w[i] -= b[i];
        }
        rep(int, i, 1, n-1) {
            std::cin >> u >> v;
            g[u].pb(v), g[v].pb(u);
        }
        dfs(dfs, 1, 0);
        std::cout << dp[1][m] + (q[1][m] > 0) << nl;
    }
}
// * CORE CODE END * //

} // namespace hellolin

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    // freopen(".dbg", "w", stderr);
#ifdef LOCAL
    auto st = std::chrono::high_resolution_clock::now();
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    // std::cout << std::fixed << std::setprecision(6);
    std::cerr << std::fixed << std::setprecision(6);
    hellolin::solve();
#ifdef LOCAL
    auto ed = std::chrono::high_resolution_clock::now();
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    std::cerr << "---------- DEBUG INFO ----------\n";
    std::cerr << "Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(ed - st).count() * 1e-9 << "s.\n";
    std::cerr << "Memory: " << pmc.WorkingSetSize / 1000000 << "MB.\n";
#endif
    return 0;
}