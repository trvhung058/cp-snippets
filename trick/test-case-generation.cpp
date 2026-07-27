// gen
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long L, long long R) {
    return L + rd() % (R - L + 1);
}

// cp
@echo off

g++ -O2 -DLOCAL -o sol sol.cpp
g++ -O2 -DLOCAL -o brute brute.cpp
g++ -O2 -DLOCAL -o gen gen.cpp

// stress
@echo off

for /l %%i in (1, 1, 500) do (
    gen.exe %%i > input.inp
    
    sol.exe < input.inp > output.out
    brute.exe < input.inp > answer.out
    fc output.out answer.out > 0 || echo TEST %%i: [WA] && type input.inp && goto :out
    echo TEST %%i: [AC]
)

:out