#include <cstdlib>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  // HTML을 정적으로 불러서 실행 (테스트용)
  int result = std::system(
    "/usr/bin/google-chrome --headless --disable-gpu "
    "--no-sandbox --js-flags=--expose-gc --virtual-time-budget=4000 "
    "file://$PWD/testdata/new_fuzz.html > /dev/null 2>&1"
  );

  return 0;
}

