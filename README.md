# **OpenGD**
A reconstrunction of Geometry Dash using decompiled android versions with our edits so the code will look a lot better.</br>
**We are using cocos2dx 4.0.**<br>
We are first going to remake 1.0 and then move on to later versions.<br>
The whole project is entirely open source **except game assets.**<br>
<br>
For now it is under development.

## **Project members:**
* **[Jaan](https://github.com/JaanDev)#2897**
* **[dogotrigger](https://github.com/SergeyMC9730)#0355**
* **[Kolyah35](https://github.com/Kolyah35)#0107**
* **[iAndy_HD3](https://github.com/iAndyHD3)#3579**
* **[Jorgame](https://github.com/ImJorGame)#8957**
* **[cdc's first account](https://github.com/CdcOnGitHub)#0451**
* **[Jammy Dodger](https://github.com/Wyliemaster)#1461**
* **[Enz](https://github.com/MikaKC)#7402**

## **Discord Server**
Join the Discord Server!<br>
https://discord.gg/PcfVcQ4gxT <br>

## **TODO list for 1.0**
- [x] LoadingLayer implementation
- [ ] PlayLayer implementation
- [ ] Player implementation
- [x] General menus
- [ ] Level Data builder and parser

## **Compiling the game**
Download Windows or Linux dependencies. Python and Shell script are placed inside `cocos2d` folder.<br>
**Windows**<br><br>
`cmake -B build -T host=x64 -A win32`<br>
`cmake --build build --config Release`<br><br>
**Linux**<br><br>
`cmake -B build`<br>
`cd build`<br>
`make`<br><br>

**Run everything from Root repo directory.**<br>

## **Troubleshooting**
**Q:** Game crashes before any image being shown<br>
**A:** It means that game failed to load textures. After building include Resources folder from 1.0 APK to build folder, where `OpenGD.exe` is located.<br><br>

## **Running the game:**
You can download the latest build in the releases tab. But you would need resources for it which are not present in the repo. For better structuring, OpenGD stores game assets in separate folders. To separate the assets from the original GD you can use `reallocate.sh`.
