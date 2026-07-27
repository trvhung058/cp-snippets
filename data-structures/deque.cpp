for (int i = 1; i <= n; ++i) {
    while (dq.size() && A[dq.back()] >= A[i]) dq.pop_back();
    dq.push_back(i);
    if (dq.front() + k <= i) dq.pop_front();
    if (i >= k) minRange[i] = A[dq.front()];
}