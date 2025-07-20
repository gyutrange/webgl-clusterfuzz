FROM gcr.io/oss-fuzz-base/base-builder

# Chrome 설치
RUN apt-get update && apt-get install -y wget gnupg ca-certificates
RUN wget -q -O - https://dl.google.com/linux/linux_signing_key.pub | apt-key add -
RUN echo "deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main" > /etc/apt/sources.list.d/google-chrome.list
RUN apt-get update && apt-get install -y google-chrome-stable

# 소스 코드 복사
COPY . /src/html-fuzz
WORKDIR /src/html-fuzz

# 빌드 스크립트 실행
RUN chmod +x .clusterfuzzlite/build.sh && .clusterfuzzlite/build.sh

