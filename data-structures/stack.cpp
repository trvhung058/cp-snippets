for (int i = 1; i <= n; ++i) {
    while (s.size() && A[s.top()] >= A[i]) s.pop();
    L[i] = s.empty() ? 1 : s.top() + 1;
    s.push(i);
}