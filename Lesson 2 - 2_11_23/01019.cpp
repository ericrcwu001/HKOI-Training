#include<bits/stdc++.h>
using namespace std;

// USE MIN HEAP

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long int n, temp;
    long long int ans = 0;
    cin >> n;
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        pq.push(temp);
    }

    while (!(pq.size() == 1)) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b);
        ans += a + b;
    }

    cout << ans << endl;
}