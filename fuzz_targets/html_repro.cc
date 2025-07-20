#include <cstdlib>
#include <cstdint>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  // 고정된 HTML 파일을 크롬으로 실행
  int result = std::system(
    "/usr/bin/google-chrome --headless --disable-gpu "
    "--no-sandbox --js-flags=--expose-gc --virtual-time-budget=4000 "
    "file:///src/html-fuzz/testdata/new_fuzz.html > /dev/null 2>&1"
  );
  return 0;
}

