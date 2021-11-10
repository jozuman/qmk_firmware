https://docs.qmk.fm/#/newbs_building_firmware

# Build & Install
- open QMK MSYS and run `qmk compile`
- open QMK Toolbox and flash `C:\Users\timgr\git\qmk_firmware\planck_rev6_jozuman.bin`.
  - keyboard needs to be in bootloader mode via Raise+Lower+Q

# Getting latest code from upstream
- `git pull upstream master`
- If master does not have a green checkmark on the latest commit https://github.com/qmk/qmk_firmware or if you just want to ensure a little more stability, use the latest release tag in git.
  - `git checkout [tag-number]`
  - `git switch -c [tag-number]-branch`
  - `git merge origin/master`
    - actually I don't think this last line would work because it'd pull in all the stuff from master which would be the latest stuff. need to rethink this for next time! probably using rebase https://medium.com/@topspinj/how-to-git-rebase-into-a-forked-repo-c9f05e821c8a

# Initial setup (more recently switched to rev6_drop instead of just rev6)
- `qmk config user.keyboard=planck/rev6_drop`
- `qmk config user.keymap=jozuman`
