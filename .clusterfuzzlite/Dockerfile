FROM gcr.io/oss-fuzz-base/base-builder

# Chrome 설치
RUN apt-get update && apt-get install -y wget gnupg ca-certificates
RUN wget -q -O - https://dl.google.com/linux/linux_signing_key.pub | apt-key add -
RUN echo "deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main" > /etc/apt/sources.list.d/google-chrome.list
RUN apt-get update && apt-get install -y google-chrome-stable

# 소스 복사
COPY . $SRC/html-fuzz
WORKDIR $SRC/html-fuzz

# build.sh 실행 (경로 명확히!)
RUN chmod +x .clusterfuzzlite/build.sh && ./.clusterfuzzlite/build.sh

