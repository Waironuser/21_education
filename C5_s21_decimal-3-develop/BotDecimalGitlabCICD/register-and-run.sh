#!/bin/bash

/usr/local/bin/tg_data.sh

gitlab-runner register \
    --non-interactive \
    --url "${GITLAB_URL}" \
    --registration-token "${REGISTRATION_TOKEN}" \
    --description "docker-runner" \
    --tag-list "linux" \
    --executor "shell"

gitlab-runner run
