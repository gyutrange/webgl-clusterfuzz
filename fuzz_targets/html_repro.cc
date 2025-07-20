#include <cstdlib>
#include <cstdint>
#include <cstddef>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  // 크래시 유도용 WebGL HTML 호출
  std::system(
    "/usr/bin/google-chrome --headless --disable-gpu --no-sandbox "
    "--js-flags=--expose-gc --virtual-time-budget=4000 "
    "file:///src/html-fuzz/testdata/new_fuzz.html > /dev/null 2>&1"
  );

  return 0;
}

