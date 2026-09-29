# Study the C

```
my_project/
├── CMakeLists.txt
│
├── include/
│   ├── include.h
│
├── basicIO/
│   ├── CMakeLists.txt
│   └── main.cpp
│
├── typeSize/
│   ├── main.cpp
│   ├── Case1.bin
│   ├── Case2.bin
│   ├── Case3.bin
│   ├── CaseSpecial.bin
│   └── README.md
│
└── build/
```
## build the project
```sh
cmake -S something -B build/something
cmake --build build/something
```
