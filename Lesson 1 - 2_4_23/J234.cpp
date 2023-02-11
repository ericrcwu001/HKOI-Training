#include <bits/stdc++.h>
const double PI = acos(-1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
}

// In-test Code:
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//
//     long long n, q, temp;
//     cin >> n >> q;
//     vector<long long> speeds(n);
//     double prev = 0;
//     for (auto &x : speeds)
//     {
//         cin >> x;
//     }
//     for (int i = 0; i < q; ++i)
//     {
//         cin >> temp;
//         double x = 0, y = 0;
//         long long idx = 1;
//         double tRotationsPsum[n + 1]; // prefix sum init
//         tRotationsPsum[0] = 0;
//         for (auto &b : speeds)
//         { // speed --> need to divide by 10
//             tRotationsPsum[idx] = (b * temp) / 10.0 + tRotationsPsum[idx - 1];
//             x += sin(PI * tRotationsPsum[idx] / 180);
//             y += cos(PI * tRotationsPsum[idx] / 180);
//             idx++;
//         }
//
//         if (x < 0.000001 && x > -0.000001)
//             x = 0;
//         if (y < 0.000001 && y > -0.000001)
//             y = 0;
//
//         cout << x << " " << y << "\n";
//     }
//     return 0;
// }
