#!/bin/bash

qmk json2c ../keymaps/corne.json -o corne_keymap_json.c
pcpp -D QMK_KEYBOARD_H="" -D KEYMAP_DISPLAY ../layout.h ../features/combos.h ./corne_keymap_json.c > corne_keymap.c
qmk c2json -kb "$(jq -r '.keyboard' ../keymaps/corne.json)" -km default corne_keymap.c > corne_keymap.json
keymap parse -l BSE CMK NUM SYM FNC -q corne_keymap.json > corne_keymap.yaml
# The json file generated from qmk c2json doesn't support combos, 
# so we need to manually add combos and customize the output yaml at this step
keymap draw corne_keymap.yaml > corne_keymap.svg
