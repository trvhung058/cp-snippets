// cp.sh

#!/bin/bash
g++ -std=c++17 -O2 -o sol sol.cpp
g++ -std=c++17 -O2 -o brute brute.cpp
g++ -std=c++17 -O2 -o gen gen.cpp

chmod +x cp.sh

// stress.sh

#!/bin/bash

for ((i = 1; i <= 2000; i++)); do
    ./gen > input.txt
    ./sol < input.txt > out1.txt
    ./brute < input.txt > out2.txt

    if diff -q out1.txt out2.txt > /dev/null; then
        echo "Test $i: [AC]"
    else
        echo "Test $i: [WA]"
        echo "Input:"
        cat input.txt
        echo "Output (sol):"
        cat out1.txt
        echo "Output (brute):"
        cat out2.txt
        exit
    fi
done

echo "All 2000 tests passed! 🎉"

chmod +x stress.sh

// run

./cp.sh
./stress.sh