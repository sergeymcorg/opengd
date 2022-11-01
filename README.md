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

## **TODO list for 1.0**
- [x] LoadingLayer implementation
- [ ] PlayLayer implementation
- [ ] Player implementation
- [x] General menues
- [ ] Level Data builder and parser
- [ ] Networking features

## **Compiling the game**
Download Windows or Linux dependencies. Python and Shell script is placed inside `cocos2d` folder.

## **Troubleshooting**
**Q:** `[build] LINK : fatal error LNK1181: unable to open file "Classes\Discord\lib\x86\Release\dgsdk.lib` <br>
**A:** Add `dgsdk.lib` from `opengd/Classes/Discord/lib/x86/dgsdk.lib` to `opengd/build (or out)/Classes/Discord/lib/x86/dgsdk.lib`<br><br>
**Q:** Game crashes before any image being shown<br>
**A:** It means that game failed to load textures. After building include Resources folder from 1.0 APK to build folder, where `OpenGD.exe` is located.<br><br>
**Q:** Game crashes after its loading<br>
**A:** Try to install Discord to your PC. **As an alternative way, disable Discord RPC support in `includes.h` and compile game again.**<br><br>
**Q:** ***OpenGD:*** `discord_game_sdk.dll` was not found<br>
**A:** Add `discord_game_sdk.dll` from `opengd/Classes/Discord/lib/x86/discord_game_sdk.dll` to build folder, where `OpenGD.exe` is located.  

## **Running the game:**
You can download the latest build in the releases tab. But you would need resources for it which are not present in the repo. For better structuring, OpenGD stores game assets in separate folders. To separate the assets from the original GD you can use `reallocate.sh`.
