FROM gcr.io/oss-fuzz-base/base-builder

# (선택적) chrome 설치 등 네이티브 의존성
RUN apt-get update && apt-get install -y wget gnupg ca-certificates
RUN wget -q -O - https://dl.google.com/linux/linux_signing_key.pub | apt-key add -
RUN echo "deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main" > /etc/apt/sources.list.d/google.list
RUN apt-get update && apt-get install -y google-chrome-stable

# 소스 복사
COPY . /src
WORKDIR /src

