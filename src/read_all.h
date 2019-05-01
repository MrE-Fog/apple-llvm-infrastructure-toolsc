// read_all.h
#pragma once

#include <cstdlib>
#include <vector>

static int read_all(int fd, std::vector<char> &bytes) {
  assert(bytes.empty());
  const ssize_t chunk_size = 1 << 14;
  ssize_t num_bytes_read;
  do {
    ssize_t num_bytes = bytes.size();
    bytes.resize(bytes.size() + chunk_size);
    num_bytes_read = read(fd, bytes.data() + num_bytes, chunk_size);
    if (num_bytes_read == -1)
      return 1;
    bytes.resize(num_bytes + num_bytes_read);
  } while (num_bytes_read);
  return 0;
}