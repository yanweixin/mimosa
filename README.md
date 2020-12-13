# Documentation
## Dependencies
### Tools
JSON
```bash
git clone --depth=1 https://github.com/DaveGamble/cJSON.git

cd cJSON
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=$HOME/.local
make
make install
```
asynchronous I/O
```bash
git clone --depth=1 git@github.com:libuv/libuv.git

cd libuv
mkdir -p build
(cd build && cmake .. -DCMAKE_INSTALL_PREFIX=$HOME/.local -DBUILD_TESTING=ON) # generate project with tests
cmake --build build -j 4

# Run tests:
(cd build && ctest -C Debug --output-on-failure)
```
### Data
Redis
```bash
git clone --depth=1 https://github.com/redis/hiredis.git
cd hiredis && make PREFIX=$HOME/.local install
```
MongoDB
```bash
git clone --depth=1 https://github.com/mongodb/mongo-c-driver.git
```
RabbitMQ
```bash
git clone --depth=1 git@github.com:alanxz/rabbitmq-c.git
cd rabbitmq-c
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=$HOME/.local ..
cmake --build . --config Release --target install
```