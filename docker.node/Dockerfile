FROM sungyong/gtest:latest

RUN apt-get update \
  && apt-get install -q -y python-is-python3 pip golang adr-tools tig nodejs node

RUN curl -fsSL https://tailscale.com/install.sh | sh \
  && curl -s https://install.zerotier.com | sh