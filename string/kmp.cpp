int k = 0;
for (int i = 2; i <= n; ++i) {
    while (k > 0 && s[i] != s[k + 1]) k = kmp[k];
    kmp[i] = s[i] == s[k + 1] ? ++k : 0;
}   