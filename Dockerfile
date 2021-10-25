FROM ubuntu:20.04

ARG BRANCH_OR_TAG=master
ARG CMAKE_OPTIONS=

ENV TZ='Asia/Seoul'
ENV DEBIAN_FRONTEND="noninteractive"

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN  env \
  && apt-get update \
  && apt-get install -q -y git cmake make g++ lcov \
  && apt-get install -q -y zsh curl wget \
  && apt-get install -q -y gettext-base jq curl \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/*

RUN chsh -s /usr/bin/zsh \
  && curl -L https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh | sh \
  && curl https://raw.githubusercontent.com/seebi/dircolors-solarized/master/dircolors.ansi-dark --output ~/.dircolors
RUN git clone --depth=1 -b $BRANCH_OR_TAG -q https://github.com/google/googletest.git /googletest
RUN mkdir -p /googletest/build
WORKDIR /googletest/build
RUN cmake .. ${CMAKE_OPTIONS} && make && make install
RUN mkdir -p /code
WORKDIR /code
RUN rm -rf /googletest
