#!/bin/bash

if [ -z "$TOKEN" ]; then
    echo "Error: TOKEN environment variable is not set"
    exit 1
fi

if [ -z "$CHAT_ID" ]; then
    echo "Error: CHAT_ID environment variable is not set"
    exit 1
fi

if [ -z "$TOPIC_ID" ]; then
    echo "Error: TOPIC_ID environment variable is not set"
    exit 1
fi

echo "$TOKEN" > /root/token.tg
echo "$CHAT_ID" > /root/chat_id.tg
echo "$TOPIC_ID" > /root/topic_id.tg
