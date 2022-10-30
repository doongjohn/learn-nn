# Learn neural network

## build

```bash
# download dependencies
cd vendor
git clone https://gitlab.com/libeigen/eigen.git
```

```bash
# generate build files
cmake -S . -B build
# build project
cmake --build build
```

## run

```bash
./build/neural_network
```
