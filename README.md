# APPLEHDA
AppleHDA kext for Codec Audio CX20671/2 (rarely)

Patch from stock AppleHDA.kext

1. dump codec audio information from linux, checkout google.com for more information

2. compile the codec dump(using script in my repository named "Scrip Patch Codec by HoangThanh")

3. using Grafivz to generate the audio flowchart

4. remove redundancy informations

5. Change the info.plist in AppleHDA.kext/Show Package Contents/Contents/PlugIns/AppleHDAHardwareConfigDriver.kext/AppleHDA.kext/Show Package Contents/Contents/Info.plist
5. Create the layout and platform from codec audio address (input & output)

6. Compiler layout and platform to *.zlib and import to stock AppleHDA (using HDA wizard)

7. Patch Binary for your kext using ./patch-hda.pl (address of your audio codec)

8. Import the changes to stock kext


More infomation, visit http://www.insanelymac.com/forum/

