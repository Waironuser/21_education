FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    curl \
    gcc \
    make \
    clang-format \
    check \
    lcov \
    zip \
    gnupg \
    locales \
    && rm -rf /var/lib/apt/lists/* \
    && localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8
ENV LANG=en_US.utf8

RUN curl -L "https://packages.gitlab.com/install/repositories/runner/gitlab-runner/script.deb.sh" | bash && \
    apt-get install -y gitlab-runner \
    && apt-get clean

COPY register-and-run.sh tg_data.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/register-and-run.sh /usr/local/bin/tg_data.sh

ENTRYPOINT ["/usr/local/bin/register-and-run.sh"]
