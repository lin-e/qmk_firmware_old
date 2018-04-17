#!/bin/bash
cd ~/usr/dev/kb/qmk_firmware/
git remote set-url origin git@github.com:lin-e/qmk_firmware.git
git add -A
git commit -am "Commit by script from laptop"
git push
