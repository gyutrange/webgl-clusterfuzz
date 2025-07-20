#include <cstdlib>
#include <fstream>
#include <iostream>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  // 입력을 무시하고 고정된 HTML 파일 실행
  const char *chrome = "/usr/bin/google-chrome";
  const char *html_path = "/src/html-fuzz/testdata/new_fuzz.html";

  std::string command = std::string(chrome) +
    " --headless --disable-gpu --no-sandbox " +
    "--js-flags=--expose-gc --virtual-time-budget=5000 " +
    "file://" + html_path + " > /dev/null 2>&1";

  int result = std::system(command.c_str());

  // Chrome exit code가 0이 아니면 크래시로 간주
  if (result != 0) {
    std::cerr << "[!] Chrome exited with code: " << result << std::endl;
    __builtin_trap();  // Fuzzing engine에 크래시로 보고
  }

  return 0;
}

