FROM gcr.io/oss-fuzz-base/base-builder

# Chrome 설치
RUN apt-get update && apt-get install -y wget gnupg ca-certificates
RUN wget -q -O - https://dl.google.com/linux/linux_signing_key.pub | apt-key add -
RUN echo "deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main" > /etc/apt/sources.list.d/google-chrome.list
RUN apt-get update && apt-get install -y google-chrome-stable

# 프로젝트 복사
COPY . $SRC/html-fuzz
WORKDIR $SRC/html-fuzz

# 빌드 스크립트 복사 및 실행
RUN chmod +x .clusterfuzzlite/build.sh && .clusterfuzzlite/build.sh

