FROM ubuntu:20.04

ARG BRANCH_OR_TAG=main
ARG CMAKE_OPTIONS=

ENV TZ='Asia/Seoul'
ENV DEBIAN_FRONTEND="noninteractive"

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN  env \
  && apt-get update \
  && apt-get install -q -y git cmake make g++ lcov \
  && apt-get install -q -y zsh curl wget


RUN chsh -s /usr/bin/zsh \
  && curl -L https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh | sh \
  && curl https://raw.githubusercontent.com/seebi/dircolors-solarized/master/dircolors.ansi-dark --output ~/.dircolors

RUN git clone -q https://github.com/abseil/abseil-cpp.git /abseil-cpp
WORKDIR /
RUN cd abseil-cpp \
  && cmake -DBUILD_TESTING=ON -DABSL_USE_GOOGLETEST_HEAD=ON -DCMAKE_CXX_STANDARD=11 \
  && make && make install \
  && cd googletest-build \
  && make && make install 
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/* \
  && mkdir -p /code
WORKDIR /code
# RUN rm -rf /googletest
