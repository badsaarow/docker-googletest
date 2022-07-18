FROM ubuntu:22.04

ARG BRANCH_OR_TAG=main
ARG CMAKE_OPTIONS=

ENV TZ='Asia/Seoul'
ENV DEBIAN_FRONTEND="noninteractive"

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN  env \
  && apt-get update \
  && apt-get install -q -y git cmake make g++ lcov \
  && apt-get install -q -y zsh curl wget vim nano btop htop \
  && apt-get install -q -y ca-certificates curl gnupg lsb-release

RUN mkdir -p /etc/apt/keyrings \
  && curl -fsSL https://download.docker.com/linux/ubuntu/gpg | gpg --dearmor -o /etc/apt/keyrings/docker.gpg \
  && echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" | tee /etc/apt/sources.list.d/docker.list > /dev/null

RUN apt-get update \
  && apt-get install -q -y docker-ce docker-ce-cli containerd.io docker-compose-plugin

RUN chsh -s /usr/bin/zsh \
  && curl -L https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh | sh \
  && curl https://raw.githubusercontent.com/seebi/dircolors-solarized/master/dircolors.ansi-dark --output ~/.dircolors

RUN git clone -q https://github.com/abseil/abseil-cpp.git /abseil-cpp \
  && git clone -q https://github.com/google/googletest.git /googletest
  
WORKDIR /
RUN cd abseil-cpp \
  && cmake -DBUILD_TESTING=ON -DABSL_USE_GOOGLETEST_HEAD=ON -DCMAKE_CXX_STANDARD=14 \
  && make \
  && make install \
  && cd /googletest \
  && cmake . \
  && make \
  && make install \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/* \
  && mkdir -p /code
WORKDIR /code
# RUN rm -rf /googletest
