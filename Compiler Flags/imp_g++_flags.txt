Compile (F8): g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -O2 -Wno-unused-result
Build (F9): g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
