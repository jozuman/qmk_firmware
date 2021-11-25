https://docs.qmk.fm/#/newbs_building_firmware

# Build & Install
- open QMK MSYS and run `qmk compile`
- open QMK Toolbox and flash `C:\Users\timgr\git\qmk_firmware\planck_rev6_jozuman.bin`.
  - keyboard needs to be in bootloader mode via Raise+Lower+Q

# Getting latest code from upstream
- use `mystuff` branch for all my commits
- `git pull` in order to not miss anything I may have done anywhere else (especially because it will be completely lost with a -f)
- `git fetch upstream`
- `git rebase upstream/master`
- `git push -f`
- If master does not have a green checkmark on the latest commit https://github.com/qmk/qmk_firmware or if you just want to ensure a little more stability, use the latest release tag in git.
  - `git checkout [tag-number]`
  - `git switch -c [tag-number]-branch`
  - TODO next steps... I've done cherry-pick so far but what to do when lots of commits in the future.

# Initial setup (more recently switched to rev6_drop instead of just rev6)
- `qmk config user.keyboard=planck/rev6_drop`
- `qmk config user.keymap=jozuman`
