#include<bits/stdc++.h>

// USE MIN HEAP

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, temp;
    int ans = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
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