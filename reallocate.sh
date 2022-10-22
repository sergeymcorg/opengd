audio=(BackOnTrack BaseAfterBase CantLetGo DryOut Jumper menuLoop Polargeist StayInsideMe StereoMadness)
bg=(game_bg_01_001)
effects=(chargeEffect dragEffect endEffectPortal explodeEffect firework glitterEffect glitterEffectIcon landEffect lvlupEffect portalEffect01 portalEffect02 portalEffect03 portalEffect04 ringEffect shipDragEffect speedEffect starEffect starEffect01 trailEffect bumpEffect)
fonts=(arial.ttf bigFont.fnt bigFont.png bigFont-hd.fnt bigFont-hd.png chatFont.fnt chatFont.png chatFont-hd.fnt chatFont-hd.png fps_images.png fps_images-hd.png fps_images-ipadhd.png goldFont.fnt goldFont.png goldFont-hd.fnt goldFont-hd.png)
grounds=(groundSquare_001)
other=(AchievementsDesc.plist levelComplete01.plist objectDefinitions.plist promo_boom.png promo_boom-hd.png promo_mm.png promo_mm-hd.png promo_mu.png promo_mu-hd.png Skull_w_01.plist Skull_w_02.plist Skull_w_03.plist starFall.plist stoneHit.plist)
res=()
sfx=(achievement_01 endStart_02 explode_11  playSound_01 quitSound_01)
sprites=(floor floor-hd GJ_gradientBG GJ_gradientBG-hd gk-icon gk-icon-hd gravityOverlay gravityOverlay-hd streak streakDWhite sun)
spriteSheets=(CCControlColourPickerSpriteSheet GJ_GameSheet GJ_LaunchSheet)
ui=(smallDot square01_001-hd sliderthumbsel-hd square02_001 loadingCircle-hd GJ_moveSBtn slidergroove edit_barBG_001 GJ_square01-hd square02_small-hd square02_small GJ_button_04 sliderthumb-hd GJ_button_03-hd sliderthumbsel loadingCircle GJ_button_02 square sliderBar smallDot-hd GJ_button_01-hd square04_001-hd GJ_progressBar_001-hd sliderBar-hd slidergroove_02 GJ_button_01 square03_001-hd slidergroove_02-hd GJ_moveSBtn-hd GJ_button_03 square01_001 square02_001-hd GJ_progressBar_001 GJ_square01 sliderthumb square02b_001 GJ_moveBtn-hd GJ_button_04-hd GJ_moveBtn slidergroove-hd edit_barBG_001-hd square03_001 square04_001 GJ_button_02-hd square02b_001-hd)

ProcessFolderStructure() {
    mkdir -p audio
    mkdir -p bg
    mkdir -p effects
    mkdir -p fonts
    mkdir -p grounds
    mkdir -p other
    mkdir -p res
    mkdir -p sfx
    mkdir -p sprites
    mkdir -p spriteSheets
    mkdir -p ui
}

ProcessAudio() {
    for file in ${audio[*]}
    do
        mv ${file}.mp3 audio/ 
    done
}
ProcessBG() {
    for file in ${bg[*]}
    do
        mv ${file}.png bg/ 
        mv ${file}-hd.png bg/ 
    done
}
ProcessEffects() {
    for file in ${effects[*]}
    do
        mv ${file}.plist effects/ 
    done
}
ProcessFonts() {
    for file in ${fonts[*]}
    do
        mv ${file} fonts/ 
    done
}
ProcessGrounds() {
    for file in ${grounds[*]}
    do
        mv ${file}.png grounds/ 
        mv ${file}-hd.png grounds/ 
    done
}
ProcessOther() {
    for file in ${other[*]}
    do
        mv ${file} other/ 
    done
}
ProcessRes() {
    for file in ${res[*]}
    do
        mv ${file} res/ 
    done
}
ProcessSfx() {
    for file in ${sfx[*]}
    do
        mv ${file}.ogg sfx/ 
    done
}
ProcessSprites() {
    for file in ${sprites[*]}
    do
        mv ${file}.png sprites/ 
    done
}
ProcessSpriteSheets() {
    for file in ${spriteSheets[*]}
    do
        mv ${file}.png spriteSheets/ 
        mv ${file}.plist spriteSheets/ 
        mv ${file}-hd.png spriteSheets/ 
        mv ${file}-hd.plist spriteSheets/ 
    done
}
ProcessUi() {
    for file in ${ui[*]}
    do
        mv ${file}.png ui/ 
    done
}

ProcessFolderStructure

ProcessAudio &
ProcessBG &
ProcessEffects &
ProcessFonts &
ProcessGrounds &
ProcessOther &
ProcessRes &
ProcessSfx &
ProcessSprites &
ProcessSpriteSheets &
ProcessUi


